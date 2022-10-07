@echo off
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