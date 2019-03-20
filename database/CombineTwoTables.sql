-- Source : https://leetcode.com/problems/big-countries/
-- Author : Mading
-- Date   : 2019-03-20

/********************************************************************************** 
*  175. Combine Two Tables [easy]

-- Table: Person
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | PersonId    | int     |
-- | FirstName   | varchar |
-- | LastName    | varchar |
-- +-------------+---------+
-- PersonId is the primary key column for this table.

-- Table: Address
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | AddressId   | int     |
-- | PersonId    | int     |
-- | City        | varchar |
-- | State       | varchar |
-- +-------------+---------+
-- AddressId is the primary key column for this table.
 
-- Write a SQL query for a report that provides the following information for each person
-- in the Person table, regardless if there is an address for each of those people:
-- FirstName, LastName, City, State
*               
**********************************************************************************/

# 219 ms, faster than 54.31% of MySQL
# Write your MySQL query statement below
select A.FirstName, A.LastName, B.City, B.State from Person as A 
left join Address as B on A.PersonId = B.PersonId; 





