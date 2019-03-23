// Source : https://leetcode.com/problems/excel-sheet-column-number/
// Author : Hao Chen
// Date   : 2014-12-29

/********************************************************************************** 
 * 171. Excel Sheet Column Number [Easy]
 * Related to question 168. Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding column number.

 * For example:
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 *     ...

 * Example 1:
 * Input: "A"
 * Output: 1

 * Example 2:
 * Input: "AB"
 * Output: 28

 * Example 3:
 * Input: "ZY"
 * Output: 701
 *               
 **********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


string base26_int2str(long long n) {
    string ret;
    while(n>0){
        char ch = 'A' + (n-1)%26;
        ret.insert(ret.begin(), ch  );
        n -= (n-1)%26;
        n /= 26;
    }
    return ret;
}

//4 ms  8.3 MB
long long base26_str2int(string& s){
    long long ret=0;
    for (int i=0; i<s.size(); i++){
        int n = s[i] - 'A' + 1;
        ret = ret*26 + n;
    }
    return ret;
}


string titleToNumber(int n) {
    return base26_str2int(n);
}

int main(int argc, char**argv)
{
    long long n = 27; 
    if (argc>1){
        n = atoll(argv[1]);
    }
    string ns = base26_int2str(n);
    n = base26_str2int(ns);

    cout << n << " = " << ns << endl;


    ns = "ABCDEFG";
    if (argc>2){
        ns = argv[2];
    }
    cout << ns << " = " << base26_str2int(ns) << endl;
}
