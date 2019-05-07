#ifndef CAMERA_H
#define CAMERA_H
#include <Eigen>
#include "World.h"



using namespace Eigen;

class Camera
{
    Vector3f lookat;
    Vector3f up;
    Vector3f pos;
    Matrix4f tra;
    World * wld;
    public:
        Camera(Vector3f la, Vector3f u,
               Vector3f p);
        virtual ~Camera();
        void captureworld(World * wld);
        Vector3f getcolor(Ray * r, int recdepth);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // CAMERA_H
