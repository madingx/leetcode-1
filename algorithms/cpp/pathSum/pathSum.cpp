// Source : https://leetcode.com/problems/path-sum/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 112. Path Sum [Easy]
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
* such that adding up all the values along the path equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
* 
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
* 
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*               
**********************************************************************************/

#include <time.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum3(root, sum, 0);
        return hasPathSum2(root, sum);
        return hasPathSum1(root, sum);    
    }

    bool hasPathSum3(TreeNode* root, int sum, int s) {
        if ( root == NULL) return false;
        s += root->val;
        if ( !root->left && !root->right)  return s == sum;
        return (hasPathSum3(root->left, sum, s) || hasPathSum3(root->right, sum, s));
    }
    
    // traversal
    // 16 ms, faster than 99.55% of C++, 19.8 MB, less than 78.79% of C++
    bool hasPathSum1(TreeNode *root, int sum) {
        if (root==NULL) return false;
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left==NULL && node->right==NULL){
                if (node->val == sum){
                    return true;
                }
            }
            if (node->left){
                node->left->val += node->val;
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += node->val;
                v.push_back(node->right);
            }
        }
        return false;
    }    

    // recursion
    // 16 ms, faster than 99.55% of C++, 19.7 MB, less than 93.69% of C++ 
    bool hasPathSum2(TreeNode* root, int sum) {
        if(!root)  return false;
        if(!root->left && !root->right)  return (root->val == sum)
        else  return hasPathSum2(root->left,sum-root->val)  ||  hasPathSum2(root->right,sum-root->val);
        return false;        
    }

};
