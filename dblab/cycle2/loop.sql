
CREATE TABLE l(id INT, name VARCHAR(10));
INSERT INTO l VALUES(1, 'kurian'),(2, 'Augustine');

DELIMITER //

CREATE PROCEDURE  fn()
BEGIN
	DECLARE x  INT;
 	DECLARE str  VARCHAR(255);
 
 	SET x = 1;
 	SET str =  '';
 
 	WHILE x  < 6 DO
 		SET  str = CONCAT(str,x,',');
 		SET  x = x + 1; 
 	END WHILE;
 
 SELECT str;
END //

CALL fn()
