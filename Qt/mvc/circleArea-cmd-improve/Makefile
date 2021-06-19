.PHONY:clean run

TARGET := circleArea.exe

$(TARGET):build/main.o build/calculatorUi.o build/calculatorModel.o build/calculator.o 
	g++ -o bin/$@ $^

build/main.o:main.cpp
	g++ -o $@ -c $< -I ./control

build/calculatorUi.o:view/calculatorUi.cpp
	g++ -o $@ -c $<

build/calculatorModel.o:model/calculatorModel.cpp
	g++ -o $@ -c $<

build/calculator.o:control/calculator.cpp
	g++ -o $@ -c $< -I ./view -I ./model

clean:
	del /f bin\* build\*

run:
	bin\$(TARGET)
