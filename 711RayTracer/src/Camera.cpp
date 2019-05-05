#include "Camera.h"

#include <Eigen>
#include <vector>
#include <iostream>
#include <fstream>
#include "Shape.h"

#define HEIGHT 600
#define WIDTH 800
#define FLENGTH 1.0
#define PWIDTH 4.0
#define PHEIGHT 3.0
#define INF 100000000

using namespace Eigen;

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
        int r = (int) (pix[0] * 255);
        int g = (int) (pix[1] * 255);
        int b = (int) (pix[2] * 255);
        filewtt << r << " " << g << " ";
        filewtt << b << " \n";
    }
    filewtt.close();

}

Camera::~Camera()
{
    //dtor
}

void Camera::captureworld(World wld){

    //Yo dawg...
    std::vector<Vector3f>image;

    std::vector<Shape *> clones = wld.getshapes();
    std::vector<Shape *> cams;
    /*
    for (Shape * z: clones) {
        cams.push_back(z->tform((this->tra)));
    }
    */

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
                Ray * pxr = new Ray(p,raypos);
                bool foundcol = false;
                Vector3f colr;
                float newt;
                float champt = INF;
                Shape * coll;
                for (Shape * s : clones){
                    if (s->checkcollision(pxr,newt)){
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
                    colr = coll->getcolor();
                }
                image.push_back(colr);

        }
    }
    writetofile(image);
}
