// Source : https://leetcode.com/problems/copy-list-with-random-pointer/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 138. Copy List with Random Pointer [Medium]
* A linked list is given such that each node contains an additional random pointer 
* which could point to any node in the list or null.
* 
* Return a deep copy of the list.
* 
*               
**********************************************************************************/



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


/*    
 *
 *  The idea as below:
 *
 *  Consider we have a linked list as below:
 *
 *    node1->random = node2;
 *    node2->random = node1;
 *    node3->random = node1;
 *    
 *       +-------------+                         
 *       |             v                         
 *    +-------+    +-------+    +-------+        
 *    | node1 |----> node2 |----> node3 |--->NULL
 *    +-------+    +-------+    +-------+        
 *      ^  ^           |           |             
 *      |  +-----------+           |             
 *      +--------------------------+             
 *    
 *
 *  To copy the list, 
 *   
 *    1) We insert a new node for each node's next position
 *
 * 
 *       +-------------------------+                                     
 *       |                         v                                     
 *    +--+----+     +-----+    +-------+     +-----+    +-------+     +-----+     
 *    | node1 |---> | NEW |----> node2 |---> | NEW |----> node3 |---> | NEW | ---> NULL
 *    +-------+     +-----+    +---+---+     +-----+    +--+----+     +-----+ 
 *      ^  ^                       |                       |             
 *      |  +-----------------------+                       |             
 *      +--------------------------------------------------+             
 *
 *    2) Then, we can construt the new node's random pointer:
 *
 *        (node1->next) -> random  = (node1->random) -> next;
 *
 *    3) After we take out all of the "NEW" node to finish the copy.
 *    
 */

// 24 ms, faster than 99.98% of C++, 22.1 MB, less than 5.21% of C++ 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = NULL, *h=NULL, *t=NULL;
        if (head == NULL){
            return NULL;
        }
        
        //creat a new node for each node and insert its next
        p = head;
        while ( p != NULL){
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        
        //copy random pointer for each new node
        p = head;
        while (p != NULL){
            if (p->random != NULL){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        
        //break to two list
        p = head;
        h = t = head->next;
        while ( p != NULL ){
            p->next = p->next->next;
            if (t->next!=NULL){
                t->next = t->next->next;
            }
            
            p = p->next;
            t = t->next;
        }
        
        return h;
    }
};


/*
 *  Considering we have a link as below:
 *
 *
 *       +-------------+
 *       |             v
 *    +-------+    +-------+    +-------+
 *    | node1 |----> node2 |----> node3 |--->NULL
 *    +-------+    +-------+    +-------+
 *      ^  ^           |           |
 *      |  +-----------+           |
 *      +--------------------------+
 * 
 *  1) Using a map to store each node's random pointer's position
 *
 *      map[node1->random] = 1;
 *      map[node2->random] = 0;
 *      map[node3->random] = 0;
 *
 *  2) Clone the linked list (only consider the next pointer)
 *
 *      new1 --> new2 --> new3 --> NULL 
 *
 *  3) Using an array to strore the order of the cloned linked-list
 *
 *      v[0] = &new1
 *      v[1] = &new2
 *      v[2] = &new3
 * 
 *  4) Then we can clone the random pointers.
 *
 *      new->random = v [ map[node->random] ]
 *
 */ 

// 32 ms, faster than 99.23% of C++, 22.3 MB, less than 5.21% of C++
class Solution {
public:
    Node *copyRandomList(Node *head) {

        Node *p = NULL, *h=NULL, *t=NULL;
        //using a map to store the random pointer's postion.
        map<Node*, int> m;
        //construct the map
        int pos =0;
        for ( p = head; p != NULL; p = p->next, pos++){
            m[p] = pos;
        }
        
        //clone the linked list  (only consider the next pointer)
        //and using a vector to store each node's postion.
        vector<Node*> v;
        for (p = head; p != NULL; p = p->next){
            Node *node = new Node(p->val,NULL,NULL);
            v.push_back(node);
            if (h==NULL){
                h = t = node;
            }else{
                t->next = node;
                t = node;
            }
        }

        //p => source link head 
        //t => new link head
        //move the p and t synchronously, and 
        //     t->random = vector[ map[p->random] ];
        for (t=h, p = head; t!=NULL && p!= NULL; p=p->next, t=t->next){
            if (p->random!=NULL) {
                pos = m[p->random];
                t->random = v[pos];
            }
        }
        
        return h;
        
    }
};


// 36 ms, faster than 97.96% of C++, 22.5 MB, less than 5.21% of C++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* cur = head;
        Node* head2 = new Node(0,NULL,NULL);
        Node* cur2 = head2;
        unordered_map<Node*,Node*> map1;        
        while(cur){
            cur2->next = new Node(cur->val,NULL,NULL);
            cur2 = cur2->next;
            map1[cur] = cur2; 
            cur = cur->next;
        }
        cur = head;
        cur2 = head2->next;
        while(cur){
            if(cur->random){
                cur2->random = map1[cur->random];
            }
            cur = cur->next;
            cur2 = cur2->next;

        }
        return head2->next;
        
    }
};