// Source : https://leetcode.com/problems/score-after-flipping-matrix/
// Author : Mading
// Date   : 2019-08-10

/********************************************************************************** 
* 861. Score After Flipping Matrix [Medium]
* We have a two dimensional matrix A where each value is 0 or 1.

* A move consists of choosing any row or column, and toggling each value in that 
* row or column: changing all 0s to 1s, and all 1s to 0s.

* After making any number of moves, every row of this matrix is interpreted as a 
* binary number, and the score of the matrix is the sum of these numbers.

* Return the highest possible score.

* Example 1:
* Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
* Output: 39
* Explanation:
* Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
* 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

* Note:
* 1 <= A.length <= 20
* 1 <= A[0].length <= 20
* A[i][j] is 0 or 1.
*               
**********************************************************************************/




// 4 ms, faster than 67.42% of C++, 8.6 MB, less than 100.00% of C++
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i)
            if (A[i][0] == 0)
            {
                for (int j = 0; j < A[0].size(); ++j)
                    A[i][j] = 1 - A[i][j];
            }
        // So now the first bit of each row is 1
        
        int numRows = A.size();
        int numCols = A[0].size();
        int numOnesInCol = 0;
        for (int j = 1; j < numCols; ++j)
        {
            for (int i = 0; i < numRows; ++i)
                numOnesInCol += A[i][j];
            if (numOnesInCol <= numRows/2)
                for (int i = 0; i < numRows; ++i)
                    A[i][j] = 1 - A[i][j];
            numOnesInCol = 0;
        }
        // So now each column after the first has as many 1s as possible
        
        
        int answer = 0;
        int currentNumber = 0;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
                currentNumber += (A[i][j]<<(numCols - j - 1));
            answer += currentNumber;
            currentNumber = 0;
        }
        
        return answer;
    }
};