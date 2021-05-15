@echo off
echo=
echo ---compile *.qrc to source qrc_*.cpp---
rcc icon.qrc -o qrc_icon.cpp
echo ---ui compile end---