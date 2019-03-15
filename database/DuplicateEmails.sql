-- Source : https://leetcode.com/problems/duplicate-emails/
-- Author : Mading
-- Date   : 2019-03-15

/********************************************************************************** 
*  182. Duplicate Emails [Easy]
-- Write a SQL query to find all duplicate emails in a table named Person.

-- +----+---------+
-- | Id | Email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
-- For example, your query should return the following for the above table:

-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+
*               
**********************************************************************************/


# Mysql
# Write your MySQL query statement below

#193 ms, faster than 59.39% of MySQL 
SELECT Email 
FROM Person
GROUP BY Email 
HAVING COUNT(Email)>1;



