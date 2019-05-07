#include "GridIll.h"

#include <math.h>

Vector2f GridIll::touv(Vector3f pos){
    //we will ignore y
    Vector3f fromorig = pos - this->lr;
    Vector2f uvpt;
    uvpt << fromorig[0]/this->xlen, fromorig[2]/this->zlen;
    return uvpt;
}

GridIll::GridIll()
{
    //ctor
}

GridIll::~GridIll()
{
    //dtor
}

Vector3f GridIll::illuminate(Intersection* i)
{
    Vector2f coords = touv(i->pt);
    int c = (int) (coords[0] * this->numchk) + 1;
    int r = (int) (coords[1] * this->numchk) + 1;

    if (c % 2 == 0){
        if (r % 2 == 0)
            return this->cola;
        else
            return this->colb;
    }
    else{
        if (r % 2 == 0)
            return this->colb;
        else
            return this->cola;
    }
}

void GridIll::setcols(Vector3f ca, Vector3f cb)
{
    this->cola = ca;
    this->colb = cb;
}

void GridIll::setcrnr(Vector3f lr, Vector3f ul)
{
    this->lr = lr;
    this->tl = ul;

    Vector3f diffs = ul - lr;
    this->xlen = std::abs(diffs[0]);
    this->zlen = std::abs(diffs[2]);
}

void GridIll::setchk(float csize)
{
    this->chksize = csize;
    this->numchk = (int) (1.0 / csize);
}

