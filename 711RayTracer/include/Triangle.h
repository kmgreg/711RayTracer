#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Eigen>
#include "Shape.h"

using namespace Eigen;

class Triangle : public Shape
{
    Vector3f a;
    Vector3f b;
    Vector3f c;
    public:
        Triangle(Vector3f pointa, Vector3f
                pointb, Vector3f pointc);
        virtual ~Triangle();
        bool checkcollision(Ray * tocheck, float& dist);
        Shape * tform(Matrix4f touse);
        Vector3f getnorm(Vector3f hitp);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // TRIANGLE_H
