#include "bird.h"
#include "fish.h"
#include "canidae.h"
#include "felidae.h"

int main()
{
	Animal animal("animal",2);
	animal.move();
	
	Bird bird("bird",1);
	bird.move();
	
	Fish fish("fish",0.5);
	fish.move();
	
	Canidae canidae("canidae",3);
	canidae.move();
	
	Felidae felidae("felidae",4);
	felidae.move();
	
	return 0;
}