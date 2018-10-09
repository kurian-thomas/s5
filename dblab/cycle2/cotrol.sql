SELECT IF (1=1,'TRUE','FALSE');

SELECT 
    id,name
FROM
    HUMAN
ORDER BY (CASE
    WHEN name IS NULL  THEN id
    ELSE name
END);

SELECT IF(id > 1 && id<4,'cs','ec') FROM HUMAN;


UPDATE HUMAN
SET
grade=(CASE 
		WHEN mark>90 THEN 'A+'
		WHEN mark=90 THEN 'A'
		WHEN mark<45 THEN 'F'
		ELSE 'B'
		END);



 CALL GetAll();



CALL l();
 DELIMITER //
	CREATE PROCEDURE lpp()
		BEGIN
		DECLARE to INT DEFAULT 0;
 		WHILE to < 100 
 		BEGIN
 		select to;
 		SET to=to+2;
		
		END //	

CALL lpp();