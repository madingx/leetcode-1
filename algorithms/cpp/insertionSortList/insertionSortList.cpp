// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : Hao Chen, Mading
// Date   : 2014-07-19

/********************************************************************************** 
* 147. Insertion Sort List [Medium]
* Sort a linked list using insertion sort.


* A graphical example of insertion sort. The partial sorted list (black) initially
* contains only the first element in the list.
* With each iteration one element (red) is removed from the input data and inserted
* in-place into the sorted list
 

* Algorithm of Insertion Sort:

* Insertion sort iterates, consuming one input element each repetition, and 
* growing a sorted output list.
* At each iteration, insertion sort removes one element from the input data, 
* finds the location it belongs within the sorted list, and inserts it there.
* It repeats until no input elements remain.

* Example 1:
* Input: 4->2->1->3
* Output: 1->2->3->4

* Example 2:
* Input: -1->5->3->4->0
* Output: -1->0->3->4->5
*               
**********************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// Mading
// 48 ms, faster than 70.62% of C++, 9.8 MB, less than 22.22% of C++.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> vec;     
        while(head){
            vec.push_back(head);            
            head = head->next;  
            vec.back()->next = NULL;
        }      
        
        ListNode prehead = ListNode(0);
        for(auto i:vec){
            ListNode* pre = &prehead;
            while(pre && pre->next && pre->next->val < i->val){
                pre = pre->next;
            }            
            ListNode* t = pre->next;
            pre->next = i;
            i->next = t;
        }         
        return prehead.next;
        
    }
};



// Hao Chen
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 52 ms, faster than 43.88% of C++, 9.5 MB, less than 100.00% of C++
ListNode *insertionSortList(ListNode *head) {
    // zero or one element in list
    if (head == NULL || head->next ==NULL){
        return head;
    }

    ListNode *pSorted = NULL;
    while ( head != NULL  ){
        /* remember the head */
        ListNode *pHead = head;
        /* trailing pointer for efficient splice */
        ListNode **ppTrail = &pSorted;
        
        /* pop head off list */
        head = head->next;
        
        /* splice head into sorted list at proper place */
        while( *ppTrail!=NULL && pHead->val > (*ppTrail)->val )  {
            ppTrail = &(*ppTrail)->next;
        }
        pHead->next = *ppTrail;
        *ppTrail = pHead;
    }

    return pSorted;
}

void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}


int main(int argc, char** argv)
{
    int n = 10;
    if (argc>1){
        n = atoi(argv[1]);
    }
    srand(time(NULL));

    int *a = new int[n];
    for(int i=0; i<n; i++){
        a[i] = random()%n + 1;
    }

    ListNode *p = createList(a, n);
    printList(p);
    printList(insertionSortList(p));

    delete[] a;
}
