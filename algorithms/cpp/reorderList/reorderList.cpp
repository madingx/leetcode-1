// Source : https://leetcode.com/problems/reorder-list/
// Author : Hao Chen, Mading
// Date   : 2014-06-17

/********************************************************************************** 
* 143. Reorder List [Medium]
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

* You may not modify the values in the list's nodes, only nodes itself may be changed.

* Example 1:
* Given 1->2->3->4, reorder it to 1->4->2->3.

* Example 2:
* Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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

// Mading   //recursion
// 48 ms, faster than 77.47% of C++, 13.4 MB, less than 11.76% of C++
class Solution {
    bool reorderListRec(ListNode* &pre,ListNode *head){
        if(!pre || !head)return false;        
        bool newend = reorderListRec(pre,head->next); //是否已产生新的结尾
        if(newend)return newend;
        if(pre == head || pre->next == head){
            head->next = NULL;
            return true;
        }     
        ListNode* t = pre->next; 
        pre->next = head;
        head->next = t;
        pre = t;  
        return false;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        reorderListRec(head,head->next);
    }
};


//Mading   //dp
// 48 ms, faster than 77.47% of C++, 13.1 MB, less than 17.65% of C++
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        vector<ListNode*> vec;
        while(head){
            vec.push_back(head);
            head = head->next;
        }
        int left = 0,right = vec.size()-1;
        while(left <= right){
            vec[left]->next = vec[right];
            left++;
            vec[right]->next = vec[left];
            right--;
        }
        vec[vec.size()/2]->next = NULL;
        return;
    }
};







// Hao Chen
// 44 ms, faster than 95.23% of C++, 12 MB, less than 100.00% of C++
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode():val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *pMid = findMidPos(head);
        pMid = reverseList(pMid);
        head = Merge(head, pMid);
    }
    
private:
    ListNode* findMidPos(ListNode *head){

        ListNode *p1, *p2, *p=NULL;
        p1 = p2 = head;
        
        while(p1!=NULL && p2!=NULL && p2->next!=NULL){
            p = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }

        if(p!=NULL){
            p->next = NULL;
        }
        
        return p1;
    }
    
    ListNode* reverseList(ListNode *head){
        ListNode* h = NULL;
        ListNode *p;
        while (head!=NULL){
            p = head;
            head = head->next;
            p->next = h;
            h = p;
        }
        return h;
    }
    
    ListNode* Merge(ListNode *h1, ListNode* h2) {
        ListNode *p1=h1, *p2=h2, *p1nxt, *p2nxt;
        while(p1!=NULL && p2!=NULL){
            p1nxt = p1->next;
            p2nxt = p2->next;
            
            p1->next = p2;
            p2->next = p1nxt;
            
            if (p1nxt==NULL){
                p2->next = p2nxt;
                break;
            }
            p1=p1nxt;
            p2=p2nxt;
        }
    }
};

void printList(ListNode *h){
    while(h!=NULL){
        printf("%d->", h->val);
        h = h->next;
    }
    printf("nil\n");
}

int main(int argc, char** argv)
{
    int size = atoi(argv[1]);
    ListNode* n = new ListNode[size] ;

    for(int i=0; i<size; i++){
        n[i].val = i;
        if( i+1 < size) {
            n[i].next = &n[i+1];
        }
    }


    Solution s;
    s.reorderList(&n[0]);
    printList(&n[0]);
    
    
    
    return 0;
}
