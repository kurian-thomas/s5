CREATE TABLE animals (id mediumint(9) 
NOT NULL AUTO_INCREMENT, 
name char(30) NOT NULL, 
PRIMARY KEY (`id`));

CREATE TABLE animal_count (animals int);

CREATE TRIGGER increment_animal 
AFTER INSERT ON animals 
FOR EACH ROW 
UPDATE animal_count SET animal_count.animals = animal_count.animals+1;
