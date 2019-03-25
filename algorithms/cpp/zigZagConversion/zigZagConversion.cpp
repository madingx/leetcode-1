// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 6. ZigZag Conversion [Medium]
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* 
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* 
* string convert(string text, int nRows);
* 
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

* * Example 1:
* Input: s = "PAYPALISHIRING", numRows = 3
* Output: "PAHNAPLSIIGYIR"

* Example 2:
* Input: s = "PAYPALISHIRING", numRows = 4
* Output: "PINALSIGYAHRPI"
* Explanation:
* P     I    N
* A   L S  I G
* Y A   H R
* P     I
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//24 ms 16.6 MB, faster than 91.19% of C++
string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string result;
        result.reserve(s.size());
        int maxSkip = numRows + max(numRows - 2, 0);
        for (int i = 0; i < numRows; ++i) {
            int j = i;
            int skips[2];
            if (i == 0 || i == numRows - 1) {
                skips[0] = skips[1] = maxSkip;
            } else {
                skips[0] = maxSkip - i * 2;
                skips[1] = i * 2;
            }
            const int *skip = skips;
            while (j < s.size())
            {
                result.push_back(s[j]);
                j += *skip;
                skip = (skip == skips)? skips + 1 : skips;
            }
        }
        return result;
    }

//24 ms 19.2 MB, faster than 91.19% of C++
string convert(string s, int numRows) {
    //The cases no need to do anything
    if (numRows<=1 || numRows>=s.size()) return s;
     
    vector<string> r(numRows);
    int row = 0;
    int step = 1;
    for(int i=0; i<s.size(); i ++) {
        if (row == numRows-1) step = -1;
        if (row == 0) step = 1;
        //cout << row <<endl;
        r[row] += s[i];
        row += step;
    }
    
    string result;
    for (int i=0; i<numRows; i++){
        result += r[i];
    }
    return result;
}

int main(int argc, char**argv){

    string s;
    int r;

    s = "PAYPALISHIRING";
    r = 3;
    cout << s << " : " << convert(s, 3) << endl;

}

//not very well
//28 ms 19.3 MB, faster than 65.83% of C++
string convert(string s, int numRows) {
    if(numRows==1)return s;
    vector<string> a(numRows,"");
    for(int i = 0;i<s.length();i++){
        //jth in one circle
        int j = i%(numRows*2-2);
        //punished k
        int k = j>=numRows? (j+1)%numRows : 0;
        a[j-2*k] += s[i];         
    }
    for(int i = 1;i<numRows;i++){
        a[0] += a[i];
    }
    return a[0];
}