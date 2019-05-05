#include "World.h"

#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"

#include <vector>

using namespace Eigen;

World::World()
{
    //Will make more robust later
    //Near
    Vector3f sc1;
    sc1 << -.1, 0, .35;
    geoset.push_back(new Sphere(0.2, sc1));

    //Far

    Vector3f sc2;
    sc2 << .2, -.3, .8;
    geoset.push_back(new Sphere(.3, sc2));
    //Closer to origin
    Vector3f a; //(far left)
    Vector3f b; //(far right)
    Vector3f c; //(Near left)
    Vector3f d; //(Near right)

    a << -2, -1, .1;
    b << 3,  -1, .1;
    c << 3,  -1, 4;
    d << -2, -1, 4;

    geoset.push_back(new Triangle(a,b,c));

    //further away
    geoset.push_back(new Triangle(a,d,c));

}


World::~World()
{
    //dtor
}

std::vector<Shape * > World::getshapes(){
    return geoset;
}
