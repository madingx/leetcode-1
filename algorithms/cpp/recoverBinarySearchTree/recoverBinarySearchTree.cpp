// Source : https://leetcode.com/problems/recover-binary-search-tree/
// Author : Hao Chen
// Date   : 2014-10-11

/********************************************************************************** 
* 99. Recover Binary Search Tree [Hard]
* Two elements of a binary search tree (BST) are swapped by mistake.
* Recover the tree without changing its structure.
* 
* Example 1:
* Input: [1,3,null,null,2]

*    1
*   /
*  3
*   \
*    2
* Output: [3,1,null,null,2]

*    3
*   /
*  1
*   \
*    2

* Example 2:
* Input: [3,1,4,null,null,2]

*   3
*  / \
* 1   4
*    /
*   2
* Output: [2,1,4,null,null,3]
*   2
*  / \
* 1   4
*    /
*   3

* Follow up:
* A solution using O(n) space is pretty straight forward.
* Could you devise a constant space solution? 
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

//
// We can convert the BST to a sorted array,  then we can find the two nodes which missed the order.
//
// To cover the BST to sorted array, we needn't use an extra array, we just traverse the tree in order.
//  
//                   8
//           _______/ \_______
//          /                 \
//         4                  12
//      __/ \__             __/ \__
//     /       \           /       \
//    2         6        10        14
//   / \       / \       / \       / \
//  1   3     5   7     9  11    13  15
//  
//  
// 44 ms, faster than 69.65% of C++, 17.5 MB, less than 100.00% of C++ 
class Solution {
public:
    void recoverTreeHelper(TreeNode *root) {
        if (root == NULL) return;
        
        recoverTreeHelper(root->left);
        if (prev) {
            if (prev->val > root->val){
                if (n1==NULL) {
                    n1 = prev;
                }
                n2 = root;
            }
        }
        prev = root;
        recoverTreeHelper(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        n1 = n2 = prev = NULL;
        recoverTreeHelper(root);
        if (n1 && n2) {
            swap(n1->val, n2->val);
        }
    }
private:
    TreeNode *n1, *n2, *prev;
};


// 32 ms, faster than 97.10% of C++ 17.8 MB, less than 98.44% of C++ 
class Solution {
    TreeNode *first;
    TreeNode *second;
    TreeNode *pre;
public:
    void recoverTree(TreeNode* root){
        first = NULL;
        second = NULL;
        pre = new TreeNode(INT_MIN);

        traverse(root);
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
        delete(pre);
        return;
    }
        
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        if(!first && pre->val>=root->val)  
            first = pre;
        if(first && pre->val>=root->val)  
            second = root;
        pre = root;
        
        traverse(root->right);
        return;
        
    }
};