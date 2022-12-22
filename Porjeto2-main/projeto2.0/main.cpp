#include "figurageometrica.h"
#include "interpretador.h"
#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

int main(){
  Sculptor *teste;
  Interpretador parser;

  std::vector<FiguraGeometrica*> fig;

  fig = parser.parse((char *)"C:/Users/elvan/OneDrive/햞ea de Trabalho/Projeto#U/Dados/figuras.txt");
  teste = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

  for(size_t i=0; i<fig.size(); i++){
    std::cout << "draw\n";
    fig[i]->draw(*teste);
  }
  teste->Sculptor::writeOFF((char *)"C:/Users/elvan/OneDrive/햞ea de Trabalho/Projeto#U/Dados/teste.off");
  for(size_t i=0; i<fig.size(); i++){
    delete fig[i];
    }
  delete teste;


  Sculptor *hollow;
  Interpretador reader;

  std::vector<FiguraGeometrica*> f;

  f = reader.parse((char *)"C:/Users/elvan/OneDrive/햞ea de Trabalho/Projeto#U/Dados/figura.txt");
  hollow = new Sculptor(reader.getDimx(), reader.getDimy(), reader.getDimz());

  for(size_t i=0; i<f.size(); i++){
    std::cout << "draw\n";
    f[i]->draw(*hollow);
  }
  hollow->Sculptor::writeOFF((char *)"C:/Users/elvan/OneDrive/햞ea de Trabalho/Projeto#U/Dados/hollow.off");
  for(size_t i=0; i<f.size(); i++){
    delete f[i];
    }
  delete hollow;

  return 0;
}
