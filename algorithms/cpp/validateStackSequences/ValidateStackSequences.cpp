// Source : https://leetcode.com/problems/validate-stack-sequences/
// Author : Mading
// Date   : 2019-05-30

/********************************************************************************** 
 * 946. Validate Stack Sequences [Medium]
 * Given two sequences pushed and popped with distinct values, 
 * return true if and only if this could have been the result of
 * a sequence of push and pop operations on an initially empty stack.

 * Example 1:
 * Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * Output: true
 * Explanation: We might do the following sequence:
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

 * Example 2:
 * Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * Output: false
 * Explanation: 1 cannot be popped before 2.
 
 * Note:

 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed is a permutation of popped.
 * pushed and popped have distinct values.
 * 
 **********************************************************************************/


// 8 ms, faster than 97.88% of C++, 9 MB, less than 74.97% of C++ 
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size())return false;
        stack<int> mystack;
        int i = 0;
        for(int j=0;j<popped.size();j++){
            if( i>= pushed.size() && mystack.empty())return false;
            if(!mystack.empty())
                if(mystack.top() == popped[j]){ mystack.pop(); continue;}
            if(i < pushed.size()){
                if(pushed[i] == popped[j]){ i++; continue;}
                else{
                    mystack.push(pushed[i]);
                    i++;
                    j--; 
                }
            }
        }
        return i == pushed.size() && mystack.empty();
    }
};