// Source : https://leetcode.com/problems/jump-game-iv/
// Author : Mading
// Date   : 2020-02-14

/********************************************************************************** 
1345. Jump Game IV [Hard]

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
*               
**********************************************************************************/

// class Node{
// public:
//     int val;
//     vector<Node*> vec;
    
    
// }



// 168 ms, faster than 58.30% of C++, 35.8 MB, less than 100.00% of C++
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < arr.size(); i++) indices[arr[i]].emplace_back(i);

        queue<int> q;
        q.push(0);
        vector<int> dist(arr.size());

        while(!q.empty()) {
            int temp = q.front(); q.pop();
            if(temp == arr.size() - 1) return dist[temp];   

            vector<int>& list = indices[arr[temp]];
            list.emplace_back(temp - 1), list.emplace_back(temp + 1);

            for(const auto &i: list) {
                if(i > 0 && i < arr.size() && !dist[i]) {
                    dist[i] = 1 + dist[temp];
                    q.push(i);
                }
            }
            list.clear(); // had to check discussion to learn this trick (only failed 1 case without it, which is a few thousand 7s followed by a single 11)
        }
        return -1;
    }
};