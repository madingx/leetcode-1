// Source : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Author : Mading
// Date   : 2019-03-01

/********************************************************************************** 
* 559. Maximum Depth of N-ary Tree

* Given a n-ary tree, find its maximum depth.
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
* For example, given a 3-ary tree:
                    1
                3   2   4
               5 6
* We should return its max depth, which is 3.

* Note:
* The depth of the tree is at most 1000.
* The total number of nodes is at most 5000.
*               
**********************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)return 0;
        int m = 0;
        for(int i = 0;i<root->children.size();i++){
            int m1 = maxDepth(root->children[i]);
            m = m>m1?m:m1;
        }
        return m+1;
    }
};