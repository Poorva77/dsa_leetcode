# Write your MySQL query statement below

#see output me we have a new column name - "id" so whenever we have to rename a column name/table name in sql then we use - "AS" KEYWORD

#also the result is stored in ascending order so- we use "ORDER BY" KEYWORD here

#for unique (we want only distinct values to be returned)- use "DISTINCT" KEYWORD
SELECT DISTINCT author_id AS id FROM Views WHERE author_id=viewer_id ORDER BY id;