// Source : https://leetcode.com/problems/find-bottom-left-tree-value/
// Author : Mading
// Date   : 2019-04-27

/********************************************************************************** 
 * 513. Find Bottom Left Tree Value [Medium]
 * Given a binary tree, find the leftmost value in the last row of the tree.

 * Example 1:
 * Input:

 *     2
 *    / \
 *   1   3

 * Output:
 * 1

 * Example 2: 
 * Input:

 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   5   6
 *        /
 *       7

 * Output:
 * 7

 * Note: You may assume the tree (i.e., the given root node) is not NULL.
 *               
 **********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 20 ms, faster than 98.99% of C++ 21.2 MB, less than 72.22% of C++
class Solution {
public:
    int findBottomLeftValueLevel(TreeNode* root,int &level) {
        if(!root)return 0;
        if(!root->left && !root->right){
            level += 1;
            return root->val;
        }
        int leftlevel = level , rightlevel = level;
        int leftvalue = findBottomLeftValueLevel(root->left,leftlevel);
        int rightvalue = findBottomLeftValueLevel(root->right,rightlevel);
        level = max(leftlevel,rightlevel) + 1;
        return (leftlevel >= rightlevel)? leftvalue:rightvalue;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int level = 0;        
        return findBottomLeftValueLevel(root,level);
    }
};