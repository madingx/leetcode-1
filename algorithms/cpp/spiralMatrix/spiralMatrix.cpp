// Source : https://leetcode.com/problems/spiral-matrix/
// Author : Hao Chen
// Date   : 2014-06-30

/********************************************************************************** 
* 54. Spiral Matrix [Medium]
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* Example 1:
* Input:
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* Output: [1,2,3,6,9,8,7,4,5]

* Example 2:
* Input:
* [
*   [1, 2, 3, 4],
*   [5, 6, 7, 8],
*   [9,10,11,12]
* ]
* Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;



//根据边界计算坐标
//4 ms  8.6 MB, faster than 100.00% of C++
vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector <int> v;
    int row = matrix.size();
    if (row<=0) return v;
    int col = matrix[0].size();
    if (col<=0) return v;
    int r, c;
    for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++){
        //top
        for(int i=c; i<col-c; i++){
            v.push_back(matrix[r][i]);
        }
        //right
        for(int i=r+1; i<row-r; i++){
            v.push_back(matrix[i][col-c-1]);
        }
        //bottom
        for(int i=col-c-2; row-r-1>r && i>=c; i--){
            v.push_back(matrix[row-r-1][i]);
        }
        //left
        for(int i=row-r-2; col-c-1>c && i>r; i--){
            v.push_back(matrix[i][c]);
        }
    }
    return v;
}

//每一个圈是一次循环
//4 ms    8.6 MB, faster than 100.00% of C++
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int row = matrix.size();
        if (row<=0) return ans;
        int col = matrix[0].size();
        if (col<=0) return ans;
        int r, c;
        int r1 = 0, 
            r2 = row - 1;     //行数
        int c1 = 0, 
            c2 = col - 1;  //列数
        
        while (r1 <= r2 && c1 <= c2) {
            for (int c = c1; c <= c2; c++) {
                ans.push_back(matrix[r1][c]);//将上面的行，向右，加入
            }
            for (int r = r1 + 1; r <= r2; r++) {
                ans.push_back(matrix[r][c2]);//将右边的列，向下，加入
            }
            
            if (r1 < r2 && c1 < c2) {
                for (int c = c2 - 1; c > c1; c--) ans.push_back(matrix[r2][c]);//将下面的行，向左顺序，加入
                for (int r = r2; r > r1; r--) ans.push_back(matrix[r][c1]);//将左边的列，向行顺序，加入
            }
            //进入下一层圈
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }

void printArray(vector<int> v)
{
    cout << "[";
    for(int j=0; j<v.size(); j++) {
        printf(" %02d", v[j]);
    }
    cout << "]" << endl;;
}

void printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        printArray(vv[i]);
    }
    cout << endl;
}

vector< vector<int> > createMatrix(int n, int m)
{
    vector< vector<int> > vv;
    int cnt = 1;
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<m; j++){
            v.push_back(cnt++);
        }
        vv.push_back(v);
    }
    return vv;
}

int main(int argc, char** argv)
{
    int n=3, m=3;
    if (argc>2){
        n = atoi(argv[1]);
        m = atoi(argv[2]);
    }
    vector< vector<int> > matrix = createMatrix(n, m);
    printMatrix(matrix);
    vector<int> v = spiralOrder(matrix);
    printArray(v);
    return 0;
}
