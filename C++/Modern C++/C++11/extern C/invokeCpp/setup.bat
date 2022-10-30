@echo off
echo=
echo "[usage]: setup.bat {clean|run|libMath|test}"
echo=

set cmd=%1

if "%cmd%" == "clean" (
	echo "setup.bat clean"
	cd test && build.bat clean && cd ..
	cd libMath && build.bat clean && cd ..
)

if "%cmd%" == "run" (
	echo "setup.bat run"
	cd test && build.bat run && cd ..
)

if "%cmd%" == "libMath" (
	echo "setup.bat libMath"
	cd libMath && build.bat && build.bat install && cd ..
)

if "%cmd%" == "test" (
	echo "setup.bat test"
	cd test && build.bat && cd ..
)

if "%cmd%" == "" (
	cd libMath && build.bat && cd ..
	cd test && echo %cd% && build.bat && build.bat run && cd ..
)
