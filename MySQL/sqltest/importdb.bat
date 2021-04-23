@echo off
echo ---import testdb from test.sql---
mysql -uroot -p123456 -Dtestdb < test.sql
echo=

echo ---execute students.sql to insert data---
mysql -uroot -p123456 -Dtestdb < students.sql