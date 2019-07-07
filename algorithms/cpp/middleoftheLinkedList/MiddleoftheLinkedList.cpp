// Source : https://leetcode.com/problems/middle-of-the-linked-list/
// Author : Mading
// Date   : 2019-07-07

/********************************************************************************** 
* 876. Middle of the Linked List [Easy]
* Given a non-empty, singly linked list with head node head, return a middle node of linked list.

* If there are two middle nodes, return the second middle node.

* Example 1:

* Input: [1,2,3,4,5]
* Output: Node 3 from this list (Serialization: [3,4,5])
* The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
* Note that we returned a ListNode object ans, such that:
* ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

* Example 2:

* Input: [1,2,3,4,5,6]
* Output: Node 4 from this list (Serialization: [4,5,6])
* Since the list has two middle nodes with values 3 and 4, we return the second one.
 
* Note:

* The number of nodes in the given list will be between 1 and 100.
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

// 0 ms, faster than 100.00% of C++, 8.5 MB, less than 22.52% of C++ 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *p1 = head,*p2 = head;
        while(p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
        
    }
};