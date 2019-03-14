// Source : https://leetcode.com/problems/leaf-similar-trees/
// Author : Mading
// Date   : 2019-03-14

/********************************************************************************** 
 * 872. Leaf-Similar Trees
 * Consider all the leaves of a binary tree.  From left to right order, the values of
 * those leaves form a leaf value sequence.
 *                    3
 *                5       1
 *              6   2   9   8
 *                 7 4 

 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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


//8 ms  14.4 MB. faster than 99.87% of C++.
class Solution {
public:
    
    bool resc(TreeNode* root,vector<int> &arr){
        if(!root)return false;
        bool left = resc(root->left,arr);
        bool right = resc(root->right,arr);
        if(!left && ! right){
            arr.push_back(root->val);
        }
        return true;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        resc(root1,arr1);
        resc(root2,arr2);
        return arr1 == arr2;
    }
};