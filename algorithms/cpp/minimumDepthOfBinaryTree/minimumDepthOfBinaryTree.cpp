// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author : Hao Chen
// Date   : 2014-06-22

/********************************************************************************** 
* 111. Minimum Depth of Binary Tree [Easy]
* Given a binary tree, find its minimum depth.
* 
* The minimum depth is the number of nodes along the shortest path from the root node 
* down to the nearest leaf node.

* Note: A leaf is a node with no children.

* Example:
* Given binary tree [3,9,20,null,null,15,7],

*     3
*    / \
*   9  20
*     /  \
*    15   7
* return its minimum depth = 2.
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

    // 16 ms, faster than 99.35% of C++, 19.4 MB, less than 95.64% of C++ 
    int minDepth(TreeNode *root) {
        if (root==NULL){
            return 0;
        }
        if (root->left==NULL && root->right==NULL){
            return 1;
        }
        int left=INT_MAX;
        if (root->left){
            left = minDepth(root->left) + 1 ;
        }
        int right=INT_MAX;
        if (root->right){
            right = minDepth(root->right) + 1;
        }
        
        return left<right ? left : right;
        
    }
};
