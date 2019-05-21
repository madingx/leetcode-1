// Source : https://leetcode.com/problems/combination-sum-iii/
// Author : Hao Chen
// Date   : 2015-06-11

/********************************************************************************** 
 * 216. Combination Sum III [Medium]
 * Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 * 
 * Example 1:
 * Input:  k = 3,  n = 7
 * Output: 
 * 
 * [[1,2,4]]
 * 
 * Example 2:
 * Input:  k = 3,  n = 9
 * Output: 
 * 
 * [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;


// 0 ms, faster than 100.00% of C++, 9.3 MB, less than 10.42% of C++
class Solution {
    int maxnum = 9;
public:
    void combinationSumResc(int candidate,int k, int target,int restnum,vector<int> &line,vector<vector<int>> &res){
        if(target == 0 && k==0){
            res.push_back(vector<int>(line));
            return;
        }
        if( target<0 || target>restnum || candidate>maxnum || k<=0 || k>(maxnum-candidate+1))return;
        
        combinationSumResc(candidate+1,k,target,restnum-candidate,line,res);
        line.push_back(candidate);
        combinationSumResc(candidate+1,k-1,target-candidate,restnum-candidate,line,res);
        line.pop_back();
        
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> line;
        combinationSumResc(1,k,n,45,line,res);
        return res;
    }
};

// 0 ms, faster than 100.00% of C++, 8.8 MB, less than 35.40% of C++
class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int start, int num, int target, 
                          vector<int>& solution, vector< vector<int> >& results) {
        if (target < 0|| solution.size() > num){
            return;
        }
        if (target == 0 && solution.size()==num){
            results.push_back(solution);
            return;
        }
        for (int i=start; i<candidates.size(); i++){
            solution.push_back(candidates[i]);
            combinationSumHelper(candidates, i+1, num, target-candidates[i], solution, results);
            solution.pop_back();
        }

    }

    vector< vector<int> > combinationSum3(int k, int n) {
        vector<int> v;
        for (int i=1; i<=9; i++){
            v.push_back(i);
        }

        vector< vector<int> > result;
        vector<int> solution;

        combinationSumHelper(v, 0, k, n, solution, result);    

        return result;

    }
};

// void PrintResults(int k, int n, vector< vector<int> >& results) {
//     cout << "k=" << k << ", n=" << n << "\t";
//     for (int i=0; i<results.size(); i++){
//         cout << "[";
//         for (int j=0; j<results[i].size(); j++){
//             cout << results[i][j] << (j!=results[i].size()-1 ? ",":"]") ;
//         }
//         cout << ( i!=results.size()-1 ? ", " : "" );
//     } 
//     cout << endl;
// }

// int main(int argc, char** argv) 
// {
//     int k = 3, n =9;
//     if (argc > 2){
//         k = atoi(argv[1]);
//         n = atoi(argv[2]);
//     } 

//     vector< vector<int> > results;
//     results = combinationSum3(k, n);

//     PrintResults(k,n, results);
//     return 0;
// }
