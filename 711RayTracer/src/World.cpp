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
    sc1 << 5.7, 0.7, 3.8;
    geoset.push_back(new Sphere(0.2, sc1));

    //Far
    Vector3f sc2;
    sc2 << 4.5, 0.4, 4.4;
    geoset.push_back(new Sphere(0.2, sc2));

    //Closer to origin
    Vector3f a; //(far left)
    Vector3f b; //(far right)
    Vector3f c; //(Near left)
    Vector3f d; //(Near right)

    a << 0.25, 0.1, 0.25;
    b << 5.98, 0.1, 0.25;
    c << 0.25, 0.1, 6.53;
    d << 5.98, 0.1, 6.53;

    geoset.push_back(new Triangle(a,b,c));

    //further away
    geoset.push_back(new Triangle(b,c,d));

}


World::~World()
{
    //dtor
}

std::vector<Shape * > World::getshapes(){
    return geoset;
}
