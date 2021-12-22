WITH L2 (score, rnk) AS  (
    SELECT L1.score, ROW_NUMBER() OVER (ORDER BY L1.score DESC) 
    FROM (SELECT DISTINCT score FROM Scores) AS L1)
SELECT Scores.score AS Score, rnk AS `Rank` 
FROM L2 JOIN Scores ON L2.score = Scores.score ORDER BY Score DESC;