// Source : https://leetcode.com/problems/path-sum-ii/submissions/
// Author : Hao Chen
// Date   : 2014-07-01

/********************************************************************************** 
* 113. Path Sum II [Medium]
* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
* 
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \    / \
*         7    2  5   1
* 
* return
* 
* [
*    [5,4,11,2],
*    [5,8,4,5]
* ]
* 
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

// 32 ms, faster than 37.17% of C++, 32.9 MB, less than 36.13% of C++
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> v;
        generatePathSum(root, sum, v, result);
        return result;
    }
    
    void generatePathSum(TreeNode *root, int sum, vector<int> v, vector<vector<int> >& result) {
        if (root==NULL) {
            return;
        }
        
        if (root->left==NULL && root->right==NULL) {
            if (root->val == sum){
                v.push_back(root->val);
                result.push_back(v);
            }
            return;
        }
        
        v.push_back(root->val);
        if (root->left) {
            generatePathSum(root->left, sum - root->val, v, result);
        }
        if (root->right) {
            generatePathSum(root->right, sum - root->val, v, result);
        }
    }
};



// 16 ms, faster than 99.97% of C++, 19.8 MB, less than 91.61% of C++
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};