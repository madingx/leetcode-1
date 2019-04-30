// Source : https://leetcode.com/problems/print-binary-tree/
// Author : Mading
// Date   : 2019-04-30

/********************************************************************************** 
 * 655. Print Binary Tree [Medium]

 * Print a binary tree in an m*n 2D string array following these rules:

 * 1.The row number m should be equal to the height of the given binary tree.
 * 2.The column number n should always be an odd number.
 * 3.The root node's value (in string format) should be put in the exactly middle
 * of the first row it can be put. The column and the row where the root node 
 * belongs will separate the rest space into two parts (left-bottom part and 
 * right-bottom part). You should print the left subtree in the left-bottom part
 * and print the right subtree in the right-bottom part. The left-bottom part and
 * the right-bottom part should have the same size. Even if one subtree is none
 * while the other is not, you don't need to print anything for the none subtree
 * but still need to leave the space as large as that for the other subtree. 
 * However, if two subtrees are none, then you don't need to leave space for both of them.
 * 4.Each unused space should contain an empty string "".
 * 5.Print the subtrees following the same rules.

 * Example 1:
 * Input:
 *      1
 *     /
 *    2
 * Output:
 * [["", "1", ""],
 *  ["2", "", ""]]
 * Example 2:
 * Input:
 *      1
 *     / \
 *    2   3
 *     \
 *      4
 * Output:
 * [["", "", "", "1", "", "", ""],
 *  ["", "2", "", "", "", "3", ""],
 *  ["", "", "4", "", "", "", ""]]

 * Example 3:
 * Input:
 *       1
 *      / \
 *     2   5
 *    / 
 *   3 
 *  / 
 * 4 
 * Output:

 * [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 *  ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 *  ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 *  ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 * Note: The height of binary tree is in the range of [1, 10].
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
// 4 ms, faster than 100.00% of C++, 10.4 MB, less than 5.88% of C++ 
class Solution {
public:
    void revet2d(TreeNode* root,vector<vector<string>> &res,int row,int col) {
        if(!root)return;
        if(row >= res.size()){
            vector<string> a(pow(2,row),"");
            res.push_back(a);
        }
        res[row][col] = to_string(root->val);       
        revet2d(root->left,res,row+1,2*col);
        revet2d(root->right,res,row+1,2*col+1);              
        return;        
    }
    /********
    row\col:
     0            0
     1        0       1
     2      0   1   2   3
     3     0 1 2 3 4 5 6 7
      
      0  1  2  3  4  5  6  7  8  9 10
     30,20,31,10,32,21,33,00,34,22,11,23,36,37...
     
     res2[i][ (pow(2,(row-j+1))-1)*j + (pow(2,(row-j))-1)  ] = res[i][j]; 
    ********/
    
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        vector<vector<string>> res2;
        int row = 0,col = 0;
        revet2d(root,res,row,col);
        
        
        row = res.size();
        col = res[row-1].size()*2-1;
        
        for(int i=0;i<res.size();i++){
            vector<string> a(col,"");
            res2.push_back(a);
            for(int j=0;j<res[i].size();j++){
                int p = pow(2,(row-i));
                int q = p*j + (p/2-1);
                res2[i][ q ] = res[i][j]; 
            }
        }
        
        return res2;
    }
};