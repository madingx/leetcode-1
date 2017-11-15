// Source : https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
// Author : Hao Chen, Mading
// Date   : 2017-11-15
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-15

/********************************************************************************** 
* 94. Binary Tree Inorder Traversal  //中序遍历
* 
* Given a binary tree, return the inorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 
*    1
*     \
*      2
*     /
*    3
* 
* return [1,3,2].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
* 
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
* 
* OJ's Binary Tree Serialization:
* 
* The serialization of a binary tree follows a level order traversal, where '#' signifies 
* a path terminator where no node exists below.
* 
* Here's an example:
* 
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
* 
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> v;
        
        while(stack.size()>0 || root!=NULL){
            if (root!=NULL){
                stack.push_back(root);
                root = root->left;
            }else{
                if (stack.size()>0) {
                    root = stack.back(); //father in the top
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return v;
    }



    /*** Recursive solution *******************/
    void inorder(TreeNode* root,vector<int> &res) {
        if(root == NULL)return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
