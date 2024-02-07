#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct  tAdorno{

    int coste, superficie;
};


struct tInfo{

    int presupuestoDisponible;
    vector<tAdorno> adornos;
    vector<int> estimacion;
};

struct tSol{

    int costeTotal=0,superficieTotal=0; 
};

bool esValido(const tInfo& info, tSol actual){

    bool ret;

    return true;
}



void resolver(const tInfo& info, tSol actual, tSol& sol, vector<bool>& marcaje, int k=0){

    actual.costeTotal += info.adornos[k].coste;
    actual.superficieTotal += info.adornos[k].superficie;
    marcaje[k] = true;

    if (actual.costeTotal < info.presupuestoDisponible)
    {
        if (k + 1 == info.adornos.size())
        {
            if (actual.superficieTotal > sol.superficieTotal)
            {

                sol = actual;
            }
        }
        else if (info.estimacion[k+1]+actual.superficieTotal>sol.superficieTotal)
        {

            resolver(info, actual, sol, marcaje, k+1);
        }
    }

    actual.costeTotal -= info.adornos[k].coste;
    actual.superficieTotal -= info.adornos[k].superficie;
    marcaje[k] = false;

    if (k + 1 == info.adornos.size())
    {
        if (actual.superficieTotal > sol.superficieTotal)
        {

            sol = actual;
        }
    }
    else if (info.estimacion[k+1]+actual.superficieTotal>sol.superficieTotal)
    {

        resolver(info, actual, sol, marcaje, k + 1);
    }
}




bool resuelveCaso(){

    int n, presupuesto;

    cin>>n>>presupuesto;

    tInfo info;
    tAdorno aux;

    vector<tAdorno> adornos(n);
    vector<bool> marcaje(n, false);


    for(int i=0;i<n;i++){
        cin>>aux.coste>>aux.superficie;
        adornos[i]=aux;
        info.estimacion.push_back(aux.superficie);
    }

    for(int i=info.estimacion.size()-1;i>0;i--){

        info.estimacion[i-1]=info.estimacion[i];
    }

    tSol sol;
    tSol actual;

    resolver(info,actual, sol,marcaje );

    return true;
}