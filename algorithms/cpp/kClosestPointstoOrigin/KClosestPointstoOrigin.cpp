// Source : https://leetcode.com/problems/k-closest-points-to-origin/
// Author : Mading
// Date   : 2019-05-25

/*************************************************************************************** 
 * 973. K Closest Points to Origin [Medium]
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 * You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 * Example 1:

 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation: 
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].


 * Example 2:

 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 

 * Note:

 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 *               
 ***************************************************************************************/


// 240 ms, faster than 80.23% of C++, 42.5 MB, less than 64.44% of C++
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        if(points.size() == 0) return result;

        typedef pair<int, int> pi;

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        int m = points.size();
        int n = points[0].size();

        for(int i = 0; i < m; ++i) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push(make_pair(dist, i));
        }

        int j = 0;
        while(j != K) {
            int idx = pq.top().second;
            pq.pop();
            result.push_back(points[idx]);
            j++;
        }

        return result;
    }
};
