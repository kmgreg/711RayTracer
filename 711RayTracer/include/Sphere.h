#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include <Eigen>

using namespace Eigen;

class Sphere : public Shape
{
    float radius;
    Vector3f center;
    public:
        Sphere(float r, Vector3f loc);
        virtual ~Sphere();
        bool checkcollision(Ray * tocheck, float& dist);
        Shape * tform(Matrix4f touse);
        Vector3f getnorm(Vector3f hitp);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // SPHERE_H
