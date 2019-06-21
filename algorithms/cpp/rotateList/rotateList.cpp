// Source : https://oj.leetcode.com/problems/rotate-list/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 61. Rotate List [Medium]
* Given a linked list, rotate the list to the right by k places, where k is non-negative.

* Example 1:

* Input: 1->2->3->4->5->NULL, k = 2
* Output: 4->5->1->2->3->NULL
* Explanation:
* rotate 1 steps to the right: 5->1->2->3->4->NULL
* rotate 2 steps to the right: 4->5->1->2->3->NULL
* Example 2:

* Input: 0->1->2->NULL, k = 4
* Output: 2->0->1->NULL
* Explanation:
* rotate 1 steps to the right: 2->0->1->NULL
* rotate 2 steps to the right: 1->2->0->NULL
* rotate 3 steps to the right: 0->1->2->NULL
* rotate 4 steps to the right: 2->0->1->NULL
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

// 8 ms, faster than 91.38% of C++, 8.8 MB, less than 93.57% of C++ 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k<=0){
            return head;
        }
        
        //find the length of List
        int len=1;
        ListNode *p=head;
        while( p->next != NULL ){
            p = p->next;
            len++;
        }
        //connect the tail to head
        p->next = head;
        //find the left place (take care the case - k > len)
        k = len - k % len;
        
        //find the place
        for(int i=0; i<k; i++){
            p = p->next;
        }
        
        //break the list
        head = p->next;
        p->next = NULL;
        
        return head;
        
    }
};


// 8 ms, faster than 91.38% of C++, 9.1 MB, less than 35.42% of C++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)return head;
        stack<ListNode*> mystack;
        ListNode* cur = head;
        while(cur){
            mystack.push(cur);
            cur = cur->next; 
            
        }
        int s = mystack.size();
        k = k%s;
        if(k == 0)return head;
        mystack.top()->next = head;
        while( !mystack.empty() ){
            cur = mystack.top();
            mystack.pop();
            if(k>0)k--;
            if(k == 0)break;
            
        }
        head = cur;
        mystack.top()->next = NULL;
        return head;
    }
};