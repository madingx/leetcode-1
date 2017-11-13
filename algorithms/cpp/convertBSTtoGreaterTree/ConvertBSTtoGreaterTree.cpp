// Source : https://leetcode.com/problems/convert-bst-to-greater-tree/description/
// Author : Mading
// Date   : 2017-11-13

/*************************************************************************************** 
 * 538. Convert BST to Greater Tree
 * 
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that 
 * every key of the original BST is changed to the original key plus sum of all keys 
 * greater than the original key in BST.
 *
 * Example:
 * Input: The root of a Binary Search Tree like this:
 *               5
 *             /   \
 *            2     13
 * Output: The root of a Greater Tree like this:
 *              18
 *             /   \
 *           20     13
 *                
 ***************************************************************************************/

//http://blog.csdn.net/qazwyc/article/details/63685401

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void convert(TreeNode* root, int& sum){
        if(root == NULL)    return;
        convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        convert(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }
};