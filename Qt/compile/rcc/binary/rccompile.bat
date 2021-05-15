@echo off
echo=
echo ---compile *.qrc to binary *.rcc---
rcc -binary icon.qrc -o icon.rcc
echo ---ui compile end---