@echo off
echo ---export testdb all table---
mysqldump -u root -p123456 testdb > test.sql
