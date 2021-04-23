@echo off
echo ---export paradigmdb to paradigm.sql---
mysqldump -u root -p123456 paradigmdb > paradigm.sql
