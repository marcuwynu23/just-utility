.mode column
.header ON

CREATE TABLE IF NOT EXISTS USER(
    id INT PRIMARY KEY,
    name VARCHAR(20),
    age INT
);


.schema 
-- INSERT INTO USER VALUES(1,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(2,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(3,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(4,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(5,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(6,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(7,"Mark Wayne B. Menorca",23);
-- INSERT INTO USER VALUES(8,"Mark Wayne B. Menorca",23);


SELECT * FROM USER;