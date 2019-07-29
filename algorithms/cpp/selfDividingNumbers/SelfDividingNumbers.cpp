// Source : https://leetcode.com/problems/self-dividing-numbers/
// Author : Mading
// Date   : 2019-07-29

/********************************************************************************** 
* 728. Self Dividing Numbers [Easy]
* A self-dividing number is a number that is divisible by every digit it contains.

* For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, 
* and 128 % 8 == 0.

* Also, a self-dividing number is not allowed to contain the digit zero.

* Given a lower and upper number bound, output a list of every possible self 
* dividing number, including the bounds if possible.

* Example 1:
* Input: 
* left = 1, right = 22
* Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
* Note:

* The boundaries of each input argument are 1 <= left <= right <= 10000.
* 
*               
**********************************************************************************/

// 4 ms, faster than 73.83% of C++, 8.2 MB, less than 97.31% of C++
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++){
            if(i%10!=0 && check(i))
                v.push_back(i);
        }
        
        return v;
    }
    
    bool check(int n){
        int N=n;
        while(N){
            if(N%10==0)
                return false;
            if(n%(N%10)!=0)
                return false;
            N/=10;
            
        }
        return true;
    }
};