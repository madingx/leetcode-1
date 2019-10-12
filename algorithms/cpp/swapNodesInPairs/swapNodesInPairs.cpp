// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 24. Swap Nodes in Pairs [Medium]

* Given a linked list, swap every two adjacent nodes and return its head.
* You may not modify the values in the list's nodes, only nodes itself may be changed. 

* Example:
* Given 1->2->3->4, you should return the list as 2->1->4->3.
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
class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    /*
     * Here we have two ways to solve this problem:
     * 1) keep the list's nodes no change. only swap the data in the list node.
     * 2) swap the list node physically.
     */
    ListNode *swapPairs(ListNode *head) {
        if(random()%2){
            return swapPairs1(head);
        }
        return swapPairs2(head);
    }
    /*just swap the node's value instead of node*/
    ListNode *swapPairs1(ListNode *head) {
        for (ListNode *p = head; p && p->next; p = p->next->next) {
            int n = p->val;
            p->val = p->next->val;
            p->next->val = n;
        }
        return head;
    }
    /*swap the list nodes physically*/ 
    ListNode *swapPairs2(ListNode *head) {
        ListNode *h = NULL;
        //using `*p` to traverse the linked list
        for (ListNode *p = head; p && p->next; p = p->next) {
            //`n` is `p`'s next node, and swap `p` and `n` physcially
            ListNode *n = p->next;
            p->next = n->next;
            n->next = p;
            //using `h` as `p`'s previous node
            if (h){
                h->next = n;
            }
            h=p;
            
            //determin the really 'head' pointer
            if (head == p){
                head = n;
            }
        }
        
        return head;
    }

    ListNode* swapPairs3(ListNode* head) {
         // Three pointers point current, previous and next node.
         ListNode *Curr=head, *Prev=NULL, *Next=NULL;

         while (Curr && Curr->next ) {
             Next = Curr->next;

             //swap nodes
             Curr->next = Next->next;
             Prev == NULL ? head = Prev = Next : Prev->next = Next;
             Next->next = Curr;

             //set the pointers to next place.
             Prev = Curr;
             Curr = Curr->next;
         }
         return head;
     }
};






// 4 ms, faster than 68.55% of C++,8.5 MB, less than 100.00% of C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode tmp(0);
        tmp.next = head;
        ListNode *pre = &tmp, *cur = head;
        while(cur && cur->next){
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return tmp.next;
    }
};


// 4 ms, faster than 68.55% of C++,8.5 MB, less than 100.00% of C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
    }
};