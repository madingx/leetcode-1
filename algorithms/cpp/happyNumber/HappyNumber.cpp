// Source : https://leetcode.com/problems/happy-number/
// Author : Hao Chen
// Date   : 2015-06-08

/********************************************************************************** 
 * 202. Happy Number [Easy]
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 
 * (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this 
 * process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;

//there must be a circle for any number?

//4 ms  8 MB,faster than 100.00% of C++
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}


//4 ms  8.5 MB, faster than 100.00% of C++
int squares(int n) {
    int result = 0;
    int sq = 0;
    for (; n>0; n/=10) {
        sq = n%10;
        result += (sq * sq);
    }
    return result;
}

bool isHappy(int n) {

    if (n==1) return true;

    map<int, bool> m;
    m[n]=true;

    while (n!=1) {
        n = squares(n);
        //cout << n << endl;
        if (m.find(n) != m.end()){
            return false;
        }
        m[n] = true;
    }

    return true;
}


int main(int argc, char** argv) 
{
    int n = 2;
    if (argc > 1){
        n = atoi(argv[1]);
    }
    cout << n << (isHappy(n) ? " is " : " isn't ") << "a happy number" << endl;
    return 0;
}
