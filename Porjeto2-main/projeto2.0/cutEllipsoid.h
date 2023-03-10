#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "sculptor.h"
#include "Figurageometrica.h"

class cutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~cutEllipsoid(){

    };
    void draw(Sculptor &s);
};

#endif
