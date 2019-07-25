-- Source : https://leetcode.com/problems/swap-salary/
-- Author : Mading
-- Date   : 2019-07-25

/********************************************************************************** 
-- 627. Swap Salary [Easy]
-- SQL Schema
-- Given a table salary, such as the one below, that has m=male and f=female values.
-- Swap all f and m values (i.e., change all f values to m and vice versa) with a 
-- single update statement and no intermediate temp table.

-- Note that you must write a single update statement, 
-- DO NOT write any select statement for this problem.
 

-- Example:

-- | id | name | sex | salary |
-- |----|------|-----|--------|
-- | 1  | A    | m   | 2500   |
-- | 2  | B    | f   | 1500   |
-- | 3  | C    | m   | 5500   |
-- | 4  | D    | f   | 500    |
-- After running your update statement, the above salary table should have the following rows:
-- | id | name | sex | salary |
-- |----|------|-----|--------|
-- | 1  | A    | f   | 2500   |
-- | 2  | B    | m   | 1500   |
-- | 3  | C    | f   | 5500   |
-- | 4  | D    | m   | 500    |
*               
**********************************************************************************/


-- Write your MySQL query statement below

-- 161 ms, faster than 45.24% of MySQL, Memory Usage: N/A
update salary set sex = (case sex when'm' then 'f' when 'f' then 'm' end);
