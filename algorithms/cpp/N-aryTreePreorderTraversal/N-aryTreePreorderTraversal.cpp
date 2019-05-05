// Source : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Author : Mading
// Date   : 2019-05-05

/*************************************************************************************** 
 * 589. N-ary Tree Preorder Traversal [Easy]
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * For example, given a 3-ary tree:
 *                 1
 *             /   |   \
 *            3    2    4
 *           /\
 *          5  6
 * Return its preorder traversal as: [1,3,5,6,2,4].

 * Note:
 * Recursive solution is trivial, could you do it iteratively?
 *  
 ***************************************************************************************/
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
// 156 ms, faster than 98.23% of C++, 32.4 MB, less than 100.00% of C++ 
class Solution {
public:
    void preorderResc(Node* root,vector<int> &pretra) {
        if(!root)return;
        pretra.push_back(root->val);
        for(auto i:root->children){
            preorderResc(i,pretra);
        }
        return;
    }
    vector<int> preorder(Node* root) {
        vector<int> pretra;
        preorderResc(root,pretra);
        return pretra;
    }
};