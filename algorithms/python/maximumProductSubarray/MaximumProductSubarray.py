# Source : https://leetcode.com/problems/maximum-product-subarray/
# Author : Hao Chen
# Date   : 2014-10-09

#********************************************************************************* 
# 152. Maximum Product Subarray [Medium]
# Given an integer array nums, find the contiguous subarray within an array 
# (containing at least one number) which has the largest product.

# Example 1:
# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.

# Example 2:
# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#*********************************************************************************

# 40 ms, faster than 99.91% of Python3, 14.3 MB, less than 5.52% of Python3
class Solution:
    def maxProduct(self, A):
        B = A[::-1]
        for i in range(1, len(A)):
            A[i] *= A[i - 1] or 1
            B[i] *= B[i - 1] or 1
        return max(A + B)


# this is art,but not high efficiency as C++ solution

