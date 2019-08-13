# UnionFind 随机


[并查集（Union-Find）](https://blog.csdn.net/guoziqing506/article/details/78752557)是解决动态连通性问题的一类非常高效的数据结构。

主要分为两个步骤:
find: 为每一个点赋值
 1 2 3 4 5

union: 将两个同类点合并
 1 1 3 3 3 

## [200. Number of Islands](/algorithms/cpp/numberofIslands/NumberofIslands.cpp) **Medium**

>地图上0和1分别代表海洋和岛屿，统计岛屿的数量

对于每个1记一次数，并递归处理每一个相邻点，使得一个岛屿只能被记一次数


