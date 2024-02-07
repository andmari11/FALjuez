#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tInfo{
    int n, m;
    vector<vector<int>> satisfaccion;
};

struct tSolucion{
    int sTotal=0;
    vector<int> sol;
};

bool esValido(){

    bool ret=true;




    return ret;
}


void resolver(const tInfo &info, tSolucion actual, tSolucion& solucion, vector<int>marcaje,vector<int>& estimacion, int k=0){

    for(int i=0;i<info.m;i++){

        if(marcaje[i]==0){

            actual.sol.push_back(i);
            actual.sTotal+=info.satisfaccion[k][i];
            marcaje[i]++;

            if(esValido()){

                if(k+1==info.n){

                    if(actual.sTotal>solucion.sTotal){
                        solucion=actual;
                    }
                }
                else{

                    resolver(info, actual, solucion, marcaje, estimacion, k+1);
                }
            }

            actual.sol.pop_back();
            actual.sTotal-=info.satisfaccion[k][i];
            marcaje[i]--;
        }
    }
}