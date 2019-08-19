// Source : https://leetcode.com/problems/car-fleet/
// Author : Mading
// Date   : 2019-08-17

/********************************************************************************** 
* 853. Car Fleet [Medium]
* N cars are going to the same destination along a one lane road.  
* The destination is target miles away.

* Each car i has a constant speed speed[i] (in miles per hour), and 
* initial position position[i] miles towards the target along the road.

* A car can never pass another car ahead of it, but it can catch up to it,
* and drive bumper to bumper at the same speed.

* The distance between these two cars is ignored - they are assumed to have the same position.

* A car fleet is some non-empty set of cars driving at the same position and 
* same speed.  Note that a single car is also a car fleet.

* If a car catches up to a car fleet right at the destination point,
* it will still be considered as one car fleet.

* How many car fleets will arrive at the destination?


* Example 1:
* Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
* Output: 3
* Explanation:
* The cars starting at 10 and 8 become a fleet, meeting each other at 12.
* The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
* The cars starting at 5 and 3 become a fleet, meeting each other at 6.
* Note that no other cars meet these fleets before the destination, so the answer is 3.

* Note:
* 0 <= N <= 10 ^ 4
* 0 < target <= 10 ^ 6
* 0 < speed[i] <= 10 ^ 6
* 0 <= position[i] < target
* All initial positions are different.
*               
**********************************************************************************/


// 48 ms, faster than 75.86% of C++, 10.6 MB, less than 100.00% of C++
class Solution {
public:
    void SortPosition(vector<int>& position, vector<int>& speed) {
        vector<int> vec(position.size());
        for (int i = 0; i < position.size(); ++i)
            vec[i] = i;
        auto lambda = [&position](const int lhs, const int rhs) {
            return position[lhs] > position[rhs];
        };
        sort(vec.begin(), vec.end(), lambda);
        vector<int> vec2(position.size());
        for (int i = 0; i < position.size(); ++i)
            vec2[i] = position[vec[i]];
        position = vec2;
        for (int i = 0; i < position.size(); ++i)
            vec2[i] = speed[vec[i]];
        speed = vec2;
        return ;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        SortPosition(position, speed);
        int i = 0;
        int fleet_count = 0;
        while (i < position.size()) {
            double time_to_reach_target = (target - position[i]) / static_cast<double>(speed[i]);
            int j = i + 1;
            while (j < position.size()) {
                double distance_travelled = speed[j] * time_to_reach_target;
                double ending_position = position[j] + distance_travelled;
                if (ending_position >= target) {
                    ++j;
                    continue;
                } else {
                    break;
                }
            }
            ++fleet_count;
            i = j;
        }
        return fleet_count;
    }
};