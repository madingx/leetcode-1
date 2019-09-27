// Source : https://leetcode.com/problems/powx-n/
// Author : Hao Chen
// Date   : 2014-06-25

/********************************************************************************** 
* 50. Pow(x, n) [Medium]
* Implement pow(x, n), which calculates x raised to the power n (xn).

* Example 1:

* Input: 2.00000, 10
* Output: 1024.00000
* Example 2:

* Input: 2.10000, 3
* Output: 9.26100
* Example 3:

* Input: 2.00000, -2
* Output: 0.25000
* Explanation: 2-2 = 1/22 = 1/4 = 0.25
* Note:

* -100.0 < x < 100.0
* n is a 32-bit signed integer, within the range [−231, 231 − 1]
*               
**********************************************************************************/




// 0 ms, faster than 100.00% of C++, 8.2 MB, less than 100.00% of C++ 
class Solution {
public:
    double myPow(double x, long long int  n) {
        if (n == 0){
            return 1.0;
        }
        if ( n == -1){
            return 1.0/x;
        }
        double hp= myPow(x,n/2);
        int np = abs(n);
        if (np%2 == 1){
            double m = n > 0 ? x:(1.0/x);
            return m*hp*hp;
        }
        else{
            return hp*hp;
        }
    }
};





#include <stdio.h>
#include <stdlib.h>

/*
 *   Basically, most people think this is very easy as below:
 *
 *      double result = 1.0;
 *      for (int i=0; i<n; i++){
 *           result *=x;
 *      }
 *   
 *   However, 
 *
 *     1) We need think about the `n` is negtive number.
 *
 *     2) We need more wisely deal with the following cases:
 *
 *         pow(1, MAX_INT);
 *         pow(-1,BIG_INT);
 *         pow(2, BIG_INT);
 *
 *        To deal with such kind case, we can use x = x*x to reduce the `n` more quickly
 *
 *        so, if `n` is an even number, we can `x = x*x`, and `n = n>>1;`
 *            if `n` is an odd number, we can just `result *= x;`
 *
 */
double pow(double x, int n) {

    bool sign = false;
    unsigned int exp = n;
    if(n<0){
        exp = -n;
        sign = true;
    }
    double result = 1.0;
    while (exp) {
        if (exp & 1){
            result *= x;
        }
        exp >>= 1;
        x *= x;
    }

    return sign ? 1/result : result;

}

int main(int argc, char** argv){
    double x=2.0;
    int n = 3;
    if (argc==3){
        x = atof(argv[1]);
        n = atoi(argv[2]);
    }
    printf("%f\n", pow(x, n));
    return 0;
}
