@echo off
echo=
echo ---compile *.qrc to source *.cpp---
rcc resource.qrc -o qrc_resource.cpp
echo ---ui compile end---