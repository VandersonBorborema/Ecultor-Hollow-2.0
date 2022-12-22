#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "sculptor.h"
#include "figurageometrica.h"

class putVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    putVoxel(int x,int y,int z,float r,float g,float b,float a);
    ~putVoxel(){

    };
    void draw(Sculptor &s);
};

#endif
