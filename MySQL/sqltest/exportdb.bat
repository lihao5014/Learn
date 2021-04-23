@echo off
echo ---export testdb to test.sql---
mysqldump -u root -p123456 testdb > test.sql
