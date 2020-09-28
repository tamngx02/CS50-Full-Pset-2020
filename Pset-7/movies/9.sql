SELECT names
FROM(SELECT DISTINCT people.id, people.name AS names
	FROM people INNER JOIN stars ON people.id = stars.person_id
	INNER JOIN movies ON stars.movie_id = movies.id
	WHERE movies.year = 2004
	ORDER BY people.birth);

SELECT COUNT(names)
FROM(SELECT DISTINCT people.id, people.name AS names
	FROM people INNER JOIN stars ON people.id = stars.person_id
	INNER JOIN movies ON stars.movie_id = movies.id
	WHERE movies.year = 2004
	ORDER BY people.birth);
