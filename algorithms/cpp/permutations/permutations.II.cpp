// Source : https://leetcode.com/problems/permutations-ii/
// Author : Hao Chen
// Date   : 2014-06-21

/********************************************************************************** 
* 47. Permutations II [Medium]
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
* 
* For example,
* [1,1,2] have the following unique permutations:
* [1,1,2], [1,2,1], and [2,1,1].
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// To deal with the duplication number, we need do those modifications:
//    1) sort the array [pos..n].
//    2) skip the same number.
// 24 ms, faster than 92.01% of C++, 10.4 MB, less than 53.97% of C++
vector<vector<int> > permute(vector<int> &num) {

    vector<vector<int> > vv;
    vv.push_back(nums);

    if (nums.size() <2){
        return vv;
    }
        
    int pos=0;
    while(pos<nums.size()-1){
        int size = vv.size();
        for(int i=0; i<size; i++){
            //sort the array, so that the same number will be together
            sort(vv[i].begin()+pos, vv[i].end());
            //take each number to the first
            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
                //skip the same number 
                if (j>0 && v[j]==v[j-1]){
                    continue;
                }
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

// recursion
// 24 ms, faster than 92.01% of C++, 10.6 MB, less than 37.68% of C++
class Solution {
public:
    void permuteUniqueResc(vector<int>& nums , vector<vector<int>> &res,int k) {
        if(k == nums.size() -1 ){
            res.push_back(vector<int>(nums));
            return;
        }
        set<int> sets;
        for(int i=k;i<nums.size();i++){
            if( !sets.insert(nums[i]).second )continue;
            int temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
            
            permuteUniqueResc(nums,res,k+1);
            
            temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;   
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUniqueResc(nums,res,0);
        return res;
    }
};










void printVector( vector<int>&  pt)
{
    cout << "{ ";
    for(int j=0; j<pt.size(); j++){
        cout << pt[j] << " ";
    }
    cout << "} " << endl;
}


int main(int argc, char** argv)
{
    int n = 3;
    if (argc>1){
       n = atoi(argv[1]); 
    }

    srand(time(NULL));
    vector<int> v;
    for (int i=0; i<n; i++) {
        v.push_back(random()%n+1);
    }
    /*v[0] =0;
    v[1] =1;
    v[2] =0;
    v[3] =0;
    v[4] =9;*/

    printVector(v); 
    cout << "-----------------" << endl;


    vector<vector<int> > vv;
    vv = permute(v);
    
    for(int i=0; i<vv.size(); i++) {
        printVector(vv[i]);
    }

    return 0;
}
