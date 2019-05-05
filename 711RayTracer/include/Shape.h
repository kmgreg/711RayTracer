#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include <Eigen>

using namespace Eigen;
class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual bool checkcollision(Ray * tocheck, float& dist);
        virtual Shape * tform(Matrix4f touse);
        Vector3f getcolor();
        void setambi(Vector3f am);
        void setspec(Vector3f sp);
        void setphong(float pa,float pd,float ps,float pe,);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:
    Vector3f color;
    Vector3f ambi;
    Vector3f spec;
    float ka, kd, ks, ke;
    private:
};

#endif // SHAPE_H
