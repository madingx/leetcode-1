// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Hao Chen,Mading
// Date   : 2014-07-05

/********************************************************************************** 
* 25. Reverse Nodes in k-Group [Hard]

* Given a linked list, reverse the nodes of a linked list k at 
* a time and return its modified list.

* k is a positive integer and is less than or equal to the 
* length of the linked list. If the number of nodes is not 
* a multiple of k then left-out nodes in the end should remain as it is.

* Example,
* Given this linked list: 1->2->3->4->5 
* For k = 2, you should return: 2->1->4->3->5
* For k = 3, you should return: 3->2->1->4->5

* Note:
* Only constant extra memory is allowed.
* You may not alter the values in the list's nodes, only nodes itself may be changed.
* 
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
// 20 ms, faster than 70.04% of C++, 9.8 MB, less than 83.87% of C++
class Solution {
    ListNode* reverseKGroupResc(ListNode* &pre,ListNode* cur, int k,bool &flag) {
        if(!cur && k>0){flag = false;return cur;}
        if(!cur || k<=0)return cur;
        ListNode* nextgroup = reverseKGroupResc(pre,cur->next,k-1,flag);
        if(!flag)return nextgroup;
        cur->next = nextgroup;
        pre->next = cur;
        pre = pre->next;       
        return nextgroup;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode prehead = ListNode(0);
        prehead.next = head;
        ListNode *pre = &prehead;
        while(head){        
            bool flag = true;
            head = reverseKGroupResc(pre,head,k,flag);
        }
        return prehead.next;
        
    }
};




//Hao Chen
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *&head, int k);


// 20 ms, faster than 70.04% of C++, 9.8 MB, less than 77.42% of C++
ListNode *reverseKGroup(ListNode *head, int k) {

    if (k<=0) return head;
    ListNode fake(0);
    fake.next = head;
    ListNode* p = &fake;

    while(p){
        p->next = reverseList(p->next, k);
        for(int i=0; p && i<k; i++){
            p = p->next;
        }
    }

    return fake.next;
}

ListNode *reverseList(ListNode *&head, int k){
    ListNode* pEnd=head;
    while (pEnd && k>0){
        pEnd = pEnd->next;
        k--;
    }
    if (k>0) return head;

    ListNode *pHead=pEnd, *p=head;
    while(p != pEnd){
        ListNode *q = p->next;
        p->next = pHead;
        pHead = p;
        p = q;
    }
    return pHead;
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
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    ListNode* pList = createList(a, sizeof(a)/sizeof(int));

    int k =2;
    if (argc>1){
        k = atoi(argv[1]);
    }

    pList = reverseKGroup(pList, k);
    printList(pList);
    
    return 0;
}
