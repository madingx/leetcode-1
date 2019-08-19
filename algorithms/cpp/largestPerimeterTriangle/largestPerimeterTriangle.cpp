// Source : https://leetcode.com/problems/largest-perimeter-triangle/
// Author : Mading
// Date   : 2019-08-16

/********************************************************************************** 
* 976. Largest Perimeter Triangle [Easy]
* Given an array A of positive lengths, return the largest perimeter of a 
* triangle with non-zero area, formed from 3 of these lengths.

* If it is impossible to form any triangle of non-zero area, return 0.

 
* Example 1:
* Input: [2,1,2]
* Output: 5

* Example 2:
* Input: [1,2,1]
* Output: 0

* Example 3:
* Input: [3,2,3,4]
* Output: 10

* Example 4:
* Input: [3,6,2,3]
* Output: 8
 

* Note:
* 3 <= A.length <= 10000
* 1 <= A[i] <= 10^6
* 
*               
**********************************************************************************/


// 64 ms, faster than 14.55% of C++, 10.4 MB, less than 100.00% of C++
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end(),greater<int>());
        int i= 0;
        while(i+2<A.size()){            
            if(A[i] < A[i+1] + A[i+2])break;
            i++;
        }
        return i+2>=A.size() ? 0 : A[i]+A[i+1]+A[i+2];
    }
};




class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) return 0;
        sort(A.begin(), A.end(), greater<int>());
        for (auto it = A.begin(); it != A.end() - 2; ++it) {
            if (*it < *(it + 1) + *(it + 2))
                return *it + *(it + 1) + *(it + 2);            
        }
        return 0;
    }
};