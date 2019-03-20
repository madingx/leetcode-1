-- Source : https://leetcode.com/problems/second-highest-salary/
-- Author : Mading
-- Date   : 2019-03-20

/********************************************************************************** 
*  176. Second Highest Salary [Easy]
-- Write a SQL query to get the second highest salary from the Employee table.

-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+

-- For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.
-- +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | 200                 |
-- +---------------------+
*               
**********************************************************************************/


# Mysql
# Write your MySQL query statement below

#Runtime: 147 ms, faster than 25.61% of MySQL
select (
  select distinct Salary from Employee order by Salary Desc limit 1 offset 1
)as SecondHighestSalary


#Runtime: 130 ms, faster than 74.62% of MySQL
SELECT max(Salary) as SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(Salary) FROM Employee)
