// Source : https://leetcode.com/problems/maximal-rectangle/
// Author : Hao Chen
// Date   : 2014-07-21


/*************************************************************************************** 
 * 85. Maximal Rectangle [Hard]

 * Given a 2D binary matrix filled with 0's and 1's, 
 * find the largest rectangle containing only 1's and return its area.

 * Example:

 * Input:
 * [
 *   ["1","0","1","0","0"],
 *   ["1","0","1","1","1"],
 *   ["1","1","1","1","1"],
 *   ["1","0","0","1","0"]
 * ]
 * Output: 6
 *               
 ***************************************************************************************/

// 20 ms, faster than 94.02% of C++, 10.4 MB, less than 100.00% of C++
class Solution {public:
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
            else {right[j]=n; cur_right=j;}    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
}



#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

// The problem can be convert to the problem - "Largest Rectangle in Histogram"
//   1) we can take each row to calculate each row's histogram.
//   2) using the algorithm of "Largest Rectangle in Histogram" to find the largest area histogram.
//   3) tracking the maximal area.
//
// For the 1), it's easy. 
//     heights[i][j] = 1,                     if (i==0)
//     heights[i][j] = heights[i-1][j] + 1;,  if (i>0)
//
// For the 2), please referr to "Largest Rectangle in Histogram"
// 

int largestRectangleArea(vector<int> &height) {

    if (height.size()<=0) return 0;

    height.push_back(0);
    vector<int> stack;
    int maxArea=0;

    for(int i=0; i<height.size(); ){
        if (stack.size()==0 || height[i] >= height[ stack.back() ] ){
            stack.push_back(i);
            i++;
        }else{
            int topIdx = stack.back();
            stack.pop_back();
            int area = height[topIdx] * ( stack.size()==0 ? i  : i - stack.back() - 1 );
            if (area > maxArea){
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char> > &matrix) {

    if (matrix.size()<=0 || matrix[0].size()<=0) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector< vector<int> > heights(row, vector<int>(col));

    int maxArea = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++) {
            if (matrix[i][j]=='1'){
                heights[i][j] = (i==0 ? 1 : heights[i-1][j] + 1);
            }
        }
        int area = largestRectangleArea(heights[i]);
        if (area > maxArea){
            maxArea = area;
        }
    }

    return maxArea;

}

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}

void test(int a[], int n)
{
    vector<int> v(a, a + n);
    printArray(v);
    cout << largestRectangleArea(v) << endl;
}

int main(int argc, char** argv)
{
    #define TEST(a) test(a, sizeof(a)/sizeof(int))

    int a0[] = {2,1,3,1};
    TEST(a0);
    int a1[] = {2,1,5,6,2,3};
    TEST(a1);



    cout << "------------------" << endl; 
    srand(time(0));

    int r = 3;
    int c = 3;
    if (argc>2){
        r = atoi(argv[1]);
        c = atoi(argv[2]);
    }

    vector< vector<char> > matrix;
    for(int i=0; i<r; i++){
        vector<char> v;
        cout << "[";
        for(int j=0; j<c; j++) {
            char ch = random()%2+'0';
            v.push_back(ch);
            cout << " " << ch;
        }
        matrix.push_back(v);
        cout << " ]" << endl;
    }
    cout << "------------------" << endl; 
    cout << "maxArea = " << maximalRectangle(matrix) << endl;

    return 0;
}



