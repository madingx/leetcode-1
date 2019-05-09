// Source : https://leetcode.com/problems/binary-tree-cameras/
// Author : Mading
// Date   : 2019-05-09

/********************************************************************************** 
 * 968. Binary Tree Cameras [Hard]

 * Given a binary tree, we install cameras on the nodes of the tree. 
 * Each camera at a node can monitor its parent, itself, and its immediate children.
 * Calculate the minimum number of cameras needed to monitor all nodes of the tree.


 * Example 1:
 *         0
 *        / 
 *      camera
 *      / \
 *     0   0
 * Input: [0,0,null,0,0]
 * Output: 1
 * Explanation: One camera is enough to monitor all nodes if placed as shown.

 * Example 2:
 *         0
 *        / 
 *      camera
 *      / 
 *     0   
 *    /
 *  camera
 *     \
 *      0
 * Input: [0,0,null,0,null,0,null,null,0]
 * Output: 2
 * Explanation: At least two cameras are needed to monitor all nodes of the tree.
 * The above image shows one of the valid configurations of camera placement.

 * Note:
 * The number of nodes in the given tree will be in the range [1, 1000].
 * Every node has value 0.
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
// 8 ms, faster than 100.00% of C++, 18.7 MB, less than 100.00% of C++
class Solution {
public:
    int res = 0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};