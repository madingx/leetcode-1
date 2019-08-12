# Random 随机


核心问题在于确定随机数的范围和权重，使得随机数等比例分布。


## [470. Implement Rand10 Using Rand7](/algorithms/cpp/implementRand10UsingRand7/ImplementRand10UsingRand7.cpp) **Medium**

>使用rand7()函数，制作一个rand10()函数，

使用公式： 7 * (rand7() - 1) + (rand7() - 1)  可以随机一个 1 - 49 的数，使用此公式来保证每个数的几率相同。
当结果大于40时，重新随机一次。


## [528. Random Pick with Weight](/algorithms/cpp/randomPickIndex/RandomPickwithWeight.cpp) **Medium**

>按照提供的权重，产生随机数

### 方法一
根据权重n将数字重复n次，然后随机，结果TLE。
### 方法二
1. 将权重处理为 w[i] = w[i] + w[i-1]
2. 随机一个范围为[0,w.back()]的数r。
3. 找到第一个不小于r的w[i]，返回i。 


## [497. Random Point in Non-overlapping Rectangles](/algorithms/cpp/randomPointinNon-overlappingRectangles/RandomPointinNon-overlappingRectangles.cpp) **Medium**

>提供若干不重复的矩形，随机一个在矩形范围内的点坐标。

### 方法一
先随机x，确定是否合法。再随机y，再确定是否合法。结果TLE。

### 方法二
1. 求解所有矩形面积。
2. 以面积为权重随机一个矩形。
3. 在矩形内随机x,y。
