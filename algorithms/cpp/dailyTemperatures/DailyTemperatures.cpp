// Source : https://leetcode.com/problems/daily-temperatures/
// Author : Mading
// Date   : 2019-05-27

/********************************************************************************** 
* 739. Daily Temperatures [Medium]
* Given a list of daily temperatures T, return a list such that, 
* for each day in the input, tells you how many days you would have 
* to wait until a warmer temperature. If there is no future day for
* which this is possible, put 0 instead.

* For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], 
* your output should be [1, 1, 4, 2, 1, 1, 0, 0].

* Note: The length of temperatures will be in the range [1, 30000].
* Each temperature will be an integer in the range [30, 100]. 
*               
**********************************************************************************/


// 192 ms, faster than 87.43% of C++, 16.2 MB, less than 49.51% of C++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> mystack;
        vector<int> res(T.size(),0);
        for(int i=0;i<T.size();i++){
            while( !mystack.empty() ){
                int top = mystack.top();
                if(T[i] <= T[top])break;
                res[top] = i-top;
                mystack.pop();
            } 
            mystack.push(i);
        }
        return res;
    }
};