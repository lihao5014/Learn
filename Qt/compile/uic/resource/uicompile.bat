@echo off
echo=
echo ---compile *.ui to ui_*.h header---
uic mainwindow.ui -o ui_mainwindow.h
echo ---ui compile end---