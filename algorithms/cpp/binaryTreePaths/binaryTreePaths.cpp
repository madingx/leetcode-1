// Source : https://leetcode.com/problems/binary-tree-paths/
// Author : Calinescu Valentin, Hao Chen
// Date   : 2015-10-23

/*************************************************************************************** 
 * 257. Binary Tree Paths [Easy]
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * 
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test 
 * cases.
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


// 8 ms, faster than 91.82% of C++, 11.6 MB, less than 91.86% of C++ 
class Solution {
public:
    vector<string> TreePaths;
    void DFS(TreeNode* node, string answer)
    {
        answer += "->" + to_string(node->val);
        if(node->left == NULL && node->right == NULL)
            TreePaths.push_back(answer);
        else
        {
            if(node->left != NULL)
                DFS(node->left, answer);
            if(node->right != NULL)
                DFS(node->right, answer);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root != NULL)
        {
            DFS(root, "");
            for(int i = 0; i < TreePaths.size(); i++)
                TreePaths[i].erase(TreePaths[i].begin(), TreePaths[i].begin() + 2);
        }
        return TreePaths;
    }
};




// Another more clear DFS implementation

// 8 ms, faster than 91.82% of C++, 12.4 MB, less than 80.81% of C++ 
class Solution {
public:
    void binaryTreePathsHelper(TreeNode* root, vector<int> solution, vector<string>& result ) {
        if (!root) return;
        
        solution.push_back(root->val);
        
        //meet the leaf node, shape a path into the result
        if (root->left==NULL && root->right==NULL){
            if(solution.size()>0){
                stringstream ss;
                for(int i=0; i<solution.size(); i++){
                    ss << solution[i] << (i<solution.size()-1 ? "->":"");
                }
                result.push_back(ss.str());
            }
            return;
        }
        
        binaryTreePathsHelper(root->left, solution, result);
        binaryTreePathsHelper(root->right, solution, result);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> solution;
        binaryTreePathsHelper(root, solution, result);
        return result;
    }
};





//Runtime: 8 ms, faster than 91.82% of C++, 11.7 MB, less than 91.86% of C++ 

class Solution {
public:
    void binaryTreeResc(TreeNode* root,vector<string> &arr,vector<string> &res) {
        if(!root)return ;
        arr.push_back( to_string(root->val));
        if(!root->left and !root->right){
            stringstream stream;
            if(arr.size()>0){
                stream<<arr[0];
                for(int i=1;i<arr.size();i++){
                    stream <<"->"<< arr[i];
                }
            }
            string str = stream.str();
            res.push_back(str);
            arr.pop_back();
            return;
        }
        binaryTreeResc(root->left,arr,res);
        binaryTreeResc(root->right,arr,res);
        arr.pop_back();
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> arr;
        vector<string> res;
        binaryTreeResc(root,arr,res);
        return res;
    }
};