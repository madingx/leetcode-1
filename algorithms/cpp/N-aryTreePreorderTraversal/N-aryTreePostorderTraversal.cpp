// Source : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Author : Mading
// Date   : 2019-05-05

/*************************************************************************************** 
 * 590. N-ary Tree Postorder Traversal [Easy]
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * For example, given a 3-ary tree:
 *                 1
 *             /   |   \
 *            3    2    4
 *           /\
 *          5  6
 * Return its postorder traversal as: [5,6,3,2,4,1].

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
// 156 ms, faster than 98.74% of C++, 32.6 MB, less than 96.80% of C++
class Solution {
public:
    void postorderResc(Node* root,vector<int> &posttra) {
        if(!root)return;
        for(auto i:root->children){
            postorderResc(i,posttra);
        }
        posttra.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int> posttra;
        postorderResc(root,posttra);
        return posttra;
    }
};

// 160 ms, faster than 80.09% of C++, 33.2 MB, less than 60.80% of C++
class Solution {
public:
     vector<int> postorder(Node* root) {
        if (!root) {
            return {};
        }
        std::stack<std::pair<Node *, int>> s;
        std::vector<int> res;
        s.emplace(root, 0);
        while (!s.empty()) {
            auto &[node, index] = s.top();
            if (index == node->children.size()) {
                res.push_back(node->val);
                s.pop();
            } else {
                s.emplace(node->children[index++], 0);
            }
        }
        return res;
    }
};