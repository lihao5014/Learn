@echo off
echo=
echo "[usage]: backup.bat {export|import}"
echo=

set cmd=%1
if "%cmd%" == "export" (
	sqlite3 exercises30.db .dump > exercises30_db.sql
	exit /b
)

if "%cmd%" == "import" (
	sqlite3 exercises30.db < exercises30_db.sql
	exit /b
)

echo ---parameter is error---