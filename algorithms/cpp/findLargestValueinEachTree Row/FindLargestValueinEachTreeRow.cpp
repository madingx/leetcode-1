// Source : https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Author : Mading
// Date   : 2019-08-30

/********************************************************************************** 
* 515. Find Largest Value in Each Tree Row [Medium]
* You need to find the largest value in each row of a binary tree.

* Example:
* Input: 

*           1
*          / \
*         3   2
*        / \   \  
*       5   3   9 

* Output: [1, 3, 9]
* 
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


 // 12 ms, faster than 95.81% of C++, 21 MB, less than 100.00% of C++
class Solution {
    vector<int> rowmax;
    void treeResc(TreeNode* root,int row){
        if(!root)return;
        if(row>=rowmax.size())  rowmax.push_back(root->val);
        else  rowmax[row] = max(rowmax[row],root->val);
        treeResc(root->left,row+1);
        treeResc(root->right,row+1);
        return;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        treeResc(root,0);
        return rowmax;
    }
};