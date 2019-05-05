#include "Shape.h"
#include <iostream>

Shape::Shape()
{

}

Shape::~Shape()
{
    //dtor
}

Shape * Shape::tform(Matrix4f touse){
    return nullptr;
}

bool Shape::checkcollision(Ray * tocheck, float& dist){
    return false;
}

Vector3f Shape::getcolor(){
    return color;
}

