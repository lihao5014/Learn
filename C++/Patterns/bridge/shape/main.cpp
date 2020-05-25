#include "circle.h"
#include "redCircle.h"
#include "greenCircle.h"
#include <cstdlib>

static void myFree(void* p);

int main()
{
	DrawAPI* drawAPI = new RedCircle();
	Shape* circle = new Circle(10,4,5,drawAPI);
	circle->display();
	circle->draw();
	myFree(drawAPI);

	drawAPI = new GreenCircle();
	circle->setDrawAPI(drawAPI);
	circle->display();
	circle->draw();
	
	try{
		drawAPI->drawRectangle(4,5,0,0);
	}catch(const char* e){
		std::cout<<e<<std::endl;
	}catch(char* e){
		std::cout<<e<<std::endl;
	}

	myFree(drawAPI);
	myFree(circle);
	
	return 0;
}

void myFree(void* p)
{
	if(p != nullptr)
		free(p);
}