// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author : Hao Chen
// Date   : 2014-06-21

/********************************************************************************** 
* 129. Sum Root to Leaf Numbers [Medium]
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
* 
* Find the total sum of all root-to-leaf numbers.
* Note: A leaf is a node with no children.

* For example,
*     1
*    / \
*   2   3
* The root-to-leaf path 1->2 represents the number 12.
* The root-to-leaf path 1->3 represents the number 13.
* Return the sum = 12 + 13 = 25.
* 
* Example 2:
* Input: [4,9,0,5,1]
*     4
*    / \
*   9   0
*  / \
* 5   1
* Output: 1026
* Explanation:
* The root-to-leaf path 4->9->5 represents the number 495.
* The root-to-leaf path 4->9->1 represents the number 491.
* The root-to-leaf path 4->0 represents the number 40.
* Therefore, sum = 495 + 491 + 40 = 1026.
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
// 8 ms, faster than 81.09% of C++, 12.4 MB, less than 48.41% of C++
class Solution {
public:
    int sumNumbers(TreeNode *root) {
    
        if (!root) return 0;
        
        int sum = 0;       
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left){
                node->left->val += (10*node->val); 
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += (10*node->val); 
                v.push_back(node->right);
            }
            if(!node->right && !node->left){
                sum += node->val;
            }
        }
        
        return sum;
    }
};


// 4 ms, faster than 100.00% of C++, 12.3 MB, less than 78.98% of C++
class Solution {
public:
    int sumNumbers(TreeNode* root,int fa) {
        if(!root)return 0;
        int t = fa*10 + root->val;
        int l = sumNumbers(root->left,t);
        int r = sumNumbers(root->right,t);
        if(l>0 || r>0)t=0;
        return l+r+t;
    }
    
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root,0);
    }
};