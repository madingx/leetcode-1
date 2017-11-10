// Source : https://leetcode.com/problems/hamming-distance/description/
// Author : Mading
// Date   : 2017-11-10

/*************************************************************************************** 
 * 461. Hamming Distance
 * 
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * Example:
 * Input: x = 1, y = 4
 *  
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are different.
 * 
 ***************************************************************************************/

/*
*  Solution 1
*

*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        unsigned int c =0 ;
        for (c =0; n; ++c)
        {
            n &= (n -1) ; // 清除最低位的1
            // 求二进制数中有几个1    https://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
        }
        return c ;
    }


};
