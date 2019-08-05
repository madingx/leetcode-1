// Source : https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Author : Mading
// Date   : 2019-08-05

/********************************************************************************** 
 * 530. Minimum Absolute Difference in BST [Easy]
 * Given a binary search tree with non-negative values, find the minimum absolute 
 * difference between values of any two nodes.

 * Example:

 * Input:

 *    1
 *     \
 *      3
 *     /
 *    2

 * Output:
 * 1

 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

 * Note: There are at least two nodes in this BST.
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


 // 24 ms, faster than 49.97% of C++, 21.7 MB, less than 100.00% of C++
class Solution {
    void inorderTraverse(TreeNode* root, int& val, int& min_dif) {
        if (root->left != NULL) inorderTraverse(root->left, val, min_dif);
        if (val >= 0) min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL) inorderTraverse(root->right, val, min_dif);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        auto min_dif = INT_MAX, val = -1;
        inorderTraverse(root, val, min_dif);
        return min_dif;
    }
};