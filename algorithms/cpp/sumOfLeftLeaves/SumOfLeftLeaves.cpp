// Source : https://leetcode.com/problems/sum-of-left-leaves/
// Author : Hao Chen
// Date   : 2016-11-12

/*************************************************************************************** 
 * 404. Sum of Left Leaves [Easy]
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. 
 * Return 24.
 ***************************************************************************************/

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

    // 8 ms, faster than 100.00% of C++, 13.3 MB, less than 100.00% of C++
    void sumOfLeftLeaves_recursion_v1(TreeNode* root, int& result) {
        if (root == NULL ) {
            return;
        }
        
        if (root->left && root->left->left == NULL && root->left->right == NULL) {
            result += root->left->val;
        }
        sumOfLeftLeaves_recursion_v1(root->left, result);
        sumOfLeftLeaves_recursion_v1(root->right, result);
        
    }

    //Runtime: 8 ms, faster than 100.00% of C++, 13.4 MB, less than 100.00% of C++
    int sumOfLeftLeaves_recursion_v2(TreeNode* root) {
        if(!root) return 0;
        int left = 0;
        if(root->left && !root->left->left && !root->left->right)
            left =  root->left->val;
        else
            left = sumOfLeftLeaves_recursion_v2(root->left);
        int right = sumOfLeftLeaves_recursion_v2(root->right);
        return left + right;
    }    
    

    int sumOfLeftLeaves(TreeNode* root) {
        srand(time(NULL));
        if (rand()%2) {
            int result = 0;
            sumOfLeftLeaves_recursion_v1(root, result);
            return result;
        } else {
            return sumOfLeftLeaves_recursion_v2(root);
        }
        
    }
};

