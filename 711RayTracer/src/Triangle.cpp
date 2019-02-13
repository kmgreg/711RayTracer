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
    //From scratchapixel version
    Vector3f n1 = b - a;
    Vector3f n2 = c - a;
    Vector3f bign = n1.cross(n2);

    float ndd = bign.dot(tocheck->getdir());
    if (ndd == 0)
        return false;

    float d = bign.dot(a);
    float t = (bign.dot(tocheck->getpos()) + d) / ndd;
    if (t < 0)
        return false;
    Vector3f p = tocheck->getpos() + t * tocheck->getdir();
    Vector3f c;

    Vector3f ega = b - a;
    Vector3f vpa = p - a;
    c = ega.cross(vpa);
    if (bign.dot(c) < 0)
        return false;

    Vector3f egb = c - b;
    Vector3f vpb = p - b;
    c = egb.cross(vpb);
    if (bign.dot(c) < 0)
        return false;

    Vector3f egc = a - c;
    Vector3f vpc = p - c;
    c = egc.cross(vpc);
    if (bign.dot(c) < 0)
        return false;

    return true;
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

    ta.normalize();
    tb.normalize();
    tc.normalize();

    return new Triangle(ta,tb,tc);

}
