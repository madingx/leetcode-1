// Source : https://leetcode.com/problems/delete-node-in-a-bst/
// Author : Mading
// Date   : 2019-04-26

/********************************************************************************** 
* 450. Delete Node in a BST [Medium]
* Given a root node reference of a BST and a key, delete the node with the given key
* in the BST. Return the root node reference (possibly updated) of the BST.

* Basically, the deletion can be divided into two stages:

* Search for a node to remove.
* If the node is found, delete the node.
* Note: Time complexity should be O(height of tree).

* Example:
* root = [5,3,6,2,4,null,7]
* key = 3

*     5
*    / \
*   3   6
*  / \   \
* 2   4   7

* Given key to delete is 3. So we find the node with value 3 and delete it.

* One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
*     5
*    / \
*   4   6
*  /     \
* 2       7
* Another valid answer is [5,2,6,null,4,null,7].

*     5
*    / \
*   2   6
*    \   \
*     4   7
 * 
 **********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 32 ms, faster than 99.38% of C++, 12.8 MB, less than 100.00% of C++
class Solution {
public:
    
    void reconstructNode(TreeNode* root,TreeNode* newnode) {
        if(!root || !newnode)return;
        while(root){
            if(root->val > newnode->val){
                if(!root->left){
                    root->left = newnode;
                    break;
                }
                else root = root->left; 
            }
            else{
                if(!root->right){
                    root->right = newnode;
                    break;
                }                    
                else root = root->right;
            }
        }
        return;           
       
    }
    int findNode(TreeNode* root, int key,TreeNode* &father) {
        if(!root)return 0;
        if(root->val == key){
            return 2;
        }
        else if(root->val > key){
            int l = findNode(root->left,key,father);
            if(l == 2){
                father = root;
                return 1;
            }
            else if(l == 1)return 1;
        }
        else if(root->val < key){
            int r = findNode(root->right,key,father);
            if(r == 2){
                father = root;
                return 1;
            }
            else if(r == 1)return 1;
        }
        return 0;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        TreeNode *father;
        TreeNode *superroot = new TreeNode(INT_MAX);
        superroot->left = root;
        
        int i = findNode(superroot,key,father);
        if(i!=1)return root;
        //cout<<root->val<<(father->val > key)<<endl;
        TreeNode *tmp;
        if(father->val > key){
            tmp = father->left;
            father->left = tmp->left;
        }
        else{
            tmp = father->right;
            father->right = tmp->left;
        }
        reconstructNode(father,tmp->right);
        
        
        return superroot->left;
        
    }
};



// Very Concise C++ Solution for General Binary Tree not only BST
// 36 ms, faster than 70.49% of C++, 13.1 MB, less than 93.84% of C++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else {
                TreeNode* right = root->right;
                while (right->left)
                    right = right->left;
                swap(root->val, right->val);    
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};