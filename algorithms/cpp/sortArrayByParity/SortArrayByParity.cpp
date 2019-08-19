// Source : https://leetcode.com/problems/sort-array-by-parity/
// Author : Mading,Hao Chen
// Date   : 2019-03-15

/********************************************************************************** 
 * 905. Sort Array By Parity [easy]
 * Given an array A of non-negative integers, return an array consisting of all the 
 * even elements of A, followed by all the odd elements of A.
 * You may return any answer array that satisfies this condition.

 * Example 1:
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

 * Note:
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 *               
 **********************************************************************************/


//32 ms 11.2 MB, faster than 98.89% of C++
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size()-1;
        while(i<j){
            if(A[i] % 2 == 0){i++;continue;}
            if(A[j] % 2 != 0){j--;continue;}
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        return A;
    }
};





class Solution {
public:
    bool isEven(int& x) {
        return x % 2 == 0;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        //two pointer, one from left to right, another from right to left
        // if left is odd number and right is even number, switch them
        int l=0, r=A.size()-1;
        while ( l < r ) {
            if ( !isEven(A[l]) && isEven(A[r]) ) swap(A[l], A[r]);
            if ( isEven(A[l]) ) l++;
            if ( !isEven(A[r]) ) r--;
        }
        return A;
    }
};
