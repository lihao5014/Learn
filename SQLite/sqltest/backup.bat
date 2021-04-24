@echo off
echo=
echo "[usage]: backupdb.bat {export|import}"
echo=

set cmd=%1
if "%cmd%" == "export" (
	sqlite3 test.db .dump > testdb.sql
	exit /b
)

if "%cmd%" == "import" (
	sqlite3 test.db < testdb.sql
	exit /b
)

echo ---parameter is error---
