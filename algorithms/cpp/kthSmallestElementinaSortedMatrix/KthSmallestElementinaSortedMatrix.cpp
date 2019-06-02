// Source : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Author : Mading
// Date   : 2019-06-02

/*************************************************************************************** 
 * 378. Kth Smallest Element in a Sorted Matrix [Medium]
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order,
 * find the kth smallest element in the matrix.

 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 * Example:

 * matrix = [
 *    [ 1,  5,  9],
 *    [10, 11, 13],
 *    [12, 13, 15]
 * ],
 * k = 8,

 * return 13.
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 *               
 ***************************************************************************************/


// 60 ms, faster than 46.83% of C++, 14.1 MB, less than 7.83% of C++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> priqueue;
        for( auto row:matrix){
            for( auto cell:row){
                priqueue.emplace(cell);
            }
        }
        int res = 0;
        while(k>0){
            res = priqueue.top();
            priqueue.pop();
            k--;
        }
        return res;
    }
};


// 40 ms, faster than 94.15% of C++, 12.2 MB, less than 43.77% of C++ 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int mid = 0;
        
        while(left < right){
            mid = left + (right - left)/2;
            int num = 0;
            for(int i = 0; i < n; i++){
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if(num < k)  left = mid+1;
            else   right = mid;
        }
        return left;
    }
};