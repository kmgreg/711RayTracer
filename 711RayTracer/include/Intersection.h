#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <Eigen>
#include <vector>
#include "Light.h"

using namespace Eigen;
using namespace std;

class Intersection
{
    public:
        Intersection();
        virtual ~Intersection();
        Vector3f pt;
        Vector3f norm;
        Vector3f incom;
        Vector3f reflex;
        vector<Light *> litlist;

    protected:

    private:
};

#endif // INTERSECTION_H
