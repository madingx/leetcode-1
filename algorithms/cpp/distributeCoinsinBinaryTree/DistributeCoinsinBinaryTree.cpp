// Source : https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Author : Mading
// Date   : 2019-05-07

/********************************************************************************** 
* 979. Distribute Coins in Binary Tree [Medium]
* Given the root of a binary tree with N nodes, each node in the tree has node.
* val coins, and there are N coins total.

* In one move, we may choose two adjacent nodes and move one coin from one node to another. 
* (The move may be from parent to child, or from child to parent.)

* Return the number of moves required to make every node have exactly one coin.
*
* Example 1:
*      3
*     / \
*    0   0
* Input: [3,0,0]
* Output: 2
* Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
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
// 8 ms, faster than 100.00% of C++, 13.3 MB, less than 100.00% of C++
class Solution {
public:
    int distributeCoinsCount(TreeNode* root,int &cnt,int &sum) {
        if(!root)return 0;
        if(!root->left && !root->right){
            cnt = root->val;
            sum = 1;
            return abs(cnt-sum);
        }
        int cleft=0,cright=0,sleft=0,sright=0;
        int left = 0;
        if(root->left){
            left = distributeCoinsCount(root->left,cleft,sleft);
        }
        int right = 0;
        if(root->right){
            right = distributeCoinsCount(root->right,cright,sright);
        }
        cnt = cleft+cright+root->val;    //3+0+0
        sum = sleft+sright+1;            //1+1+1
        return left+right+abs(sum-cnt);
    }
    int distributeCoins(TreeNode* root) {
        int cnt=0,sum=0;
        return distributeCoinsCount(root,cnt,sum);        
    }
};