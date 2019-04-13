// Source : https://leetcode.com/problems/set-matrix-zeroes/
// Author : Hao Chen
// Date   : 2014-06-23

/********************************************************************************** 
* 73. Set Matrix Zeroes [Medium]
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

* Example 1:
* Input: 
* [
*   [1,1,1],
*   [1,0,1],
*   [1,1,1]
* ]
* Output: 
* [
*   [1,0,1],
*   [0,0,0],
*   [1,0,1]
* ]

* Example 2:
* Input: 
* [
*   [0,1,2,0],
*   [3,4,5,2],
*   [1,3,1,5]
* ]
* Output: 
* [
*   [0,0,0,0],
*   [0,4,5,0],
*   [0,3,1,0]
* ]

* Follow up:

* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
*               
**********************************************************************************/

class Solution {
public:
    Solution(){
        srand(time(NULL));
    }
    void setZeroes(vector<vector<int> > &matrix) {
        if(random()%2){
            setZeroes1(matrix);
        }
        setZeroes2(matrix);
    }
    
    // 48 ms, faster than 99.45% of C++, 11.5 MB, less than 62.36% of C++
    void setZeroes1(vector<vector<int> > &matrix) {
        
        int bRow = false, bCol=false;
        
        for (int r=0; r<matrix.size(); r++){
            for(int c=0; c<matrix[r].size(); c++){
                if (matrix[r][c]==0){
                    if (r==0) bRow = true;
                    if (c==0) bCol = true;
                    matrix[0][c] = matrix[r][0] = 0;
                }
            }
        }
        
        for (int r=1; r<matrix.size(); r++){
            for(int c=1; c<matrix[r].size(); c++){
                if (matrix[0][c]==0 || matrix[r][0]==0) {
                    matrix[r][c]=0;
                }
            }
        }
        if (bRow){
            for(int c=0; c<matrix[0].size(); c++) matrix[0][c] = 0;
        }
        if (bCol){
            for(int r=0; r<matrix.size(); r++) matrix[r][0] = 0;
        }

    }

    // 48 ms, faster than 99.45% of C++ , 11.4 MB, less than 82.66% of C++ 
    void setZeroes2(vector<vector<int> > &matrix) {
        bool *row = new bool[matrix.size()]();
        bool *col = new bool[matrix[0].size()]();
        for (int r=0; r<matrix.size(); r++){
            for(int c=0; c<matrix[r].size(); c++){
                if (matrix[r][c]==0){
                    row[r]=true;
                    col[c]=true;
                }
            }
        }
        
        for (int r=0; r<matrix.size(); r++){
            for(int c=0; c<matrix[r].size(); c++){
                if (row[r] || col[c]) {
                    matrix[r][c]=0;
                }
            }
        }
    }
};
