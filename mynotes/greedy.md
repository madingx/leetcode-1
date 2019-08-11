# Greedy 贪心算法总结

[贪婪算法(贪心算法)](https://www.jianshu.com/p/fede80bad3f1)是指在对问题进行求解时，在每一步选择中都采取最好或者最优(即最有利)的选择，从而希望能够导致结果是最好或者最优的算法。

贪婪算法所得到的结果往往不是最优的结果(有时候会是最优解)，但是都是相对近似(接近)最优解的结果。




## [763. Partition Labels](/algorithms/cpp/partitionLabels/PartitionLabels.cpp) **Medium**
======
将字符串进行切割，使得每个字母只出现在一个substring。
1. 只要统计好每个字母最后出现的位置map[i]。
2. 然后使用贪心算法最小化子串：
    1. 从左至右遍历字母，
    2. 对于字母i如果map[i]大于当前边界，就将边界j扩大到map[i]，
    3. 如果已经遍历到当前边界j，则切割此子串。




## [861. Score After Flipping Matrix](/algorithms/cpp/scoreAfterFlippingMatrix/ScoreAfterFlippingMatrix.cpp) **Medium**
******
一个只包含0和1的矩阵，每次可以翻转一行或1列，若干次操作后返回矩阵的最大值。
将每行视为一个二进制数，将每行相加得到矩阵值。

由于每行是一个二进制数，则重点为让每行最高位为1。


