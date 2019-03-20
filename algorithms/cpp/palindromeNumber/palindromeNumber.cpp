// Source : https://leetcode.com/problems/palindrome-number/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 9. Palindrome Number [easy]
* Determine whether an integer is a palindrome. An integer is a palindrome 
* when it reads the same backward as forward.

* Example 1:
* Input: 121
* Output: true

* Example 2:
* Input: -121
* Output: false
* Explanation: From left to right, it reads -121. From right to left, it becomes 121-.
* Therefore it is not a palindrome.

* Example 3:
* Input: 10
* Output: false
* Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*               
**********************************************************************************/

#include <stdio.h>

class Solution {
public:

    //108 ms  72.9 MB, faster than 97.48% of C++
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;                         //注意这个过程
        }
        //input=12321;  here:x=12 ,revertedNumber=123
        //input=1221;  here:x=12 ,revertedNumber=12
        return x == revertedNumber || x == revertedNumber/10;        
    }


    //108 ms    73 MB, faster than 97.48% of C++
    bool isPalindrome(int x) {
        if(x<0)return false;
        long n = 0; //long int is a tricky method 
        long m = x;
        while(m>0){
            n = n*10 + m%10;
            m /= 10;
        }
        return n==x;
    }

    //112 ms    73.1 MB, faster than 84.19% of C++
    bool isPalindrome(int x) {
        if (x<0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int len=1;
        for (len=1; (x/len) >= 10; len*=10 );
        
        while (x != 0 ) {
            int left = x / len;
            int right = x % 10;
            
            if(left!=right){
                return false;
            }
            
            x = (x%len) / 10;
            len /= 100;
        }
        return true;
    }
    
    bool isPalindrome2(int x) {
        return (x>=0 && x == reverse(x));
    }

private:    
    int reverse(int x) {
        int y=0;

        int n;
        while( x!=0 ){
            n = x%10;
            y = y*10 + n;
            x /= 10;
        }
        return y;
    }
};



int main()
{
    Solution s;
    printf("%d is %d\n", 0, s.isPalindrome(0) );
    printf("%d is %d\n", -101, s.isPalindrome(-101) );
    printf("%d is %d\n", 1001, s.isPalindrome(1001) );
    printf("%d is %d\n", 1234321, s.isPalindrome(1234321) );
    printf("%d is %d\n", 2147447412, s.isPalindrome(2147447412) );
    printf("%d is %d\n", 2142, s.isPalindrome(2142) );
}
