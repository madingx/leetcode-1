# // Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
# // Author : Mading
# // Date   : 2019-02-26
# /********************************************************************************** 
# * 
# * There are two sorted arrays nums1 and nums2 of size m and n respectively.
# * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
# * You may assume nums1 and nums2 cannot be both empty.

# * Example 1:
# * nums1 = [1, 3]
# * nums2 = [2]
# * The median is 2.0

# * Example 2:
# * nums1 = [1, 2]
# * nums2 = [3, 4]
# * The median is (2 + 3)/2 = 2.5
# *               
# **********************************************************************************/

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 有一个数组为空
        if len(nums1) == 0 and len(nums2) > 0:
            return nums2[int(len(nums2)/2)] if len(nums2) % 2 == 1 else (nums2[int(len(nums2)/2)-1]+nums2[int(len(nums2)/2)])/2.0
        if len(nums2) == 0 and len(nums1) > 0:
            return nums1[int(len(nums1)/2)] if len(nums1) % 2 == 1 else (nums1[int(len(nums1)/2)-1]+nums1[int(len(nums1)/2)])/2.0

        # 保证n > m
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        m, n = len(nums1), len(nums2)
        imin, imax = 0, m
        '''
        用i,j分别将两个数组随机分成两部分(这里取中间)，nums1长度m,nums2为n
        分别为nums1_left,nums1_right,nums2_left,nums2_right
        我们再将nums1_left,nums2_left归为nums_left
             将nums1_right,nums2_right归为nums_right
             
        只要我们确保：
            1.len(nums_left) = len(nums_right)
            2.max(nums_left) <= min(nums_left)
            
        那么中值就为:(max(nums_left)+min(nums_left))/2
        
        为了满足条件1，需使得i+j = m-i+n-j+ 则 j = (m+n+1)/2
        为了满足条件2，需使得：
            nums1[i-1] <= nums2[j]
            nums2[j-1] <= nums1[i]
            
        所以，我们只要找到满足条件的i的位置即可
        
        '''
        while imin <= imax:
            i = int((imin+imax)/2)
            j = int((m+n+1)/2) - i
            # i太小增加i
            if i < m and j > 0 and nums1[i] < nums2[j-1]:
                imin = i + 1
            # i太大减少i
            elif i > 0 and j < n and nums1[i-1] > nums2[j]:
                imax = i-1
            else:
                # i或j为边界值
                if (i == 0):
                    max_left = nums2[j-1]
                elif (j == 0):
                    max_left = nums1[i-1]
                else:
                    max_left = nums1[i-1] if nums1[i-1] > nums2[j-1] else nums2[j-1]
                break
        
        # 数组大小和奇数
        if (m+n) % 2 == 1:
            return max_left
        if i == m:
            min_right = nums2[j]
        elif j == n:
            min_right = nums1[i]
        else:
            min_right = nums1[i] if nums1[i] < nums2[j] else nums2[j]
        return (max_left+min_right)/2.0