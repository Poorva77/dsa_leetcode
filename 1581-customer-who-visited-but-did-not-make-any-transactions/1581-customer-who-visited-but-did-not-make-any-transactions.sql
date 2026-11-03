#keywords to use - JOIN, WHERE, COUNT
#whenever we use aggregate functions(SUM,COUNT,MAX, MIN,AVG), we have to use "GROUP BY" KEYWORD
SELECT v.customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits v LEFT JOIN Transactions t ON v.visit_id=t.visit_id WHERE t.transaction_id is NULL
GROUP BY v.customer_id