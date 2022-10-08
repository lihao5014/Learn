@echo off

set cmd=%1

if "%cmd%" == "clean" (
	del /Q /f bin\main.exe
	exit /b
)

if "%cmd%" == "run" (
	bin\main.exe
	exit /b
)

echo set GOPATH environment variable
set GOPATH_BACKUP=%GOPATH%
set GOPATH=%GOPATH%;%cd%
echo GOPATH = %GOPATH%

echo ---compile main.go---
echo=
go build -o bin\main.exe src\main.go

echo ---running---
echo=
bin\main.exe
echo=

echo recover GOPATH environment variable
set GOPATH=%GOPATH_BACKUP%