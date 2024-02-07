#include <iostream>
using namespace std;


void solucion(){

    int numero;

    cin>>numero;



    cout<< numero/5<<"\n";
}


int main(){

    int numcasos;

    cin>>numcasos;

    for(int i=0; i<numcasos;i++){

        solucion();
    }
}