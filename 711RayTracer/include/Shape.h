#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "IllModel.h"
#include "Intersection.h"
#include <Eigen>

using namespace Eigen;
class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual bool checkcollision(Ray * tocheck, float& dist);
        virtual Shape * tform(Matrix4f touse);
        Vector3f getcolor(Intersection * ix);
        void setambi(Vector3f am);
        void setspec(Vector3f sp);
        void setilm(IllModel * ilm);
        Vector3f getambi();
        Vector3f getspec();
        virtual Vector3f getnorm(Vector3f hitp);
        float kr;
        float kt;
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:
    Vector3f color;
    Vector3f ambi;
    Vector3f spec;
    IllModel * ilmdl;
    private:
};

#endif // SHAPE_H
