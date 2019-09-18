// Source : https://leetcode.com/problems/binary-search-tree-iterator/
// Author : Hao Chen
// Date   : 2014-12-31

/********************************************************************************** 
 * 173. Binary Search Tree Iterator [Medium]
 * Implement an iterator over a binary search tree (BST). 
 * Your iterator will be initialized with the root node of a BST.

 * Calling next() will return the next smallest number in the BST.


 * Example:

 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // return 3
 * iterator.next();    // return 7
 * iterator.hasNext(); // return true
 * iterator.next();    // return 9
 * iterator.hasNext(); // return true
 * iterator.next();    // return 15
 * iterator.hasNext(); // return true
 * iterator.next();    // return 20
 * iterator.hasNext(); // return false
 

 * Note:

 * next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 * where h is the height of the tree.
 * You may assume that next() call will always be valid, that is, 
 * there will be at least a next smallest number in the BST when next() is called.
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


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */




// 56 ms, faster than 66.30% of C++, 25.5 MB, less than 10.87% of C++
class BSTIterator {
    vector<int> arr;//desc
    void makearrResc(TreeNode* root){
       if(!root)return;
       makearrResc(root->right);
       arr.push_back(root->val);
       makearrResc(root->left);
   }
public:
    BSTIterator(TreeNode* root) {
        makearrResc(root);        
    }
    
    /** @return the next smallest number */
    int next() {
        int back = arr.back();
        arr.pop_back();
        return back;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return arr.size()>0;
    }
};



// 60 ms, faster than 35.79% of C++, 24.4 MB, less than 47.83% of C++.
class BSTIterator {
    private:
        vector<int> v; 
        int pos;
    public:
        //Travse the Tree in-order and covert it to an array
        BSTIterator(TreeNode *root) {
            pos = 0;
            vector<TreeNode*> stack;
            while(stack.size()>0 || root !=NULL) {
                if (root){
                    stack.push_back(root);
                    root = root->left;
                }else{
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return pos < v.size();
        }

        /** @return the next smallest number */
        int next() {
            return v[pos++];
        }
};
