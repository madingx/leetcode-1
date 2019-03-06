-- Source : https://leetcode.com/problems/consecutive-numbers/
-- Author : Mading
-- Date   : 2019-03-06

/********************************************************************************** 
* 
-- Write a SQL query to find all numbers that appear at least three times consecutively.

-- +----+-----+
-- | Id | Num |
-- +----+-----+
-- | 1  |  1  |
-- | 2  |  1  |
-- | 3  |  1  |
-- | 4  |  2  |
-- | 5  |  1  |
-- | 6  |  2  |
-- | 7  |  2  |
-- +----+-----+
-- For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.

-- +-----------------+
-- | ConsecutiveNums |
-- +-----------------+
-- | 1               |
-- +-----------------+
*               
**********************************************************************************/


# Mysql
# Write your MySQL query statement below

#Runtime: 334 ms, faster than 57.17% of MySQL 
select DISTINCT(l1.Num) as ConsecutiveNums from Logs l1, Logs l2, Logs l3 
    where l1.Id+1=l2.Id and l1.Id+2=l3.Id and l1.Num=l2.Num and l1.Num=l3.Num; 


#Runtime: 351 ms, faster than 35.86% of MySQL
SELECT DISTINCT l1.Num ConsecutiveNums FROM Logs l1
    JOIN Logs l2 ON l1.Id = l2.Id - 1
    JOIN Logs l3 ON l1.Id = l3.Id - 2
    WHERE l1.Num = l2.Num AND l2.Num = l3.Num;


#Runtime: 251 ms, faster than 96.16% of MySQL
SELECT DISTINCT Num ConsecutiveNums FROM (
    SELECT Num,@count := IF(@pre = Num,@count + 1,1) As n,@pre := Num
    FROM Logs,(SELECT @count := 0,@pre := -1) As init
    ) As t WHERE t.n >= 3;




