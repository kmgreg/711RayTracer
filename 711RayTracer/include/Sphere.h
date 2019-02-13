#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include <Eigen/Dense>

using namespace Eigen;

class Sphere : public Shape
{
    float radius;
    Vector3f center;
    public:
        Sphere(float r, Vector3f loc);
        virtual ~Sphere();
        bool checkcollision(Ray * tocheck);
        Shape * tform(Matrix4f touse);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // SPHERE_H
