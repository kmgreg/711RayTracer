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

Vector3f Shape::getcolor(Intersection * ix){
    return this->ilmdl->illuminate(ix);
}

Vector3f Shape::getambi(){
    return this->ambi;
}

Vector3f Shape::getspec(){
    return this->spec;
}

void Shape::setambi(Vector3f am){
    this->ambi = am;
}

void Shape::setspec(Vector3f sp){
    this->spec = sp;
}

void Shape::setilm(IllModel * ilm){
    this->ilmdl = ilm;
}

Vector3f Shape::getnorm(Vector3f hitp){
    Vector3f tr;
    tr << 0,0,0;
    return tr;
}
