// Source : https://leetcode.com/problems/gray-code/
// Author : Hao Chen
// Date   : 2014-06-20

/********************************************************************************** 
* 89. Gray Code [Medium]
* The gray code is a binary numeral system where two successive values differ in only one bit.
* 
* Given a non-negative integer n representing the total number of bits in the code, 
* print the sequence of gray code. A gray code sequence must begin with 0.
* 
* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
* 
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* 
* Note:
* For a given n, a gray code sequence is not uniquely defined.
* 
* For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
* 
* For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

/*
 * I designed the following stupid algorithm base on the blow observation
 * 
 * I noticed I can use a `mirror-like` binary tree to figure out the gray code.
 * 
 * For example:
 * 
 *           0      
 *        __/ \__   
 *       0       1  
 *      / \     / \ 
 *     0   1   1   0
 * So, the gray code as below: (top-down, from left to right)
 *
 *     0 0 0 
 *     0 0 1
 *     0 1 1
 *     0 1 0
 * 
 *                  0
 *            _____/ \_____
 *           0             1
 *        __/ \__       __/ \__
 *       0       1     1       0
 *      / \     / \   / \     / \
 *     0   1   1   0 0   1   1   0
 * 
 * So, the gray code as below:
 *
 *     0 0 0 0 
 *     0 0 0 1
 *     0 0 1 1
 *     0 0 1 0
 *     0 1 1 0
 *     0 1 1 1 
 *     0 1 0 1
 *     0 1 0 0
 */
vector<int> grayCode01(int n) {
    vector<int> v;
    //n = 1<<n;
    
    int x =0;   
    v.push_back(x); 
    for(int i=0; i<n; i++){
        int len = v.size();
        for (int j=0; j<len; j++){
            x = v[j]<<1;
            if (j%2==0){
                v.push_back(x);
                v.push_back(x+1);
            }else{
                v.push_back(x+1);
                v.push_back(x);
            }
        }
        v.erase(v.begin(), v.begin()+len);
    }
     
    return v;
}

/*
 * Actually, there is a better way.
 * The mathematical way is: (num >> 1) ^ num; 
 * Please refer to http://en.wikipedia.org/wiki/Gray_code
 */
// 4 ms, faster than 98.01% of C++ , 8.7 MB, less than 52.07% of C++ 
vector<int> grayCode02(int n) {
    vector<int> ret;   
    int size = 1 << n;   
    for(int i = 0; i < size; ++i) {
        ret.push_back((i >> 1)^i);   
    }
    return ret;   
}




/********************
 gry  add   bit    i     gray = (i>>1) ^ i 
 000
 001  +1     1    001    00 ^ 001
 011  +2     2    010    01 ^ 010
 010  -1     1    011    01 ^ 011

 110  +4     3    100    10 ^ 100
 111  +1     1    101    10 ^ 101
 101  +2     2    110    11 ^ 110
 100  -1     1    111    11 ^ 111

1100  +8     4
1101  +1     1
1111  +2     2
1110  -1     1
1010  -4     3
1011  +1     1
1001  -2     2
1000  -1     1

********************/
// 4 ms, faster than 98.01% of C++, 8.8 MB, less than 31.37% of C++
vector<int> grayCode03(int n) {
    int m = 0;
    int flag = 1;
    vector<int> res;
    for(int i=1;i<=(1 << n);i++){
        res.push_back(m);
        flag = 1;
        for(int j = i;j>0;j = j>>1){
            if(j%2 == 1)break;
            flag = flag<<1;
        }
        m ^= flag;
    }
    return res;
}

















//random invoker
vector<int> grayCode(int n) {
    srand(time(0));
    if (rand()%2){
        return grayCode01(n);
    }
    return grayCode02(n);
}

void printBits(int n, int len){
    for(int i=len-1; i>=0; i--) {
        if (n & (1<<i)) {
            printf("1");
        }else{
            printf("0");
        }
    }
}

void printVector(vector<int>& v, int bit_len)
{
    vector<int>::iterator it;

    for(it=v.begin(); it!=v.end(); ++it){
        //bitset<bit_len> bin(*it);
        printBits(*it, bit_len);
        cout <<  " ";
        //cout << *it <<  " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    int n = 2;
    if (argc>1){
        n = atoi(argv[1]); 
    }
    vector<int> v = grayCode(n);
    printVector(v, n);
    return 0;
}
