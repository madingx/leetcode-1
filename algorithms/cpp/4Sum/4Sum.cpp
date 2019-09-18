// Source : https://leetcode.com/problems/4sum/
// Author : Hao Chen
// Date   : 2014-07-03

/********************************************************************************** 
* 18. 4Sum [Medium]
* Given an array nums of n integers and an integer target, are there elements a, b, c, 
* and d in nums such that a + b + c + d = target? Find all unique quadruplets 
* in the array which gives the sum of target.

* Note:

* The solution set must not contain duplicate quadruplets.

* Example:

* Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

* A solution set is:
* [
*   [-1,  0, 0, 1],
*   [-2, -1, 1, 2],
*   [-2,  0, 0, 2]
* ]
* 
*               
**********************************************************************************/

// 12 ms, faster than 89.68% of C++， 8.9 MB, less than 100.00% of C++ 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
    }
};




// 40 ms, faster than 54.63% of C++， 9.1 MB, less than 100.00% of C++
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    
        vector<vector<int> > res;
    
        if (num.empty())
            return res;
    
        std::sort(num.begin(),num.end());
    
        for (int i = 0; i < num.size(); i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < num.size(); j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = num.size() - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    
    }
};









#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> num, int target); 

/*
 * 1) Sort the array,
 * 2) traverse the array, and solve the problem by using "3Sum" soultion.
 */

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector< vector<int> > result;
    if (num.size()<4) return result;
    sort( num.begin(), num.end() );
    
    for(int i=0; i<num.size()-3; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        vector<int> n(num.begin()+i+1, num.end());
        vector<vector<int> > ret = threeSum(n, target-num[i]);
        for(int j=0; j<ret.size(); j++){
            ret[j].insert(ret[j].begin(), num[i]);
            result.push_back(ret[j]);
        }
    }

    return result; 
}

vector<vector<int> > threeSum(vector<int> num, int target) {

    vector< vector<int> > result;
    //sort the array (if the qrray is sorted already, it won't waste any time)
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            if (a+b+c == target) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                while(high>0 && num[high]==num[high-1]) high--;
                low++;
                high--;
            } else if (a+b+c > target) {
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                low++;
            }
        }
    }
    return result;
}


int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}


int main()
{
    int a[] = {1,0,-1,0,-2,2};
    vector<int> n(a, a+6);
    int t = 0;
    vector< vector<int> > v = fourSum(n, t);
    printMatrix(v);

    n.clear();
    int b[] = {-1,-5,-5,-3,2,5,0,4};
    n.insert(n.begin(), b, b+8);
    t = -7;
    v = fourSum(n, t);
    printMatrix(v);

    return 0;
}
