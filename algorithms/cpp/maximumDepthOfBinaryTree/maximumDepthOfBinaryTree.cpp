// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// Author : Hao Chen
// Date   : 2014-06-21
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-12

/********************************************************************************** 
* 104. Maximum Depth of Binary Tree
* 
* Given a binary tree, find its maximum depth.
* 
* The maximum depth is the number of nodes along the longest path from the root node 
* down to the farthest leaf node.
*               
**********************************************************************************/

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
    int maxDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (!root->left && !root->right){
            return 1;
        }
        int left=1, right=1;
        if (root->left){
            left += maxDepth(root->left);
        }
        if (root->right){
            right += maxDepth(root->right);
        }
        return left>right?left:right;
    }
    
};

class Solution2 {
public:
    int maxDepth(TreeNode *root) {
        if (root==NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;//find max in (left,right)
    }
};
