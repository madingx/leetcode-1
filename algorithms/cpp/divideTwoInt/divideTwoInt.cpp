// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 29. Divide Two Integers [Medium]
* Given two integers dividend and divisor, divide two integers without using multiplication, 
* division and mod operator.

* Return the quotient after dividing dividend by divisor.

* The integer division should truncate toward zero.

* Example 1:

* Input: dividend = 10, divisor = 3
* Output: 3
* Example 2:

* Input: dividend = 7, divisor = -3
* Output: -2
* Note:

* Both dividend and divisor will be 32-bit signed integers.
* The divisor will never be 0.
* Assume we are dealing with an environment which could only store integers within 
* the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
* assume that your function returns 231 − 1 when the division result overflows.
*
**********************************************************************************/

// 0 ms, faster than 100.00% of C++, 8.2 MB, less than 82.00% of C++.
class Solution {
public:
    int divide(int dividend, int divisor) {
        return (dividend==INT_MIN&&divisor==-1)?INT_MAX:dividend/divisor;
    }
};




#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

int divide(int dividend, int divisor) {

    int sign = (float)dividend / divisor > 0 ? 1 : -1;
    unsigned int dvd = dividend > 0 ? dividend : -dividend;
    unsigned int dvs = divisor > 0 ? divisor : -divisor;

    unsigned int bit_num[33];
    unsigned int i=0;
    long long d = dvs;
    bit_num[i] = d;
    while( d <= dvd ){
        bit_num[++i] = d = d << 1;
    }
    i--;

    unsigned int result = 0;
    while(dvd >= dvs){
        if (dvd >= bit_num[i]){
            dvd -= bit_num[i];
            result += (1<<i);
        }else{
            i--;
        }
    }

    //becasue need to return `int`, so we need to check it is overflowed or not.
    if ( result > INT_MAX && sign > 0 ) {
        return INT_MAX;
    }
    return (int)result * sign;
}


int main()
{
    cout << "0/2=" << divide(0, 2) << endl;
    cout << "10/2=" << divide(10, 2) << endl;
    cout << "10/3=" << divide(10, 3) << endl;
    cout << "10/5=" << divide(10, 5) << endl;
    cout << "10/7=" << divide(10, 7) << endl;
    cout << "10/10=" << divide(10, 10) << endl;
    cout << "10/11=" << divide(10, 11) << endl;
    cout << "-1/1=" << divide(1, -1) << endl;
    cout << "1/-1=" << divide(1, -1) << endl;
    cout << "-1/-1=" << divide(-1, -1) << endl;
    cout << "2147483647/1=" << divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << divide(-2147483648, 1) << endl;
    cout << "-2147483648/-1=" << divide(-2147483648, -1) << endl;
}
