// Source : https://leetcode.com/problems/rabbits-in-forest/
// Author : Mading
// Date   : 2019-05-19

/***************************************************************************************************** 
 * 781. Rabbits in Forest [Medium]
 * In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell
 * you how many other rabbits have the same color as them. Those answers are placed in an array.

 * Return the minimum number of rabbits that could be in the forest.

 * Examples:
 * Input: answers = [1, 1, 2]
 * Output: 5
 * Explanation:
 * The two rabbits that answered "1" could both be the same color, say red.
 * The rabbit than answered "2" can't be red or the answers would be inconsistent.
 * Say the rabbit that answered "2" was blue.
 * Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
 * The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

 * Input: answers = [10, 10, 10]
 * Output: 11

 * Input: answers = []
 * Output: 0
 * Note:

 * answers will have length at most 1000.
 * Each answers[i] will be an integer in the range [0, 999].
 ******************************************************************************************************/



// 4 ms, faster than 98.94% of C++, 9.2 MB, less than 42.19% of C++
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> color;
        for(auto a : answers)color[a]++;
        int s = 0;
        for(unordered_map<int,int>::iterator it=color.begin();it!=color.end();it++){
            s += (it->first+1)*ceil(1.0*it->second/(it->first+1));
        }
        return s;
    }
};


/**********
number of 1 -> min number of rabits
1 ->  2
2 ->  2
3 ->  4
4 ->  4
5 ->  6

numbers of 2 -> min number of rabits
1 ->  3
2 ->  3
3 ->  3
4 ->  6
5 ->  6

number = (i+1)*ceil(color[i] / (i+1))
**********/