#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "sculptor.h"
#include "figurageometrica.h"


class cutSphere : public FiguraGeometrica
{
    int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, float radius);

    ~cutSphere(){

    };
    void draw(Sculptor &s);
};

#endif
