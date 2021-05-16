@echo off
echo=
echo ---compile *.qrc to source qrc_*.cpp---
rcc -binary resource.qrc -o resource.rcc
echo ---ui compile end---