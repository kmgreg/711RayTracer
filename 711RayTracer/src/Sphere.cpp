#include "Sphere.h"
#include "Shape.h"
#include <cmath>
#include <algorithm>

using namespace Eigen;

Sphere::Sphere(float r, Vector3f loc)
{
    Shape();
    radius = r;
    center = loc;
    color << 0.3, 0.0, 0.5;
}

Sphere::~Sphere()
{
    //dtor
}

bool Sphere::checkcollision(Ray * tocheck, float& dist){
    //Scratchapixel version (thank you!)
    Vector3f L = tocheck->getpos() - center;
    float a = tocheck->getdir().dot(tocheck->getdir());
    float b = 2 * tocheck->getdir().dot(L);
    float c = L.dot(L) - (radius * radius);
    float disc = b*b - (4 * a * c);
    if (disc < 0)
        return false;
    disc = std::sqrt(disc);
    float t1 = (-b + disc) / (2 * a);
    float t2 = (-b - disc) / (2 * a);
    if (t1 > t2)
        std::swap(t1,t2);
    if (t1 < 0){
        t1 = t2;
        if (t1 < 0)
            return false;
    }
    dist = t1;
    return true;
}

Shape * Sphere::tform(Matrix4f touse){
    Vector4f n;
    n << center, 1.0;
    n = touse * n;
    Vector3f vec;
    vec << n[0], n[1], n[2];
    vec.normalize();
    Sphere * td = new Sphere(radius, vec);
    return td;
}

Vector3f Sphere::getnorm(Vector3f hitp){
    return hitp - this->center;
}
