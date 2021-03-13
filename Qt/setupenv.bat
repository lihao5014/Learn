@echo off
rem 设置Qt MSVC64位或者MSVC62位编译运行环境。
rem 如果windows cmd执行的批处理脚本路径中带有空格，那么就需要将命令加上双引号。
echo [usage]: setupenv.bat x86 or setupenv.bat x64
echo=
set cmd=%1
if "%cmd%" == "x86" (
	D:\Qt5.12\5.12.0\msvc2017\bin\qtenv2.bat
	"D:\Visual Studio 2017\VC\Auxiliary\Build\vcvars32.bat"
	E:
	cd E:\Github\Learn\Qt
)

if "%cmd%" == "x64" (
	D:\Qt5.12\5.12.0\msvc2017_64\bin\qtenv2.bat
	"D:\Visual Studio 2017\VC\Auxiliary\Build\vcvars64.bat"
	E:
	cd E:\Github\Learn\Qt
)