// Source : https://leetcode.com/problems/rotated-digits/
// Author : Mading
// Date   : 2019-09-08

/********************************************************************************** 
* 788. Rotated Digits [Easy]
* X is a good number if after rotating each digit individually by 180 degrees, 
* we get a valid number that is different from X.  Each digit must be 
* rotated - we cannot choose to leave it alone.

* A number is valid if each digit remains a digit after rotation. 0, 1, 
* and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate 
* to each other, and the rest of the numbers do not rotate to any other 
* number and become invalid.

* Now given a positive number N, how many numbers X from 1 to N are good?

* Example:
* Input: 10
* Output: 4
* * Explanation: 
* There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
* Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

* Note:
* N  will be in range [1, 10000].    
**********************************************************************************/


// 4 ms, faster than 80.21% of C++, 8.3 MB, less than 80.00% of C++.
class Solution {
    
    // from 0 to 9
    int single_digit_code (int x){
        if(x==3 || x==4 || x==7) return 0;
        if(x==2 || x==5 || x==6 || x==9) return 1;
        return 2;
        
    }
    
public:
    int rotatedDigits(int N) {
        int count = 0;
        for(int i=1; i<=N; i++){
            bool is_good = false;
            int x=i;
            while(x>0){
                int code = single_digit_code(x%10);
                if(code==0) {
                    is_good = false;
                    break;
                }
                if(code==1){
                    is_good = true;
                }
                x/=10;
            }
            if(is_good) ++count;
        }
        
        return count;
    }
};