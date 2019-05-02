#include <iostream>

#include "World.h"
#include "Camera.h"
#include <Eigen/Dense>
#include "Ray.h"
#include "Sphere.h"
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
    cam->captureworld(*sampl);
    return 0;
}
