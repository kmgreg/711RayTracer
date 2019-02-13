#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include <Eigen/Dense>

using namespace Eigen;
class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual bool checkcollision(Ray * tocheck);
        virtual Shape * tform(Matrix4f touse);
        Vector3f getcolor();
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:
    Vector3f color;

    private:
};

#endif // SHAPE_H
