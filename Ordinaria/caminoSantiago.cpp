#include <iostream>
using namespace std;


void mochila(

    float peso[],
    float beneficio, 
    int n, 
    int capacidad, 

    bool solParcial[], 
    int k, 

    //marcaje
    float pesoParcial, 
    float beneficioParcial, 

    //mejorsolucion(inout)

    bool solucionOptima[], 
    float &beneficioMaximo
){
    //casobase

    if(n==k){
        if(beneficioParcial>beneficioMaximo){

            for(int i=0;i<n;i++){

                cout<<solucionOptima[i];
            }
        }

    }

    //caso recursivo

    //csao 1: añadimos el producto k
    if(pesoParcial+peso[k]<=capacidad){

        solParcial[k]=true;
        mochila(peso, beneficio, n, capacidad, solParcial, k+1, pesoParcial+peso[k], beneficioParcial+beneficio[k], solucionOptima, beneficioMaximo);
    }
    //csao 2:no lo añadimos
        
    solParcial[k]=false;
    mochila(peso, beneficio, n, capacidad, solParcial, k+1, pesoParcial,beneficioParcial, solucionOptima, beneficioMaximo);
}