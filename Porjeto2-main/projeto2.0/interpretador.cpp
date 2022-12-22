#include <iostream>
#include <fstream>
#include <sstream>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
#include "interpretador.h"

Interpretador::Interpretador(){

}

std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename){
    std::vector<FiguraGeometrica*> f;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, thing;

    fin.open(filename.c_str());
    if(!fin.is_open()){
        std::cout << "erro ao abrir arquivo" << std::endl;
        exit(0);
    }

    while(fin.good()){
        std::getline(fin,s);
        ss.clear();
        ss.str(s);
        ss >> thing;
        if(thing.compare("dim")==0){
            ss >> dimx >> dimy >> dimz;

        }
        else if(thing.compare("putvoxel")==0){
            int x,y,z;
            ss >> x >> y >> z >> r >> g >> b >> a;
            f.push_back(new putVoxel(x,y,z,r,g,b,a));
        }
        else if(thing.compare("cutvoxel")==0){
            int x,y,z;
            ss >> x >> y >> z;
            f.push_back(new cutVoxel(x,y,z));
        }
        else if(thing.compare("putbox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            f.push_back(new putBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }
        else if(thing.compare("cutbox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            f.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }
        else if(thing.compare("putsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss  >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            f.push_back(new putSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }
        else if(thing.compare("cutsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss  >> xcenter >> ycenter >> zcenter >> radius;
            f.push_back(new cutSphere(xcenter,ycenter,zcenter,radius));
        }
        else if(thing.compare("putellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            f.push_back(new putEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }
        else if(thing.compare("cutellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            f.push_back(new cutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }
    }
    return(f);
        }

int Interpretador::getDimx(){
    return dimx;
}

int Interpretador::getDimy(){
    return dimy;
}

int Interpretador::getDimz(){
    return dimz;
}
