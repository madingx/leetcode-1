// Source : https://leetcode.com/problems/regions-cut-by-slashes/
// Author : Mading
// Date   : 2019-06-08

/********************************************************************************** 
 * 959. Regions Cut By Slashes [Medium]
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \,
 * or blank space.  These characters divide the square into contiguous regions.
 * (Note that backslash characters are escaped, so a \ is represented as "\\".)
 * Return the number of regions.


 * Example 1:
 * Input:
 * [
 *   " /",
 *   "/ "
 * ]
 * Output: 2
 * Explanation: The 2x2 grid is as follows:

 * Example 2:
 * Input:
 * [
 *   " /",
 *   "  "
 * ]
 * Output: 1
 * Explanation: The 2x2 grid is as follows:

 * Example 3:
 * Input:
 * [
 *   "\\/",
 *   "/\\"
 * ]
 * Output: 4
 * Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
 * The 2x2 grid is as follows:

 * Example 4:
 * Input:
 * [
 *   "/\\",
 *   "\\/"
 * ]
 * Output: 5
 * Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
 * The 2x2 grid is as follows:

 * Example 5:
 * Input:
 * [
 *   "//",
 *   "/ "
 * ]
 * Output: 3
 * Explanation: The 2x2 grid is as follows:

 

 * Note:
 * 1 <= grid.length == grid[0].length <= 30
 * grid[i][j] is either '/', '\', or ' '.
 *               
 **********************************************************************************/

// 16 ms, faster than 59.75% of C++, 11.2 MB, less than 40.20% of C++
class Solution {
    void dfs(vector<vector<int>> &grid2, int i , int j){
        if(i <0 || i>=grid2.size() || j <0 || j >=grid2[i].size()){
            return;
        }
        if(grid2[i][j]!=0){
            return;
        }
        grid2[i][j] = 1;
        dfs(grid2,i-1,j);
        dfs(grid2,i+1,j);
        dfs(grid2,i,j-1);
        dfs(grid2,i,j+1);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>>grid2(grid.size()*3,vector<int>(grid.size()*3,0));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j]=='/'){
                   grid2[i*3+0][j*3+2] = 1;
                   grid2[i*3+1][j*3+1] = 1;
                   grid2[i*3+2][j*3+0] = 1;
                  }else if(grid[i][j]=='\\'){
                   grid2[i*3+0][j*3+0] = 1;
                   grid2[i*3+1][j*3+1] = 1;
                   grid2[i*3+2][j*3+2] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<grid2.size();i++){
            for(int j = 0;j<grid2[i].size();j++){
                if(grid2[i][j]==0){
                    dfs(grid2,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};