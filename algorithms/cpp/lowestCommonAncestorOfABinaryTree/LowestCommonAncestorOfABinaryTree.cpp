// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Author : Hao Chen
// Date   : 2015-07-17

/********************************************************************************** 
 * 236. Lowest Common Ancestor of a Binary Tree [Medium]
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the 
 * tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is 
 * defined between two nodes v and w as the lowest node in T that has both v and w as 
 * descendants (where we allow a node to be a descendant of itself).”
 * 
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6      _2       0       8
 *          /  \
 *          7   4
 * 
 * Example 1:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.

 * Example 2:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant 
 * of itself according to the LCA definition.
 
 * Note:
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.              
 *               
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
// 28 ms, faster than 26.99% of C++, 21.4 MB, less than 6.27% of C++
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (root==NULL) return false;
        if (root == p) {
            path.push_back(p);
            return true;
        }
        
        path.push_back(root);
        if (findPath(root->left, p, path)) return true;
        if (findPath(root->right, p, path)) return true;
        path.pop_back();
        
        return false;
    }

    //Ordinary way, find the path and comapre the path.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> path1, path2;
        
        if (!findPath(root, p, path1)) return NULL;
        if (!findPath(root, q, path2)) return NULL;
        
        int len = path1.size() < path2.size() ? path1.size() : path2.size();
        TreeNode* result = root;
        for(int i=0; i<len; i++) {
            if (path1[i] != path2[i]) {
                return result;
            }
            result = path1[i];
        }
        return result;
    }
    
};


// Actually, we can do the recursive search in one time
// 24 ms, faster than 67.23% of C++, 16.6 MB, less than 74.89% of C++ 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //return if found or not found, return NULL if not found
        if (root==NULL || root == p || root == q) return root;
        
        //find the LCA in left tree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        //find the LCA in right tree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        //left==NULL means both `p` and `q` are not found in left tree.
        if (left==NULL) return right;
        //right==NULL means both `p` and `q` are not found in right tree.
        if (right==NULL) return left;
        // left!=NULL && right !=NULL, which means `p` & `q` are seperated in left and right tree.
        return root;
    }
};




// 20 ms, faster than 86.16% of C++, 16.8 MB, less than 42.47% of C++
class Solution {
public:
    int LCAResc(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &res){
        if(!root)return 0;
        int has = 0;
        if(root == p)has += 1;
        if(root == q)has += 2;
        if(has < 3)  has += LCAResc(root->left, p, q,res);
        if(has < 3)  has += LCAResc(root->right, p, q,res);
        if(has == 3){
            res = root;
            return 4;
        }
        return has;
        
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * res = NULL;
        LCAResc(root, p, q,res);
        return res;
    }
};