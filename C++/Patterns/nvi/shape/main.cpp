#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main()
{
    Shape* shape = new Circle();
    shape->draw();
    if(shape != nullptr){
        delete shape;
        shape = nullptr;
    }
    
    shape = new Square;
    shape->draw();
    if(shape != nullptr){
        delete shape;
        shape = nullptr;
    }
    
    shape = new Rectangle;
    shape->draw();
    if(shape != nullptr){
        delete shape;
        shape = nullptr;
    }
    
    return 0;
}