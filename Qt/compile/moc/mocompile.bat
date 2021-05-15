@echo off
echo=
echo ---compile qt moc *.h to *.cpp---
moc sample.h -o moc_sample.cpp
echo ---moc compile end---