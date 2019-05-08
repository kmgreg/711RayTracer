#include "World.h"

#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"
#include "IllModel.h"
#include "PhongIll.h"
#include "GridIll.h"

#include <vector>

using namespace Eigen;

World::World()
{

    //colors
    Vector3f purp;
    Vector3f grn;
    Vector3f red;
    Vector3f wht;
    Vector3f yelo;
    Vector3f lol;

    purp << 50,0,50;
    grn << 0,100,0;
    red << 100,0,0;
    wht << 33,33,33;
    yelo << 50,50,0;
    lol << 10,10,10;

    //Will make more robust later
    //Near
    Vector3f sc1;
    sc1 << -.1, 0, .30;
    Sphere * so = new Sphere(0.2, sc1);
    so->setambi(wht);
    so->setspec(wht);
    PhongIll * sop = new PhongIll();
    sop->setvecs(so->getambi(), so->getspec());
    sop->setparams(0.1,0.1,0.3,100);
    so->setilm(sop);
    so->kr = 0.0;
    so->kt = 0.8;
    geoset.push_back(so);

    //Far

    Vector3f sc2;
    sc2 << .3, -.3, .8;
    Sphere * st = new Sphere(.3, sc2);
    st->setambi(wht);
    st->setspec(wht);
    PhongIll * stp = new PhongIll();
    stp->setvecs(st->getambi(), st->getspec());
    stp->setparams(0.1,0.2,0.1,100);
    st->setilm(stp);
    geoset.push_back(st);
    st->kr = 0.8;
    st->kt = 0;
    //Closer to origin
    Vector3f a; //(far left)
    Vector3f b; //(far right)
    Vector3f c; //(Near left)
    Vector3f d; //(Near right)

    a << -2, -1.2, .1;
    b << 3,  -1.2, .1;
    c << 3,  -1.2, 4;
    d << -2, -1.2, 4;

    Triangle * tn = new Triangle(a,b,c);
    tn->setambi(red);
    tn->setspec(wht);
    GridIll * cbrd = new GridIll();
    cbrd->setcols(red, yelo);
    cbrd->setchk(.1);
    cbrd->setcrnr(a,c);
    tn->setilm(cbrd);
    tn->kr = 0;
    tn->kt = 0;
    geoset.push_back(tn);

    //further away
    Triangle * tf = new Triangle(a,d,c);
    tf->setilm(cbrd);
    geoset.push_back(tf);
    tf->kr = 0;
    tf->kt = 0;

    //Light

    Vector3f ll,lc;

    ll << 1,4,1;
    lc << 100,10,0;

    Light * lo = new Light(ll,lc);
    this->lightset.push_back(lo);

}


World::~World()
{
    //dtor
}

std::vector<Shape * > World::getshapes(){
    return geoset;
}

std::vector<Light *> World::getlits(){
    return this->lightset;
}
