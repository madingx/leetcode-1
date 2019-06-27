// Source : https://leetcode.com/problems/linked-list-cycle/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 141. Linked List Cycle [Easy]
* Given a linked list, determine if it has a cycle in it.
* 
* Follow up:
* Can you solve it without using extra space?
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


/*
 * if there is a cycle in the list, then we can use two pointers travers the list.
 *
 * one pointer traverse one step each time, another one traverse two steps each time.
 *
 * so, those two pointers meet together, that means there must be a cycle inside the list.
 */

// similar
// 12 ms, faster than 86.20% of C++, 9.8 MB, less than 27.09% of C++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        if(head->next==NULL) return false;
        if(head->next->next==NULL) return false;
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
        
    }
};  


// another method
// 20 ms, faster than 25.62% of C++, 12.5 MB, less than 5.05% of C++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool> nodemap;
        while(head){
            if(nodemap.find(head) != nodemap.end())return true;
            nodemap[head] = true;
            head = head->next;
        }
        return false;
    }
};


