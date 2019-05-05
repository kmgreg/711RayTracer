#ifndef LIGHT_H
#define LIGHT_H

#include <Eigen>

using namespace Eigen;
class Light
{
    Vector3f pos;
    Vector3f colr;
    public:
        Light();
        virtual ~Light();

    protected:

    private:
};

#endif // LIGHT_H
