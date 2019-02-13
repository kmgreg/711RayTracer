#include "Ray.h"

Ray::Ray(Vector3f lo, Vector3f d)
{
    pos = lo;
    pos.normalize();
    dir = d;
    dir.normalize();
}

Ray::~Ray()
{
    //dtor
}

Vector3f Ray::getdir(){
    return this->dir;
}

Vector3f Ray::getpos(){
    return this->pos;
}
