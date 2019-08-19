// Source : https://leetcode.com/problems/maximum-product-subarray/
// Author : Hao Chen, Mading
// Date   : 2014-10-09

/********************************************************************************** 
* 152. Maximum Product Subarray [Medium]
* Given an integer array nums, find the contiguous subarray within an array 
* (containing at least one number) which has the largest product.

* Example 1:
* Input: [2,3,-2,4]
* Output: 6
* Explanation: [2,3] has the largest product 6.

* Example 2:
* Input: [-2,0,-1]
* Output: 0
* Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*               
**********************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int max(int x, int y) {
    return x>y?x:y;
}
int min(int x, int y){
    return x<y?x:y;
}
int max(int x, int y, int z) {
    return max(x, max(y,z));
}
int min(int x, int y, int z) {
    return min(x, min(y, z));
}

// The idea is similar with "Find the subarray wich has the largest sum"
// (See: http://en.wikipedia.org/wiki/Maximum_subarray_problem)
// 
// The only thing to note here is, maximum product can also be obtained by minimum (negative) product 
// ending with the previous element multiplied by this element. For example, in array {12, 2, -3, -5, -6, -2}, 
// when we are at element -2, the maximum product is multiplication of, minimum product ending with -6 and -2.

// 4 ms, faster than 100.00% of C++, 9 MB, less than 80.36% of C++
// 4 ms, faster than 100.00% of C++, 9 MB, less than 80.36% of C++
int maxProduct(vector<int>& nums) {
    // To remember the max/min product for previous position
    int maxPrev = nums[0], minPrev = nums[0];
    // To remember the max/min product for current position
    int maxHere = nums[0], minHere = nums[0];
    // Overall maximum product
    int maxProd = nums[0];

    for (int i=1; i<nums.size(); i++){
        //max( maxPrev * A[i],  minPrev * A[i],  A[i] )
        maxHere = max( max( maxPrev * nums[i], minPrev * nums[i] ), nums[i] );
        //min( maxPrev * A[i],  minPrev * A[i],  A[i] )
        minHere = min( min( maxPrev * nums[i], minPrev * nums[i] ), nums[i] );
        //Keep tracking the overall maximum product
        maxProd = max(maxHere, maxProd);
        //Shift the current max/min product to previous variables
        maxPrev = maxHere;
        minPrev = minHere;
    }
    return maxProd;    
}


#define TEST(a)    cout << maxProduct( a, sizeof(a)/sizeof(int)) << endl
int main()
{
    int o[] = {2,3,-2,4};
    TEST(o);

    int a[] = {-4,-3};
    TEST(a);

    int b[] = {-1, -1};
    TEST(b);

    int c[] = {-1, 0, -2};
    TEST(c);
}
