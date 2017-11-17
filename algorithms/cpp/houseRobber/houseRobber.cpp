// Source : https://leetcode.com/problems/house-robber/
// Author : Hao Chen
// Date   : 2015-04-07
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-17

/********************************************************************************** 
 * 198. House Robber
 * 
 * You are a professional robber planning to rob houses along a street. Each house has 
 * a certain amount of money stashed, the only constraint stopping you from robbing 
 * each of them is that adjacent houses have security system connected and it will 
 * automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, 
 * determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 *               
 **********************************************************************************/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;    
/*
 * Dynamic Programming
 *
 * We can easy find the recurive fomular:
 *
 *     dp[n] = max( 
 *                    dp[n-1],   // the previous house has been robbed. 
 *                    dp[n-2] + nums[n]  // the previous house has NOT been robbed.
 *                )
 *                  
 * The initalization is obvious:
 *     dp[1] = nums[1]
 *     dp[2] = max(nums[1], nums[2])
 *
 */
int rob1(vector<int> &nums) {

    int n = nums.size();
    if (n==0) return 0;

    vector<int> dp(n, 0);
    if (n>=1) dp[0] = nums[0];
    if (n>=2) dp[1] = max(nums[0], nums[1]);

    for (int i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}
/*
 * Acutally, we no need to allocate an additional array for DP.
 * we can only use several variables to record previous steps
 */

int rob2(vector<int> &nums) {
    int n2=0; // dp[i-2];   max money at i-2
    int n1=0; // dp[i-1];   max money at i-1

    for (int i=0; i<nums.size(); i++){
        int current = max(n1, n2 + nums[i]);
        n2 = n1;
        n1 = current;
    }
    return n1;
}

int rob(vector<int> &num) {
    if (rand()%2)
        return rob1(num);
    return rob2(num);
}

void printVector( vector<int> &v ){
    cout << '[' ;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << (i==v.size()-1 ? " " :", ");
    }
    cout << ']' << endl;
}

int main(int argc, char** argv) {
    srand(time(0));
    vector<int> nums;
    if (argc>1){
        for (int i=1; i<argc; i++) {
            nums.push_back(atoi(argv[i]));
        }
    }else{
        nums.push_back(2);
        nums.push_back(1);
        nums.push_back(3);
        nums.push_back(4);
    }

    printVector(nums);
    cout << rob(nums) << endl;
}
