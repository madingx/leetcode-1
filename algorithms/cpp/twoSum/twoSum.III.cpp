// Source : https://leetcode.com/problems/two-sum-iii-data-structure-design
// Author : Hao Chen
// Date   : 2014-12-29
// 
// Latest Edition
// Editor : Mading
// Date   : 2017-11-12

/********************************************************************************** 
* 170. Two Sum III - Data structure design 
* 
* Design and implement a TwoSum class. It should support the following operations: add and find.
* 
* add - Add the number to an internal data structure.
* find - Find if there exists any pair of numbers which sum is equal to the value.
* 
* For example,
*
*   add(1); add(3); add(5);
*   find(4) -> true
*   find(7) -> false
* 
**********************************************************************************/

class TwoSum {
    private:
        unordered_map<int, int> nums; //http://blog.csdn.net/hk2291976/article/details/51037095
    public:

        //O(1) add
        void add(int number) {
            nums[number]++;//add(3):   nums[3] += 1;
        }

        //O(n) find
        bool find(int value) {
            int one, two;
            for(auto it = nums.begin(); it != nums.end(); it++){
                one = it->first;
                two = value - one;
                if ( (one == two && it->second > 1) ||      //同一个数出现两次
                        (one != two && nums.find(two) != nums.end() ) ){   //能找到匹配的另一个数
                    return true;
                }
            }
            return false;
        }
};
