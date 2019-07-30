// Source : https://leetcode.com/problems/stone-game-ii/
// Author : Mading
// Date   : 2019-07-30

/***************************************************************************************************** 
 * 1140. Stone Game II [easy]
 * 
 * Alex and Lee continue their games with piles of stones.  There are a number of piles arranged 
 * in a row, and each pile has a positive integer number of stones piles[i].  The objective of 
 * the game is to end with the most stones. 

 * Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
 * On each player's turn, that player can take all the stones in the first X remaining piles, 
 * where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * The game continues until all the stones have been taken.
 * Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.


 * Example 1:
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex 
 * takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles 
 * at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 
 * piles in total. So we return 10 since it's larger. 
 

 * Constraints:

 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10 ^ 4
 ******************************************************************************************************/

// 72 ms, faster than 8.83% of C++, 10.6 MB, less than 100.00% of C++
class Solution {
    int memorize(vector<int>& piles, int sum, int idx,int m,unordered_map<string,int> &mymap){
        if(idx>=piles.size()) return 0;
        string pos = "(";
        pos = pos + to_string(idx) + "," +  to_string(m) + ")";
        if(mymap.count(pos)  > 0){
            return mymap[pos];
        }
        int choose=0,maxval=0,sz = piles.size();
        for(int i=idx;i < min(idx+2*m,sz) ;i++){ 
            choose += piles[i];
            // the maxs stone that bob get
            int tmp = memorize(piles,sum-choose,i+1,max(i-idx+1,m),mymap);
            // sum: sum of stones left
            // sum - dfs(...) is the value we can get in this turn.
            // the next player also plays optimally
            maxval = max(maxval,sum-tmp);
        }
        mymap[pos] = maxval;
        return maxval;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        for(auto p : piles){
            sum += p;
        }
        unordered_map<string,int> mymap;
        return memorize(piles,sum,0,1,mymap);
    }
};