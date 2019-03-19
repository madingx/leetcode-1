// Source : https://leetcode.com/problems/excel-sheet-column-title/
// Author : Hao Chen
// Date   : 2014-12-25

/********************************************************************************** 
 * 168. Excel Sheet Column Title [Easy]
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.

 * For example:

 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
    ...

 * Example 1:
 * Input: 1
 * Output: "A"

 * Example 2:
 * Input: 28
 * Output: "AB"

 * Example 3:
 * Input: 701
 * Output: "ZY"
 *               
 **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//4 ms    8 MB, faster than 100.00% of C++
string convertToTitle(int n) {
        int m= 0;
        string a = "";
        while(n>0){
            m = (n-1)%26;
            a = a.insert(0,1,'A' + m);
            n = (n-1)/26;
        }
        return a;
    }



//4 ms  8.1 MB
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

long long base26_str2int(string& s){
    long long ret=0;
    for (int i=0; i<s.size(); i++){
        int n = s[i] - 'A' + 1;
        ret = ret*26 + n;
    }
    return ret;
}


string convertToTitle(int n) {
    return base26_int2str(n);
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
