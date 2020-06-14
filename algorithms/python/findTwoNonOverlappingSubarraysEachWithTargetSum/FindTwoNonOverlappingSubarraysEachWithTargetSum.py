# 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum [Medium]

# Given an array of integers arr and an integer target.

# You have to find two non-overlapping sub-arrays of arr each 
# with sum equal target. 

# There can be multiple answers so you have to find an answer 
# where the sum of the lengths of the two sub-arrays is minimum.

# Return the minimum sum of the lengths of the two required sub-arrays, 
# or return -1 if you cannot find such two sub-arrays.



# 1376 ms, faster than 75.00% of Python3, 35.9 MB, less than 25.00% of Python3  Sub-arrays Each With Target Sum.
class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        prefix = {0: -1}
        minsubarray_till = [math.inf] * len(arr)
        ans = minsubarray = math.inf
        for i, curr in enumerate(itertools.accumulate(arr)):
            if curr - target in prefix:
                end = prefix[curr - target]
                if end > -1:
                    ans = min(ans, i - end + minsubarray_till[end])
                minsubarray = min(minsubarray, i - end)
            minsubarray_till[i] = minsubarray
            prefix[curr] = i
        return -1 if ans == math.inf else ans


# Discuss
# https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/discuss/685470/Python-One-pass-prefix-sum-O(n)