@echo off

rem 获取批处理脚本运行时，用户输入的第一个命令参数
set cmd=%1

rem exit /b退出批处理脚本，而不是整个命令行终端
if "%cmd%" == "clean" (
	rmdir /Q /S build\debug build\release
	del /Q /f build\Makefile build\Makefile.Debug build\Makefile.Release build\.qmake.stash bin\*
	exit /b
)

rem 切换到build目录下执行build.bat脚本，当build.bat脚本执行完以后，再切换回原来的目录中
cd  build && build.bat && cd ..