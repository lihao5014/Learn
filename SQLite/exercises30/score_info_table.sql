PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE score_info_table(id int,name varchar(16),subject varchar(16),score int,check(score >=0 and score <=100));
INSERT INTO score_info_table VALUES(1,'王小凤','语文',88);
INSERT INTO score_info_table VALUES(2,'张文华','语文',70);
INSERT INTO score_info_table VALUES(3,'徐雨秋','语文',92);
INSERT INTO score_info_table VALUES(1,'王小凤','数学',55);
INSERT INTO score_info_table VALUES(2,'张文华','数学',77);
INSERT INTO score_info_table VALUES(3,'徐雨秋','数学',77);
INSERT INTO score_info_table VALUES(1,'王小凤','英语',72);
INSERT INTO score_info_table VALUES(2,'张文华','英语',91);
INSERT INTO score_info_table VALUES(3,'徐雨秋','英语',93);
COMMIT;
