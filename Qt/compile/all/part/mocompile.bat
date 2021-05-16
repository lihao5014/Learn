@echo off
echo=
echo ---compile qt moc *.h to moc_*.cpp---
moc mainwindow.h -o moc_mainwindow.cpp
echo ---moc compile end---