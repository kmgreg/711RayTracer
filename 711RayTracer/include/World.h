#ifndef WORLD_H
#define WORLD_H

#include "Shape.h"
#include <vector>

class World
{
    std::vector<Shape *> geoset;
    public:
        World();
        virtual ~World();
        std::vector<Shape *> getshapes();
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    protected:

    private:
};

#endif // WORLD_H
