--��test.db���ݿ��е����������ı��浽sql�ļ���

PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "students"(id integer,name string,age int);
INSERT INTO students VALUES(1,'amy',25);
INSERT INTO students VALUES(2,'lisa',26);
INSERT INTO students VALUES(3,'bob',23);
INSERT INTO students VALUES(4,'kevin',24);
INSERT INTO students VALUES(5,'jorden',24);
INSERT INTO students VALUES(6,'james',27);
INSERT INTO students VALUES(8,'david',23);
INSERT INTO students VALUES(9,'susan',26);
COMMIT;