# Write your MySQL query statement below
#keyword- HAVING
SELECT e1.name FROM Employee e1 INNER JOIN Employee e2 ON e1.Id=e2.managerId GROUP BY e2.managerId 
HAVING COUNT(e2.managerId)>=5
#if grp by nahi use krenge toh name would be written 5 times - john john john..