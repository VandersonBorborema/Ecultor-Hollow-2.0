#include "figurageometrica.h"
#include "interpretador.h"
#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

int main(){
  Sculptor *hollow;
  Interpretador reader;

  std::vector<FiguraGeometrica*> f;

  f = reader.parse((char *)"C:/Users/elvan/OneDrive/Área de Trabalho/Projeto#U/Dados/figura.txt");
  hollow = new Sculptor(reader.getDimx(), reader.getDimy(), reader.getDimz());

  for(size_t i=0; i<f.size(); i++){
    std::cout << "draw\n";
    f[i]->draw(*hollow);
  }
  hollow->Sculptor::writeOFF((char *)"C:/Users/elvan/OneDrive/Área de Trabalho/Projeto#U/Dados/hollow.off");
  for(size_t i=0; i<f.size(); i++){
    delete f[i];
    }
  delete hollow;

  return 0;
}
