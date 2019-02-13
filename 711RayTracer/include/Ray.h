#ifndef RAY_H
#define RAY_H

#include <vector>
#include <Eigen/Dense>

using namespace Eigen;
class Ray
{
    Vector3f pos;
    Vector3f dir;
    public:
        Ray(Vector3f lo, Vector3f d);
        virtual ~Ray();
        Vector3f getpos();
        Vector3f getdir();
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // RAY_H
