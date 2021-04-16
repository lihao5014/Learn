-- （1）使用source E:/Github/Learn/MySQL/sqltest/students.sql命令来读取文件中的sql语句并执行。
-- （2）使用mysql –uroot –p -Dtestdb < test.sql命令来读取文件中的sql语句并执行。

#MySQL和SQLite数据库的sql语句中，字符串既可以用单引号'david'，也可以用双引号'david'
START TRANSACTION;
INSERT INTO students VALUES(9,'david',23);
INSERT INTO students VALUES(10,"susan",26);
COMMIT;
