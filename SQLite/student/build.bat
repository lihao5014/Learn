@echo off
set cmd=%1
if "%cmd%" == "clean" (
	del /Q /s main.exe class.db
	exit /b
)

cl main.c && del /f main.obj && main.exe