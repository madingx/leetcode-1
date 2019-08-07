// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author : Hao Chen
// Date   : 2014-06-23

/********************************************************************************** 
* 108. Convert Sorted Array to Binary Search Tree [Easy]
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

* For this problem, a height-balanced binary tree is defined as a binary tree in which the depth 
* of the two subtrees of every node never differ by more than 1.

* Example:

* Given the sorted array: [-10,-3,0,5,9],

* One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

*       0
*      / \
*    -3   9
*    /   /
*  -10  5
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



// 28 ms, faster than 18.68% of C++, 24.5 MB, less than 32.26% of C++
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size()==0){
            return NULL;
        }
        if(num.size()==1){
            return new TreeNode(num[0]);
        }
        int mid = num.size()/2;
        
        TreeNode *node = new TreeNode(num[mid]);
        
        vector<int>::const_iterator first;
        vector<int>::const_iterator last;

        first = num.begin();
        last = num.begin()+mid;
        vector<int> v(first, last);
        node->left = sortedArrayToBST(v);
        
        if (mid==num.size()-1){
            node->right = NULL;
        }else{
            first = num.begin()+mid+1;
            last = num.end();
            vector<int> v(first, last);
            node->right = sortedArrayToBST(v);
        }
        return node;
    }
};



// 20 ms, faster than 61.68% of C++, 21 MB, less than 98.92% of C++
class Solution {
    TreeNode* createBST(vector<int>& nums,int left,int right) {
        if(left>right)return NULL;
        int n = right - left + 1;
        TreeNode* root = new TreeNode(nums[n/2+left]);
        root->left = createBST(nums,left,left+n/2-1);
        root->right = createBST(nums,left+n/2+1,right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums,0,nums.size()-1);
    }
};