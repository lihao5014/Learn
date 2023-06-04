@echo off

set project=%1

if "%project%" == "clean" (
	echo "---clean whole solution---"
	echo=
	cd libsort && call setup.bat clean && cd ..
	cd libsearch && call setup.bat clean && cd ..
	cd test && call setup.bat clean && cd ..
	exit /b
)

if "%project%" == "libsort" (
	echo "---compile libsort project---"
	echo=
	cd libsort && call setup.bat && cd ..
	exit /b
)

if "%project%" == "libsearch" (
	echo "---compile libsearch project---"
	echo=
	cd libsearch && call setup.bat && cd ..
	exit /b
)

if "%project%" == "test" (
	echo "---compile test project---"
	echo=
	cd test && call setup.bat && cd ..
	exit /b
)

if "%project%" == "run" (
	echo "---running test.exe---"
	echo=
	cd test && call setup.bat run && cd ..
	exit /b
)


echo "---compile total solution---"
echo=
echo "---compile libsort---"
cd libsort && call setup.bat && cd ..
echo=

echo "---compile libsearch---"
cd libsearch && call setup.bat && cd ..
echo=

echo "---compile test project---"
cd test && call setup.bat && cd ..