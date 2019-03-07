// Source : https://oj.leetcode.com/problems/roman-to-integer/
// Author : Hao Chen
// Date   : 2014-07-17

/********************************************************************************** 
* 
* Given a roman numeral, convert it to an integer.
* 
* Input is guaranteed to be within the range from 1 to 3999.
*               
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int romanCharToInt(char ch){
    int d = 0;
    switch(ch){
        case 'I':  
            d = 1;  
            break;  
        case 'V':  
            d = 5;  
            break;  
        case 'X':  
            d = 10;  
            break;  
        case 'L':  
            d = 50;  
            break;  
        case 'C':  
            d = 100;  
            break;  
        case 'D':  
            d = 500;  
            break;  
        case 'M':  
            d = 1000;  
            break;  
    }
    return d;
}


//48 ms   30.9 MB   while python cost 172 ms 13.9 MB 
int romanToInt(string s) {
    if (s.size()<=0) return 0;
    int result = romanCharToInt(s[0]);
    for (int i=1; i<s.size(); i++){
        int prev = romanCharToInt(s[i-1]);
        int curr = romanCharToInt(s[i]);
        //if left<right such as : IV(4), XL(40), IX(9) ...
        if (prev < curr) {
            result = result - prev + (curr-prev);
        }else{
            result += curr;
        }
    }
    return result;
}

//72 ms 31.3 MB
int romanToInt2(string s) {
    if (s.size()<=0) return 0;
    vector<int> arr(s.size(),0);
    int sum1 = 0;
    for(int i=0;i<s.size();i++){
        arr[i] = romanCharToInt(s[i]);
        if(i>0 && arr[i-1] < arr[i]){
            arr[i] = arr[i] - arr[i-1] *2;
        }
        sum1 += arr[i];
    }
    
    
    return sum1;
}
int main(int argc, char**argv)
{
    string s("XL");
    if (argc>1){
        s = argv[1];
    }
    cout << s << " : " << romanToInt(s) << endl;
    return 0;
}
