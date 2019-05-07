#ifndef GRIDILL_H
#define GRIDILL_H

#include "IllModel.h"
#include <Eigen>

using namespace Eigen;
class GridIll : public IllModel
{
    public:
        GridIll();
        virtual ~GridIll();
        Vector3f illuminate(Intersection * i);
        void setcols(Vector3f ca, Vector3f cb);
        void setcrnr(Vector3f lr, Vector3f ul);
        void setchk(float csize);
        void setconsts();
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    protected:

    private:
        Vector2f touv(Vector3f pos);
        Vector3f cola;
        Vector3f colb;
        Vector3f tl;
        Vector3f lr;
        //Calculated at runtime:
        float xlen;
        float zlen;

        float chksize;
        int numchk;
};

#endif // GRIDILL_H
