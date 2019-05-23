// Source : https://leetcode.com/problems/beautiful-arrangement/
// Author : Mading
// Date   : 2019-05-23

/********************************************************************************** 
 * 526. Beautiful Arrangement [Medium]
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement 
 * as an array that is constructed by these N numbers successfully if one of 
 * the following is true for the ith position (1 <= i <= N) in this array:

 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 
 * Now given N, how many beautiful arrangements can you construct?

 * Example 1:
 * Input: 2
 * Output: 2
 * Explanation: 

 * The first beautiful arrangement is [1, 2]:
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

 * The second beautiful arrangement is [2, 1]:
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 
 * Note:
 * N is a positive integer and will not exceed 15.
 * 
 **********************************************************************************/


// 372 ms, faster than 17.21% of C++, 8.2 MB, less than 73.54% of C++
class Solution {
public:
    int countArrangementResc(int N,int k,vector<bool> &dp) {
        if(k-1 == N)return 1;
        int res = 0;
        for(int i=0;i<dp.size();i++){
            if(dp[i])continue;
            if((i+1)%k == 0 || k%(i+1) == 0){
                dp[i] = true;
                res += countArrangementResc(N,k+1,dp);
                dp[i] = false;
            }
        }
        return res;
    }
    int countArrangement(int N) {
        if(N<4)return N;
        vector<bool> dp(N,false);
        return countArrangementResc(N,1,dp);        
    }
};



// 8 ms, faster than 97.54% of C++, 8.4 MB, less than 35.43% of C++
class Solution {
public:
    int countArrangement(int N) {
        vector<int> vs;
        for (int i=0; i<N; ++i) vs.push_back(i+1);
        return counts(N, vs);
    }
    int counts(int n, vector<int>& vs) {
        if (n <= 0) return 1;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (vs[i]%n==0 || n%vs[i]==0) {
                swap(vs[i], vs[n-1]);
                ans += counts(n-1, vs);
                swap(vs[i], vs[n-1]);
            }
        }
        return ans;
    }
};