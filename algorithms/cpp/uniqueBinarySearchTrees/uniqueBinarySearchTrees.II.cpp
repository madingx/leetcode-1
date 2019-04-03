// Source : https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 95. Unique Binary Search Trees II [Medium]
* Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

* Example:

* Input: 3
* Output:
* [
*   [1,null,3,2],
*   [3,2,null,1],
*   [3,1,null,null,2],
*   [2,1,3],
*   [1,null,2,null,3]
* ]
* Explanation:
* The above output corresponds to the 5 unique BST's shown below:

*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//16 ms, faster than 100.00% of C++ ,12.4 MB, less than 98.33% of C++ 
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> tree;
        if (n == 0) {
            return tree;
        }
        vector<vector<vector<TreeNode*>>> dp(n,vector<vector<TreeNode*>>(n));
        helper(1, n , tree, dp);
        return tree;
    }
private:
    void helper(int start, int end, vector<TreeNode*> &tree,vector<vector<vector<TreeNode*>>> &dp) {
        if (start > end) {
            tree.push_back(NULL); 
            return;
        }
        if (!dp[start - 1][end - 1].empty())  {
            tree = dp[start - 1][end - 1];
            return;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left, right;
            helper(start, i - 1, left, dp);
            helper(i + 1, end, right, dp);
            for(int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    tree.push_back(node);
                }
            }
        }
        dp[start - 1][end - 1] = tree;
    }

    
};