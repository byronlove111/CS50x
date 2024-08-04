SELECT m.title AS "Movie Title", r.rating AS "Rating" FROM movies m JOIN ratings r ON m.id = r.movie_id WHERE m.year = 2010 AND r.rating IS NOT NULL ORDER BY r.rating DESC, m.title ASC;
