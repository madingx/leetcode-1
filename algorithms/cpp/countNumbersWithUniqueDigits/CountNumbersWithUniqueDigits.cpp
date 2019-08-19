// Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
// Author : Mading,Hao Chen
// Date   : 2019-04-10

/*************************************************************************************** 
 * 357. Count Numbers with Unique Digits [Medium]
 * 
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

 * Example:
 * Input: 2
 * Output: 91 
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
 *             excluding 11,22,33,44,55,66,77,88,99
 ***************************************************************************************/

// 4 ms, faster than 99.82% of C++, 8 MB, less than 88.71% of C++
int countNumbersWithUniqueDigits(int n) {
    if(n == 0)
        return 1;
    int f_next = 10, f_prev = 1;
    for(int i=2, j=9; i<=n; ++i, --j){
        int temp = f_next;
        f_next = (f_next-f_prev)*j + f_next;
        f_prev = temp;
    }
    return f_next;
}


// 8 ms, faster than 10.11% of C++, 8.2 MB, less than 29.03% of C++
int countNumbersWithUniqueDigits(int n) {
        vector<int> v(11, 9); // {1, 10, v[i-1]+9*9, v[i-1]+9*9*8, v[i-1]+9*9*8*7, ……}
        v[0] = 1;
        v[1] = 10;
        for(int i = 2; i < 10; ++i){
            int tmp = i-1;
            for(int j = 9; j >= 1 && tmp--; --j){
                v[i] *= j;
            }
            v[i] += v[i - 1];
        }

        if(n >= 10)
            return v[9];
        else
            return v[n];
    }




// Considering three digits
//   - the first place could be [1-9] which has 9 choices.
//   - the second place could be [0-9] with excluding the first digit, which is 10-1=9 choices.
//   - the third place could be [0-9] with excluding the 1st and 2nd digits, which is 10-2=8 choices.
// So, three digits has 9*9*8 unique digits.
//
// After adds the 1 digit unique number,and 2 digits unique number, we can have the result:
//
//   9*9*8 + 9*9 + 10 = 648 + 81 + 10 = 739
//
// n = 0, a[0] = 1;
// n = 1, a[1] = 9 + a[0];
// n = 2, a[2] = 9*9 + a[1];
// n = 3, a[3] = 9*9*8 + a[2];
// n = 4, a[4] = 9*9*8*7 + a[3];
// ....
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 1;
        for (int i=0; i<n; i++) {
            result += ( 9 * nine_factor(i) );
        }
        return result;
    }

    int nine_factor(int n) {
        int result = 1;
        for (int i=0; i<n; i++) {
            result *= (9-i);
        }
        return result;
    }
};


//actually, the function nine_factor() could be optimized!

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 1;
        int nine_factor = 1;
        for (int i=0; i<n; i++) {
            result += ( 9 * nine_factor );
            nine_factor *= (9-i);
        }
        return result;
    }


};