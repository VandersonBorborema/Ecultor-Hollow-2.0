#include <iostream>
#include <cstdlib>
#include <clocale>
#include <cmath>
#include <fstream>
#include "sculptor.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz){
    this -> nx = _nx;
    this -> ny = _ny;
    this -> nz = _nz;
    int i, j, k;
    //alocação da matriz 3D
    v = new Voxel**[nx];
    for (int i = 0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for (int j = 0; j<ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }


    //inicializadores
    for(i =0; i<nx; i++){
        for(j =0; j<ny; j++){
            for(k =0; k<nz; k++){
               this -> v[i][j][k].r = this -> r;
               this -> v[i][j][k].g = this -> g;
               this -> v[i][j][k].b = this -> b;
               this -> v[i][j][k].a = this -> a;
               this -> v[i][j][k].show = false;
            }
        }
    }
}
//destrutor da classe
Sculptor::~Sculptor(){
    for (int i = 0; i<nx; i++){
        for (int j = 0; j<ny; j++){
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}
//insere cor aos voxels
void Sculptor::setColor(float _r, float _g, float _b, const float _a){
     r = _r;
     g = _g;
     b = _b;
     a = _a;
}
//insere voxels
void Sculptor::putVoxel(int x, int y, int z){
   v[x][y][z].r =  r;
   v[x][y][z].g =  g;
   v[x][y][z].b =  b;
   v[x][y][z].a =  a;
   v[x][y][z].show = true;
}
//retira voxels
void Sculptor::cutVoxel(int x, int y, int z){
   v[x][y][z].show = false;
}


void Sculptor::writeOFF(char* filename){
    int i, k, j;
    setlocale(LC_ALL, "Portuguese");

    int nvo = 0, nve = 0; //Número de voxels e número de vértices, respectivamente
    std::ofstream fout;//Cria o objeto para o fluxo de sa[ida
    fout.open(filename);//Abre o fluxo
    if(!fout.is_open()){
        std::cout << "Não foi possicel abrir o arquivo.\n";
        std::exit(1);//precida da cstdlib
    }
    fout << "OFF" << std::endl;
    //conta o número de voxels existentes
    for(i =0; i<nx; i++){
        for(j = 0; j<ny; j++){
            for(k = 0;k<nz; k++){
                if(v[i][j][k].show==true){
                    nvo = nvo + 1;
                }
            }
        }
    }
    //define o número de vértices e faces
    fout <<nvo*8<<" "<<nvo*6<<" "<<0<<std::endl;

    //define a posição dos vértices de cada voxel, usando como padrão o que foi defino pelo professor
    for(i =0; i<nx; i++){
        for(j = 0; j<ny; j++){
            for(k = 0;k<nz; k++){
                if(v[i][j][k].show==true){
                    fout << i-0.5 << " " << j+0.5 << " "<<k-0.5<<std::endl;
                    fout << i-0.5 << " " << j-0.5 << " "<<k-0.5<<std::endl;
                    fout << i+0.5 << " " << j-0.5 << " "<<k-0.5<<std::endl;
                    fout << i+0.5 << " " << j+0.5 << " "<<k-0.5<<std::endl;
                    fout << i-0.5 << " " << j+0.5 << " "<<k+0.5<<std::endl;
                    fout << i-0.5 << " " << j-0.5 << " "<<k+0.5<<std::endl;
                    fout << i+0.5 << " " << j-0.5 << " "<<k+0.5<<std::endl;
                    fout << i+0.5 << " " << j+0.5 << " "<<k+0.5<<std::endl;
                }
            }
        }
    }

    nvo =0;
    //Define as faces do voxel, usando como padrão o que foi defino pelo professor
    for(i =0; i<nx; i++){
        for(j = 0; j<ny; j++){
            for(k = 0;k<nz; k++){
                if(v[i][j][k].show==true){
                    nve = nvo*8;

                    fout << "4 "<< nve+0 << " "<< nve+3 << " " << nve+2 << " "<< nve + 1 << " "<< v[i][j][k].r << " " << v[i][j][k].g << " "<< v[i][j][k].b << " " << v[i][j][k].a<<std::endl;
                    fout << "4 "<< nve+4 << " "<< nve+5 << " " << nve+6 << " "<< nve + 7 << " "<<v[i][j][k].r << " " << v[i][j][k].g << " "<< v[i][j][k].b << " " << v[i][j][k].a<<std::endl;
                    fout << "4 "<< nve+0 << " "<< nve+1 << " " << nve+5 << " "<< nve + 4 << " "<<v[i][j][k].r << " " << v[i][j][k].g << " "<< v[i][j][k].b << " " << v[i][j][k].a<<std::endl;
                    fout << "4 "<< nve+0 << " "<< nve+4 << " " << nve+7 << " "<< nve + 3 << " "<<v[i][j][k].r << " " << v[i][j][k].g << " "<< v[i][j][k].b << " " << v[i][j][k].a<<std::endl;
                    fout << "4 "<< nve+3 << " "<< nve+7 << " " << nve+6 << " "<< nve + 2 << " "<<v[i][j][k].r << " " << v[i][j][k].g << " "<< v[i][j][k].b << " " << v[i][j][k].a<<std::endl;
                    fout << "4 "<< nve+1 << " "<< nve+2 << " " << nve+6 << " "<< nve + 5 << " "<<v[i][j][k].r << " " << v[i][j][k].g << " "<< v[i][j][k].b << " " << v[i][j][k].a<<std::endl;

                    nvo = nvo+1;
                }
            }
        }
    }
    fout.close();

}



