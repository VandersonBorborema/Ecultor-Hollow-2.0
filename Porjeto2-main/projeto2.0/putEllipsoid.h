#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "sculptor.h"
#include "figurageometrica.h"


class putEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter,zcenter,rx,ry,rz;
public:
    putEllipsoid(int xcenter,int ycenter,int zcenter,int rx,int ry,int rz,float r,float g,float b,float a);
    ~putEllipsoid(){

    };
    void draw(Sculptor &s);
};

#endif
