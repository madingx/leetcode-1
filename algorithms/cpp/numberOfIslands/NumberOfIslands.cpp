// Source : https://leetcode.com/problems/number-of-islands/
// Author : Hao Chen
// Date   : 2015-06-08

/********************************************************************************** 
 * 200. Number of Islands [Medium]
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 * You may assume all four edges of the grid are all surrounded by water.
 * 
 * Example 1:
 *   11110
 *   11010
 *   11000
 *   00000
 * Answer: 1
 * 
 * Example 2:
 *   11000
 *   11000
 *   00100
 *   00011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/


// 12 ms, faster than 92.20% of C++, 10.7 MB, less than 94.38% of C++
class Solution {
    void  oneisland(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return;
        if(grid[i][j] != '1')return;
        grid[i][j] = '2';
        oneisland(grid,i-1,j);
        oneisland(grid,i+1,j);
        oneisland(grid,i,j-1);
        oneisland(grid,i,j+1);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++ ){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    res += 1;
                    oneisland(grid,i,j);
                }
            }
        }
        return res;
        
    }
};







void mark(vector<vector<char> >& grid, int r, int c){
    if ( r<0 || r>=grid.size() ||
            c<0 || c>=grid[0].size() ||
            grid[r][c] != '1' ) {
        return;
    }

    grid[r][c] = 'M';

    //left
    mark(grid, r, c+1);
    //right
    mark(grid, r, c-1);
    //up
    mark(grid, r-1, c);
    //down
    mark(grid, r+1, c);
}

int numIslands(vector<vector<char> >& grid) {
    int result = 0;
    for (int r=0; r<grid.size(); r++) {
        for (int c=0; c<grid[r].size(); c++) {
            if (grid[r][c] == '1') {
                result++;
                mark(grid, r, c);
            }
        }
    }
    return result;
}

// void initGrid( string g[], int len, vector<vector<char> >& grid )
// {
//     for (int i=0; i<len; i++){
//        grid.push_back(vector<char>(g[i].begin(), g[i].end())); 
//     }
// }

// int main(void)
// {
//     vector< vector<char> > grid;
//     grid.push_back( vector<char>(1, '1') );

//     cout << numIslands(grid) << endl;


//     grid.clear();

//     string g1[] = { "11110",
//                     "11010", 
//                     "11000", 
//                     "00000" };

//     initGrid(g1, 4, grid);
//     cout << numIslands(grid) << endl;



//     grid.clear();

//     string g2[] = { "11000",
//                     "11000",
//                     "00100",
//                     "00011" };

//     initGrid(g2, 4, grid);
//     cout << numIslands(grid) << endl;


//     return 0;
// }
