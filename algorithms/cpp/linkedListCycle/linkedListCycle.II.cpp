// Source : https://oj.leetcode.com/problems/linked-list-cycle-ii/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 142. Linked List Cycle II [Medium]
* Given a linked list, return the node where the cycle begins. 
* If there is no cycle, return null.

* To represent a cycle in the given linked list, we use an integer pos which 
* represents the * position (0-indexed) in the linked list where tail connects to. 
* If pos is -1, then there is no cycle in the linked list.

* Note: Do not modify the linked list.



* Example 1:
        3 -> 2 -> 0 -> -4 -> 2

* Input: head = [3,2,0,-4], pos = 1
* Output: tail connects to node index 1
* Explanation: There is a cycle in the linked list, where tail connects to the second node.


* Example 2:
        1 -> 2 -> 1

* Input: head = [1,2], pos = 0
* Output: tail connects to node index 0
* Explanation: There is a cycle in the linked list, where tail connects to the first node.


* Example 3:
        1

* Input: head = [1], pos = -1
* Output: no cycle
* Explanation: There is no cycle in the linked list.


 

* Follow-up:
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

// 12 ms, faster than 87.05% of C++, 9.8 MB, less than 62.76% of C++
class Solution {
    
private:
    ListNode *p1, *p2;
public:
    bool hasCycle(ListNode *head) {
        
        if (head==NULL) return false;
        p1=head;
        p2=head;
        
        while (p1!=NULL && p2!=NULL){
            
            p1=p1->next;
            
            if (p2->next == NULL) return false;
            
            p2=p2->next->next;
            
            if (p1==p2) return true;
        }
        
        return false;
        
    }  
    
    /* 
     * So, the idea is:
     *   1) Using the cycle-chcking algorithm.
     *   2) Once p1 and p1 meet, then reset p1 to head, and move p1 & p2 synchronously
     *      until p1 and p2 meet again, that place is the cycle's start-point 
     */
    ListNode *detectCycle(ListNode *head) {
        
        if (hasCycle(head)==false){
            return NULL;
        }
        
        p1 = head;
        
        while (p1!=p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};





// 20 ms, faster than 29.26% of C++, 12.5 MB, less than 5.10% of C++ 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> mymap;
        while(head){
            if(mymap.find(head) != mymap.end()){
                return head;
            }
            else{
                mymap[head] = true;
            }
            head = head->next;
        }
        return head;
    }
};