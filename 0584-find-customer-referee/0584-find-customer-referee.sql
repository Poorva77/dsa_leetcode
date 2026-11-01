# Write your MySQL query statement below
SELECT name FROM Customer WHERE referee_id!='2' OR referee_id is NULL 
#by default sql me null values are not returned so we have to specially use "is NULL"