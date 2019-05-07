#include "Light.h"

Light::Light(Vector3f lp, Vector3f lc)
{
    this->pos = lp;
    this->colr = lc;
}

Light::~Light()
{
    //dtor
}

Vector3f Light::getcol(){
    return this->colr;
}

Vector3f Light::getpos(){
    return this->pos;
}
