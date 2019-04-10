// Source : https://leetcode.com/problems/count-numbers-with-unique-digits/
// Author : Mading
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