// Source : https://leetcode.com/problems/random-pick-with-weight/
// Author : Mading
// Date   : 2019-08-09

/*************************************************************************************** 
 * 528. Random Pick with Weight [Medium]
 * Given an array w of positive integers, where w[i] describes the weight of index i, 
 * write a function pickIndex which randomly picks an index in proportion to its weight.

 * Note:
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 
 * Example 1:
 * Input: 
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]

 * Example 2:
 * Input: 
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 * Explanation of Input Syntax:

 * The input is two lists: the subroutines called and their arguments. 
 * Solution's constructor has one argument, the array w. pickIndex has no arguments. 
 * Arguments are always wrapped with a list, even if there aren't any.
 ***************************************************************************************/




// 144 ms, faster than 67.63% of C++, 32.5 MB, less than 100.00% of C++
class Solution {
    vector<int> v;
public:
    Solution(vector<int>& w) {
        for(int i = 1; i < w.size(); i++) w[i] += w[i - 1];
        v = w;
    }
    int pickIndex() {
        return upper_bound(begin(v), end(v), rand() % v.back()) - begin(v);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */