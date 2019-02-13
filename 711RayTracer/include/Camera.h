#ifndef CAMERA_H
#define CAMERA_H
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include "World.h"


using namespace Eigen;

class Camera
{
    Vector3f lookat;
    Vector3f up;
    Vector3f pos;
    Matrix4f tra;
    public:
        Camera(Vector3f la, Vector3f u,
               Vector3f p);
        virtual ~Camera();
        void captureworld(World wld);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // CAMERA_H
