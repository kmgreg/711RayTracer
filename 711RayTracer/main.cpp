#include <iostream>

#include "World.h"
#include "Camera.h"
#include <Eigen>
#include "Ray.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Shape.h"
#include <vector>

using namespace std;
using namespace Eigen;

int main()
{


    World * sampl = new World();
    Vector3f lookat;
    lookat << 0, 0, -1;
    Vector3f up;
    up << 0, 1, 0;
    Vector3f pos;
    pos << 3, 0, 1;
    Camera * cam = new Camera(lookat, up, pos);
    cam->captureworld(sampl);

    /*
    Vector3f a,b,c;

    a << 0,0,10;
    b << 100, 0, 10;
    c << 100, 100, 10;

    Vector3f l,d;

    l << 1,0, 0;
    d << -1,0, 10;

    Ray * test = new Ray(l,d);
    Sphere * tr = new Sphere(1, a);

    if (tr->checkcollision(test))
        cout << "blah";

    */
    return 0;
}
