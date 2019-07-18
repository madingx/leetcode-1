// Source : https://leetcode.com/problems/reshape-the-matrix/
// Author : Mading
// Date   : 2019-07-18

/********************************************************************************** 
* 566. Reshape the Matrix [Easy]
* In MATLAB, there is a very useful function called 'reshape', which can reshape 
* a matrix into a new one with different size but keep its original data.

* You're given a matrix represented by a two-dimensional array, and two positive 
* integers r and c representing the row number and column number of the wanted 
* reshaped matrix, respectively.

* The reshaped matrix need to be filled with all the elements of the original 
* matrix in the same row-traversing order as they were.

* If the 'reshape' operation with given parameters is possible and legal, output 
* the new reshaped matrix; Otherwise, output the original matrix.

* Example 1:
* Input: 
* nums = 
*    [[1,2],
*     [3,4]]
* r = 1, c = 4
* Output: 
*    [[1,2,3,4]]
* Explanation:
* The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix,
* fill it row by row by using the previous list.

* Example 2:
* Input: 
* nums = 
*    [[1,2],
*     [3,4]]
* r = 2, c = 4
* Output: 
*    [[1,2],
*     [3,4]]
* Explanation:
* There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.

* Note:
* The height and width of the given matrix is in range [1, 100].
* The given r and c are all positive.
* 
*               
**********************************************************************************/

// 36 ms, faster than 69.17% of C++, 12.1 MB, less than 33.45% of C++ 
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()*nums[0].size() != r*c )return nums;
        vector<vector<int>> res;
        int m=0,n=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(n == c){
                    m++;
                    n=0;
                }
                if(n == 0){
                    res.push_back(vector<int>(c,0));
                }
                res[m][n] = nums[i][j];
                n++;           
            }
        }
        return res;
    }
};










// 32 ms, faster than 94.28% of C++, 11.8 MB, less than 54.14% of C++

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
// https://leetcode.com/problems/reshape-the-matrix/discuss/329512/C%2B%2B-Live-coding-faster-than-100.00-resize-vector-no-push_back

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        if (r <= 0 || c <= 0 || nums.size() == 0) return nums;
        int maxrow = nums.size() - 1;
        int maxcol = nums[0].size() - 1;
        if (r * c != (maxrow + 1) * (maxcol + 1)) return nums;
        vector<vector<int>> matrix(r);
        for (auto &v : matrix)
            v.resize(c);
        int row = 0;
        int col = 0;
        for (int i = 0; i <= r && row <= maxrow; ++i) {
            for (int j = 0; j < c && row <= maxrow; ++j) {
                matrix[i][j] = nums[row][col];
                ++col;
                if (col > maxcol) {
                    col = 0;
                    ++row;
                }
            }
        }
        if (row == maxrow + 1 && col == 0)
            return matrix;
        return nums;
    }
};