#include "Triangle.h"
#include <iostream>

using namespace Eigen;

Triangle::Triangle(Vector3f pointa, Vector3f
                pointb, Vector3f pointc)
{
    a = pointa;
    b = pointb;
    c = pointc;
    color << 0.9, 0.1, 0.0;
}

Triangle::~Triangle()
{
    //dtor
}

bool Triangle::checkcollision(Ray * tocheck){
    //Based on Wikipedia's version of
    //Moller-Trumbore

    float eps = 0.0000001;
    Vector3f e1,e2,h,s,q;
    float aa,ff,uu,vv;
    e1 = this->b - this->a;
    e2 = this->c - this->a;

    h = tocheck->getdir().cross(e2);
    aa = e1.dot(h);
    if (aa > -eps && aa < eps)
        return false;

    ff = 1.0/aa;
    s = tocheck->getpos() - this->a;
    uu = ff * (s.dot(h));
    if (uu < 0.0 || uu > 1.0)
        return false;

    q = s.cross(e1);
    vv = ff * (tocheck->getdir().dot(q));
    if (vv < 0.0 || uu + vv > 1.0)
        return false;

    float tt = ff * e2.dot(q);
    if (tt > eps)
    {
        return true;
    }
    else
        return false;


}

Shape * Triangle::tform(Matrix4f touse){
    Vector4f na;
    na << a, 1.0;
    Vector4f nb;
    nb << b, 1.0;
    Vector4f nc;
    nc << c, 1.0;

    na = touse * na;
    nb = touse * nb;
    nc = touse * nc;

    Vector3f ta;
    Vector3f tb;
    Vector3f tc;

    ta << na[0],na[1],na[2];
    tb << nb[0],nb[1],nb[2];
    tc << nc[0],nc[1],nc[2];

    //a.normalize();
    //tb.normalize();
    //tc.normalize();

    return new Triangle(ta,tb,tc);

}
