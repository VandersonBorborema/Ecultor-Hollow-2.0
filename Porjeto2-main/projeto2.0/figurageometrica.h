#ifndef FIGURAGEOMETRICA
#define FIGURAGEOMETRICA
#include "sculptor.h"

class FiguraGeometrica{
public:
  float r, g, b, a;
public:

  virtual ~FiguraGeometrica(){}
  virtual void draw(Sculptor &s)=0;
  FiguraGeometrica();
};



#endif
