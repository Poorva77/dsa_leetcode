# Write your MySQL query statement below
#we want to find length of content so - use "CHAR_LENGTH" KEYWORD
SELECT tweet_id FROM Tweets WHERE CHAR_LENGTH(content)>15

#also - "LENGTH()" -> this keyword finds string ka length in BYTES
#"CHAR_LENGTH()" -> this keyword finds string ka length in CHAR