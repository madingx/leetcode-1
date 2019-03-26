// Source : https://leetcode.com/problems/min-cost-climbing-stairs/
// Author : Hao Chen
// Date   : 2019-02-04

/***************************************************************************************************** 
 *
 * 746. Min Cost Climbing Stairs [Easy] 
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to 
 * reach the top of the floor, and you can either start from the step with index 0, or the step with 
 * index 1.
 * 
 * Example 1:
 * 
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 * 
 * Example 2:
 * 
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 * 
 * Note:
 * 
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * 
 ******************************************************************************************************/

class Solution {
public:
    //16 ms   8.7 MB, faster than 18.93% of C++
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dyncost(cost.size()+2,0);
        int i=2;
        for(;i<dyncost.size()-1;i++){
            dyncost[i+1] = min(dyncost[i]+cost[i-1],dyncost[i-1]+cost[i-2]);
        }
        return dyncost[i];
        //cost   [1,2,3,4]
        //dyn  [0,0,0,1,2,4]
    }

};
