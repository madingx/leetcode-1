// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Hao Chen
// Date   : 2014-06-21

/********************************************************************************** 
* 19. Remove Nth Node From End of List [Medium]
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* 
*    Given linked list: 1->2->3->4->5, and n = 2.
* 
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
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
// 8 ms, faster than 26.11% of C++, 8.6 MB, less than 41.29% of C++
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head==NULL || n<=0){
            return NULL;
        }
        ListNode fakeHead(0);
        fakeHead.next=head;
        head=&fakeHead;
        
        ListNode *p1, *p2;
        p1=p2=head;
        for(int i=0; i<n; i++){
            if (p2==NULL) return NULL;
            p2=p2->next;
        }
        while (p2->next!=NULL){
            p2=p2->next;
            p1=p1->next;
        }
        
        p1->next = p1->next->next;
        return head->next;
    }
};



// 12 ms, faster than 9.01% of C++, 8.4 MB, less than 82.71% of C++
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = head,*p2 = head;
        int i = 0;
        for(;i<n+1 && p2;i++){
            p2 = p2->next;
        }
        if(i < n+1)return p1->next;
        for(;p2;i++){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
        
    }
};



// 8 ms, faster than 26.11% of C++, 8.6 MB, less than 24.72% of C++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode *h1=head;
        while(h1->next!=NULL){
            len++;
            h1=h1->next;
        }
        h1=head;
        
        for(int i=0;i<len-n-1;i++){
            h1=h1->next;
        }
        
        if(len-n-1<0) return head->next;
        
        if(len>=2){
        ListNode *q=h1->next->next;
        h1->next=q;
        }
        
        else head=NULL;

        return head;
    }
};