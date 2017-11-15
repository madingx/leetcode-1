// Source : https://oj.leetcode.com/problems/permutations/
// Author : Hao Chen,Mading
// Date   : 2017-11-15
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-15

/********************************************************************************** 
* 46. Permutations
* 
* Given a collection of numbers, return all possible permutations.
* 
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

/*
{ 1 2 3 }
{ 2 1 3 }
{ 3 2 1 }
{ 1 3 2 }
{ 2 3 1 }
{ 3 1 2 }
*/

/*
 *    The algroithm - Take each element in array to the first place.
 *
 *    For example: 
 *    
 *         0) initalization 
 * 
 *             pos = 0
 *             [1, 2, 3]   
 *
 *         1) take each element into the first place, 
 *
 *             pos = 1
 *             [1, 2, 3]  ==>  [2, 1, 3] , [3, 1, 2] 
 *
 *             then we have total 3 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2] 
 *            
 *         2) take each element into the "first place" -- pos 
 *
 *             pos = 2
 *             [1, 2, 3]  ==>  [1, 3, 2]
 *             [2, 1, 3]  ==>  [2, 3, 1]
 *             [3, 1, 2]  ==>  [3, 2, 1] 
 *
 *             then we have total 6 answers
 *             [1, 2, 3],  [2, 1, 3] , [3, 1, 2], [1, 3, 2], [2, 3, 1], [3, 2, 1]
 *
 *          3) pos = 3 which greater than length of array, return.
 *
 */
vector<vector<int> > permute(vector<int> &num) {
    
    vector<vector<int> > vv;
    vv.push_back(num);

    if (num.size() <2){
        return vv;
    }
        
    int pos=0;
    while(pos<num.size()-1){
        int size = vv.size();
        for(int i=0; i<size; i++){
            //take each number to the first place
            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
                int t = v[j]; 
                v[j] = v[pos];
                v[pos] = t;
                vv.push_back(v);
            }
        }
        pos++;
    }
    return vv;
}

int main(int argc, char** argv)
{
    int n = 3;
    if (argc>1){
       n = atoi(argv[1]); 
    }

    vector<int> v;
    for (int i=0; i<n; i++) {
        v.push_back(i+1);
    }
    vector<vector<int> > vv;
    vv = permute(v);
    
    for(int i=0; i<vv.size(); i++) {
        cout << "{ ";
        for(int j=0; j<vv[i].size(); j++){
            cout << vv[i][j] << " ";
        }
        cout << "}" <<endl;
    }

    return 0;
}




/*** Solution by Mading *******************/
class Solution {
public:
    void per(vector<int>& nums,vector<vector<int>>& res,int i){
        if(i==nums.size()-1)res.push_back(nums);
        for(int j = i;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                per(nums,res,i+1);
                temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            else if(i==j){
                per(nums,res,i+1);
            }
            
        }
        
    }
        
        
    vector<vector<int>> permute(vector<int>& nums) {
        int row = nums.size();
        vector<vector<int>> res;
        
        per(nums,res,0);
        return res;
        
    }
};