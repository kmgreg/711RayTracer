#ifndef LIGHT_H
#define LIGHT_H

#include <Eigen>

using namespace Eigen;
class Light
{
    Vector3f pos;
    Vector3f colr;
    public:
        Light(Vector3f lp, Vector3f lc);
        virtual ~Light();
        Vector3f getpos();
        Vector3f getcol();
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // LIGHT_H
