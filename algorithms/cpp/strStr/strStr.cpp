// Source : https://oj.leetcode.com/problems/implement-strstr/
// Author : Hao Chen
// Date   : 2014-07-19

/********************************************************************************** 
* 28. Implement strStr() [Easy]
* Implement strStr().

* Return the index of the first occurrence of needle in haystack, 
* or -1 if needle is not part of haystack.

* Example 1:

* Input: haystack = "hello", needle = "ll"
* Output: 2
* Example 2:

* Input: haystack = "aaaaa", needle = "bba"
* Output: -1
* Clarification:

* What should we return when needle is an empty string? 
* This is a great question to ask during an interview.

* For the purpose of this problem, we will return 0 when needle is an empty string.
* This is consistent to C's strstr() and Java's indexOf().
*               
**********************************************************************************/


// 4 ms, faster than 96.09% of C++, 9.1 MB, less than 51.40% of C++ 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size(), p = 0;
        while (p + n - 1 < m) {
            if (haystack.substr(p, n) == needle) {
                return p;
            }
            while (p++ + n - 1 < m && haystack[p] != needle[0]);
        }
        return -1;
    }
};



// KMP
// 4 ms, faster than 96.09% of C++, 9.2 MB, less than 40.71% of C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }











#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *strStr1(char *haystack, char *needle);
char *strStr2(char *haystack, char *needle);

char *strStr(char*haystack, char *needle) {
    if (random()%2){
        printf("---KMP---\n");
        return strStr1(haystack, needle);
    }
    printf("---brute-force---\n");
    return strStr2(haystack, needle);
}
//KMP
char *strStr1(char *haystack, char *needle) {
    if(!haystack || !needle ) {
        return NULL;
    }
    if (!*needle ) {
        return haystack;
    }

    char *ph = haystack;
    char *pn = needle;
    for( ;*ph && *pn ; ph++, pn++ );

    //len(haystack) < len(needle)
    if (!*ph && *pn){
        return NULL;    
    }

    for(ph=ph-1; *ph; haystack++, ph++) {
        char *q=needle;
        char *p=haystack;
        int n=0;
        while(*q && *p && *p==*q){
            p++; q++;
            if (n==0 && *p == *needle){
                n = p - haystack;
            }
        }
        if (!*q){
            return haystack;
        }
        haystack += (n>0 ? n-1 : n);
    }
    return NULL;
}

//brute-force
char *strStr2(char *haystack, char *needle) {

    if(!haystack || !needle ) {
        return NULL;
    }
    if (!*needle ) {
        return haystack;
    }

    char *ph = haystack;
    char* pn = needle;
    for( ;*ph && *pn ; ph++, pn++ );

    //len(haystack) < len(needle)
    if (!*ph && *pn){
        return NULL;    
    }
    ph--;

    for( ; *ph; haystack++, ph++) {
        char *q=needle;
        char *p=haystack;
        while(*q && *p && *p==*q){
            p++; q++;
        }
        if (!*q){
            return haystack;
        }
    }

    return NULL;
}

int main(int argc, char** argv)
{
    srand(time(0));
    const char* haystack = "mississippi";
    const char* needle = "issi";
    printf("%s, %s : %s\n", haystack, needle, strStr((char*)haystack, (char*)needle));

    haystack = "mississippi";
    needle = "issip";
    printf("%s, %s : %s\n", haystack, needle, strStr((char*)haystack, (char*)needle));


    haystack = "babbbbbabb";
    needle = "bbab";
    printf("%s, %s : %s\n", haystack, needle, strStr1((char*)haystack, (char*)needle));

    if (argc>2){
        haystack = argv[1];
        needle = argv[2];
        printf("%s, %s : %s\n", haystack, needle, strStr((char*)haystack, (char*)needle));
    }
    
    return 0;
}
