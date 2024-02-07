#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct tCancion{
    int duracion, puntuacion;
    float proporcion;

    bool operator>(const tCancion& other) const{

        return(this->proporcion>other.proporcion);
    }
        bool operator<(const tCancion& other) const{

        return(this->proporcion<other.proporcion);
    }
};

struct tInfo{
    int capacidadCaraDisco;
    vector<tCancion> canciones;
    tCancion cancionOptima;
    
};

struct tSolParcial{

    int caraA=0;
    int caraB=0;
    int puntuacionTotal=0;
};

bool esPrometedor(const tInfo& info,const tSolParcial& solParcial, const int& sol,const  int& k){

    bool ret=true;

    int nCancionesRestantes=min((int)info.canciones.size()-k,(info.capacidadCaraDisco*2-solParcial.caraA-solParcial.caraB)/info.cancionOptima.duracion);

    if(solParcial.puntuacionTotal+(nCancionesRestantes)*info.cancionOptima.puntuacion<sol){
        ret=false;
    }

    return ret;
}

void resolver(const tInfo& info, tSolParcial solParcial, int& sol, int k=0){


    //a la cara a
    solParcial.caraA+=info.canciones[k].duracion;
    solParcial.puntuacionTotal+=info.canciones[k].puntuacion;

    bool prometedor=esPrometedor(info, solParcial, sol, k+1);

    if(solParcial.caraA<=info.capacidadCaraDisco){

        if(solParcial.puntuacionTotal>sol){

            sol=solParcial.puntuacionTotal;
        }
        else if(k+1<info.canciones.size() and prometedor){

            resolver(info, solParcial, sol, k+1);
        }
    }

    solParcial.caraA-=info.canciones[k].duracion;
    solParcial.puntuacionTotal-=info.canciones[k].puntuacion;


    //a la cara b
    solParcial.caraB+=info.canciones[k].duracion;
    solParcial.puntuacionTotal+=info.canciones[k].puntuacion;

    if(solParcial.caraB<=info.capacidadCaraDisco){

        if(solParcial.puntuacionTotal>sol){

            sol=solParcial.puntuacionTotal;
        }
        else if(k+1<info.canciones.size()and prometedor){

            resolver(info, solParcial, sol, k+1);
        }
    }

    solParcial.caraB-=info.canciones[k].duracion;
    solParcial.puntuacionTotal-=info.canciones[k].puntuacion;

    //no coger

    if(k+1<info.canciones.size() and esPrometedor(info, solParcial, sol, k+1)){

        resolver(info, solParcial, sol, k+1);
    }
}


bool resuelveCaso(){

    int nCanciones, capacidadCaraDisco;

    cin>>nCanciones;

    if(nCanciones==0){
        return false;
    }

    cin>>capacidadCaraDisco;
    vector<tCancion> canciones;
    tCancion aux;
    tCancion cancionOptima={10000, -1};

    for(int i=0;i<nCanciones;i++){

        cin>>aux.duracion>>aux.puntuacion;
        aux.proporcion=aux.puntuacion/aux.duracion;

        

        cancionOptima=max(cancionOptima, aux);
        canciones.push_back(aux);
    }
    int ret=0;
    tSolParcial solP;
    sort(canciones.begin(), canciones.end(), greater<tCancion>());

    resolver({capacidadCaraDisco, canciones, cancionOptima}, solP, ret);

    cout <<ret<<"\n";

    return true;
}

int main(){

    while(resuelveCaso());
}