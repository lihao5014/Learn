@echo off
echo ---export  classdb to  classdb.sql---
mysqldump -u root -p123456 classdb > classdb.sql
