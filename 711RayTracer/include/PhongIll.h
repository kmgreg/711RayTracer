#ifndef PHONGILL_H
#define PHONGILL_H

#include <Eigen>
#include <vector>

#include "IllModel.h"
#include "Intersection.h"

using namespace Eigen;
using namespace std;
class PhongIll : public IllModel
{
    public:
        PhongIll();
        virtual ~PhongIll();
        void setparams(float ca, float cd, float cs, float ce);
        void setvecs(Vector3f am, Vector3f sp);
        Vector3f illuminate(Intersection * i);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    protected:

    private:
    float ka, kd, ks, ke;
    Vector3f ambi;
    Vector3f spec;
};

#endif // PHONGILL_H
