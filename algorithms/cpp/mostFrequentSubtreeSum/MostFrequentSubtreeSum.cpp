// Source : https://leetcode.com/problems/most-frequent-subtree-sum/
// Author : Mading
// Date   : 2019-04-28

/*************************************************************************************** 
 * 508. Most Frequent Subtree Sum [Medium]
 * Given the root of a tree, you are asked to find the most frequent subtree sum.
 * The subtree sum of a node is defined as the sum of all the node values formed 
 * by the subtree rooted at that node (including the node itself). 
 * So what is the most frequent subtree sum value? If there is a tie, 
 * return all the values with the highest frequency in any order.

 * Examples 1
 * Input:

 *   5
 *  /  \
 * 2   -3
 * return [2, -3, 4], since all the values happen only once, return all of them in any order.
 * Examples 2
 * Input:

 *   5
* /  \
 * 2   -5
 * return [2], since 2 happens twice, however -5 only occur once.
 * Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
 *  
 ***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 40 ms, faster than 20.18% of C++ 23.8 MB, less than 70.00% of C++ 
class Solution {
public:
    int findFrequentTreeSumResc(TreeNode* root) {
        if(!root)return 0;
        int sum = root->val 
            + findFrequentTreeSumResc(root->left) 
            + findFrequentTreeSumResc(root->right);
        
        if( d.find(sum)!=d.end() ){//找到key值的键值对
            d[sum] += 1;
        }
        else{
            d[sum] = 1;
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findFrequentTreeSumResc(root);
        vector<int> res;
        int m = 0;
        for(unordered_map<int,int>::iterator it = d.begin();it != d.end();++it){
            if(it->second > m){
                res.clear();
                m = it->second;
                res.push_back(it->first);
            }
            else if(it->second == m){
                res.push_back(it->first);
            }
        }
        return res;
    }
private:
    unordered_map<int,int> d;
};