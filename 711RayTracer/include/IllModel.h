#ifndef ILLMODEL_H
#define ILLMODEL_H

#include <Eigen>
#include <vector>
#include "Intersection.h"

using namespace Eigen;
using namespace std;

class IllModel
{
    public:
        IllModel();
        virtual ~IllModel();
        virtual Vector3f illuminate(Intersection * i);
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    protected:

    private:
};

#endif // ILLMODEL_H
