#include "PhongIll.h"
#include "Light.h"
#include "Intersection.h"
#include <math.h>

Vector3f compmul(Vector3f a, Vector3f b){
    Vector3f prod;
    prod << a[0] * b[0], a[1] * b[1], a[2] * b[2];
    return prod;
}


PhongIll::PhongIll()
{
    //ctor
}

PhongIll::~PhongIll()
{
    //dtor
}

Vector3f PhongIll::illuminate(Intersection * i){
    vector<Vector3f> ill;
    Vector3f amb,dif,spe;
    amb = this->ka * this->ambi;
    Vector3f tempdif = compmul(i->litlist.at(0)->getcol(), this->ambi);
    dif = this->kd * (i->incom.dot(i->norm)) * tempdif;
    Vector3f tempspe = compmul(i->litlist.at(0)->getcol(), this->spec);
    spe = this->ks * std::pow(i->incom.dot(i->norm), this->ke) * tempspe;
    return amb + dif + spe;
}


void PhongIll::setparams(float ca, float cd, float cs, float ce){
    this->ka = ca;
    this->kd = cd;
    this->ks = cs;
    this->ke = ce;
}

void PhongIll::setvecs(Vector3f am, Vector3f sp){
    this->ambi = am;
    this->spec = sp;
}


