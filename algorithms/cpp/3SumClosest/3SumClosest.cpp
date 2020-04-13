// Source : https://leetcode.com/problems/3sum-closest/
// Author : Hao Chen,Mading
// Date   : 2019-12-23

/********************************************************************************** 
* 16. 3Sum Closest [Medium]
* Given an array nums of n integers and an integer target, find three integers 
* in nums such that the sum is closest to target. Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.

* Example:

* Given array nums = [-1, 2, 1, -4], and target = 1.

* The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
* 
*               
**********************************************************************************/

// O(n^2) with sort
// 8 ms, faster than 81.59% of C++, 8.8 MB, less than 67.92% of C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());        
        int minus = INT_MAX;
        for(int first=0;first<nums.size()-2;first++){
            int second = first+1,third = nums.size()-1;
            while(second<third){
                int s = nums[first]+nums[second]+nums[third] - target;
                if(s == 0){
                    return s+target;
                }
                if(abs(s) < abs(minus)){
                    minus = s;
                }
                if(s<0){
                    second++;
                }
                if(s>0){
                    third--;
                }                
            }                
        }
        return minus+target;
    }
};



// O(n^3)
// 520 ms, faster than 5.18% of C++, 8.6 MB, less than 100.00% of C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> vec(4,INT_MAX);
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    int m = target-nums[i]-nums[j]-nums[k];
                    if( abs(m) < abs(vec[3])){
                        vec = vector<int>({nums[i],nums[j],nums[k],m});
                    }
                }
            }
        }
        return target-vec[3];
    }
};



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647
//solution:  http://en.wikipedia.org/wiki/3SUM
//the idea as blow:
//  1) sort the array.
//  2) take the element one by one, calculate the two numsbers in reset array.
//
//notes: be careful the duplication numsber.
//
// for example:
//    [-4,-1,-1,1,2]    target=1
// 
//    take -4, can cacluate the "two numsber problem" of the reset array [-1,-1,1,2] while target=5
//    [(-4),-1,-1,1,2]  target=5  distance=4
//           ^      ^ 
//    because the -1+2 = 1 which < 5, then move the `low` pointer(skip the duplication)
//    [(-4),-1,-1,1,2]  target=5  distance=2
//                ^ ^ 
//    take -1(skip the duplication), can cacluate the "two numsber problem" of the reset array [1,2] while target=2
//    [-4,-1,(-1),1,2]  target=2  distance=1
//                ^ ^ 


// 8 ms, faster than 81.59% of C++, 8.7 MB, less than 90.57% of C++
int threeSumClosest(vector<int> &nums, int target) {
    //sort the array
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int distance = INT_MAX;
    int result;

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && nums[i-1]==nums[i]) continue;
        int a = nums[i];
        int low = i+1;
        int high = n-1;
        //convert the 3sum to 2sum problem
        while ( low < high ) {
            int b = nums[low];
            int c = nums[high];
            int sum = a+b+c;
            if (sum - target == 0) {
                //got the final soultion
                return target;
            } else {

                //tracking the minmal distance
                if (abs(sum-target) < distance ) {
                    distance = abs(sum - target);
                    result = sum;
                }

                if (sum -target> 0) {
                    //skip the duplication
                    //while(high>0 && nums[high]==nums[high-1]) high--;  // overflow
                    while(high>low && nums[high]==nums[high-1]) high--;
                    //move the `high` pointer
                    high--;
                } else {
                    //skip the duplication
                    //while(low<n && nums[low]==nums[low+1]) low++;     // overflow
                    while(low<high && nums[low]==nums[low+1]) low++;
                    //move the `low` pointer
                    low++;
                }
            }
        }
    }

    return result;
}




int main()
{
    int a[] = {-1, 2, 1, -4};
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    int target = 1;
    cout << threeSumClosest(n, target) << endl;
    return 0;
}
