SELECT names
FROM(SELECT DISTINCT people.id, people.name AS names
	FROM people INNER JOIN directors ON people.id = directors.person_id
	INNER JOIN movies ON directors.movie_id = movies.id
	INNER JOIN ratings ON directors.movie_id = ratings.movie_id
	WHERE ratings.rating >= 9.0);

SELECT COUNT(names)
FROM(SELECT DISTINCT people.id, people.name AS names
	FROM people INNER JOIN directors ON people.id = directors.person_id
	INNER JOIN movies ON directors.movie_id = movies.id
	INNER JOIN ratings ON directors.movie_id = ratings.movie_id
	WHERE ratings.rating >= 9.0);
