@echo off
rem sql脚本中使用了use classdb，所以-D classdb选项可以忽略
mysql -u root -p123456 < createtable.sql