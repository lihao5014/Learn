@echo off
echo=
echo "[usage]: backupdb.bat {export|import}"
echo=

set cmd=%1
if "%cmd%" == "export" (
	echo ---export database to *.sql file---
	mysqldump -u root -p123456 classdb > classdb.sql
	exit /b
)

if "%cmd%" == "import" (
	echo ---import data from *.sql file to database---
	mysql -uroot -p123456 -Dclassdb <  classdb.sql
	exit /b
)

echo ---parameter is error---