// Source : https://leetcode.com/problems/combination-sum/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 39. Combination Sum [Medium]
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
* in C where the candidate numbers sums to T. 
* 
* The same repeated number may be chosen from C unlimited number of times.
* 
* Note:
* 
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
* 
* Example 1:

* Input: candidates = [2,3,6,7], target = 7,
* A solution set is:
* [
*   [7],
*   [2,2,3]
* ]
* 
* Example 2:
* Input: candidates = [2,3,5], target = 8,
* A solution set is:
* [
*   [2,2,2,2],
*   [2,3,3],
*   [3,5]
* ]
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Runtime: 12 ms, faster than 97.88% of C++ online submissions for Combination Sum.
Memory Usage: 13.3 MB, less than 39.32% of C++ online submissions for Combination Sum.
class Solution {
public:
    void combinationSumResc(vector<int>& candidates, int target,int i,vector<int> &line,vector<vector<int>> &res){
        if(target == 0){
            res.push_back(vector<int>(line));
            return;
        }
        
        if(i>=candidates.size() || target<0 )return;
        
        int need = target/candidates[i];
        for(int j = 0;j<=need;j++){
            for(int k = 0;k<j;k++)line.push_back(candidates[i]);
            combinationSumResc(candidates,target-candidates[i]*j,i+1,line,res);
            for(int k = 0;k<j;k++)line.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> line;
        combinationSumResc(candidates,target,0,line,res);
        return res;
    }
};

// 16 ms, faster than 76.68% of C++, 9.6 MB, less than 82.84% of C++
class Solution {
public:
    void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector< vector<int> > &result) {
        if (target<0){
            return;
        }
        if (target==0){
            result.push_back(solution);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            //skip duplicates
            if (i>start && candidates[i] == candidates[i-1]) {
                continue;
            }
            solution.push_back(candidates[i]);
            combinationSumHelper(candidates, i, target - candidates[i], solution, result);
            solution.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector< vector<int> > result;
        if (candidates.size()<=0){
            return result;
        }
        sort(candidates.begin(), candidates.end());

        vector<int> solution;
        combinationSumHelper(candidates, 0, target, solution, result);

        return result;
    }
};

// void printMatrix(vector< vector<int> > &vv)
// {
//     for(int i=0; i<vv.size(); i++) {
//         cout << "[";
//         for(int j=0; j<vv[i].size(); j++) {
//             cout << " " << vv[i][j];
//         }
//         cout << "]" << endl;;
//     }
// }

// void printArray(vector<int> &v)
// {
//     cout << "{";
//     for(int i=0; i<v.size(); i++) {
//         cout << " " << v[i];
//     }
//     cout << "}" << endl;
// }


// int main(int argc, char** argv)
// {
//     int a[] = {4,2,3,3,5,7};
//     vector<int> v(a, a+sizeof(a)/sizeof(int));
//     int target = 7;
//     cout << "array  = ";
//     printArray(v);
//     cout << "target = " << target << endl;
    
//     vector< vector<int> > vv = combinationSum(v, target);
//     printMatrix(vv);

//     return 0;
// }
