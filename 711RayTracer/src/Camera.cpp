#include "Camera.h"

#include <Eigen>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include "Shape.h"
#include "Intersection.h"

#define HEIGHT 600
#define WIDTH 800
#define FLENGTH 1.0
#define PWIDTH 4.0
#define PHEIGHT 3.0
#define MAXRECDEPTH 4
#define INF 100000000

using namespace Eigen;

Vector3f getr(Vector3f sray, Vector3f norm){
    Vector3f t2 = sray - 2*(sray.dot(norm)) * norm;
    return t2;
}


Camera::Camera(Vector3f la, Vector3f u,
               Vector3f p)
{
    lookat = la;
    up = u;
    pos = p;
    lookat.normalize();
    up.normalize();
    pos.normalize();
    //col major
    Vector3f matn = pos - lookat;
    matn.normalize();
    Vector3f matu = up.cross(matn);
    matu.normalize();
    Vector3f matv = matn.cross(matu);
    this->tra << matu(0), matv(0), matn(0), 0.0f,
                 matu(1), matv(1), matn(1), 0.0f,
                 matu(2), matv(2), matn(2), 0.0f,
                -(pos.dot(matu)), -(pos.dot(matv)),
                -(pos.dot(matn)), 1.0;


}

void writetofile(std::vector<Vector3f> image)
{
    std::ofstream filewtt;
    filewtt.open("output.ppm");
    filewtt << "P3\n" << WIDTH << " ";
    filewtt << HEIGHT << "\n";
    filewtt << 255 << "\n";
    for (Vector3f pix : image){
        int r = std::abs((int) (pix[0] * 255));
        int g = std::abs((int) (pix[1] * 255));
        int b = std::abs((int) (pix[2] * 255));
        filewtt << r << " " << g << " ";
        filewtt << b << " \n";
    }
    filewtt.close();

}

Camera::~Camera()
{
    //dtor
}

Vector3f Camera::getcolor(Ray * r, int recdepth){
    vector<Shape *> clones = wld->getshapes();
    vector<Light *> lits = wld->getlits();
    Vector3f colr;
    bool foundcol = false;
    float newt;
    float champt = INF;
    Shape * coll;
    for (Shape * s : clones){
        if (s->checkcollision(r,newt)){
            foundcol = true;
            if (newt < champt){
                champt = newt;
                coll = s;
            }
        }
        }
        if (!foundcol){
            Vector3f dflt;
            dflt << 0.0, 0.2, 0.5;
            colr = dflt;
        }
        else
        {
            //colr = coll->getcolor();
            Vector3f colpt = r->getpos() + r->getdir().normalized() * champt;
            Vector3f SS =  lits.at(0)->getpos() - colpt;
            SS.normalize();
            Ray * shadow = new Ray(colpt,SS);
            bool seelight = true;
            float dummyt; //if dist = 0, hitting self
            for (Shape * s : clones){
                if (s != coll){
                    if (s->checkcollision(shadow, dummyt)){
                        if (dummyt != 0){
                            seelight = false;
                            //ambi
                            Vector3f blk;
                            blk << 0,0,0;
                            colr = blk;
                        }
                    }
                }
            }
            if (seelight){
                Vector3f VV = r->getdir();
                VV.normalize();
                Vector3f NN = coll->getnorm(colpt);
                NN.normalize();
                Vector3f RR = getr(SS,NN);
                Intersection * is = new Intersection();
                is->pt = colpt;
                is->incom = SS;
                is->norm = NN;
                is->reflex = RR;
                is->litlist = lits;
                colr = coll->getcolor(is);
                if (recdepth < MAXRECDEPTH){
                    if (coll->kr > 0){
                        Vector3f refr = getr(VV,NN);
                        refr.normalize();
                        Ray * nr = new Ray(colpt, refr);
                        colr += coll->kr * this->getcolor(nr, recdepth + 1);
                    }
                    if (coll->kt > 0){

                    }
                }
            }
        }
        return colr;
}

void Camera::captureworld(World * wld){

    //Yo dawg...
    std::vector<Vector3f>image;
    this->wld = wld;
    float pixh = PHEIGHT / HEIGHT;
    float pixw = PWIDTH / WIDTH;
    float tx = -PWIDTH/2;
    float ty = PHEIGHT/2;

    Vector3f p;
    p << 0.0, 0.0, 0.0;

    //Generate rays and check
    for (int i = 0; i < HEIGHT; i++){
        float ypx = ty - ((.5 + float(i)) * pixh);
        for (int c = 0; c < WIDTH; c++){
                float xpx =  tx + ((.5 + float(c)) * pixw);
                Vector3f raypos;
                raypos << xpx, ypx, FLENGTH;
                raypos.normalize();
                Ray * pxr = new Ray(p,raypos);
                Vector3f colr = this->getcolor(pxr,0);
                image.push_back(colr);

        }
    }
    writetofile(image);
}
