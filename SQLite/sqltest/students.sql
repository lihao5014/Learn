--使用.read students.sql命令来读取文件中的sql语句并执行。

PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
INSERT INTO students VALUES(8,'david',23);
INSERT INTO students VALUES(9,'susan',26);
COMMIT;
