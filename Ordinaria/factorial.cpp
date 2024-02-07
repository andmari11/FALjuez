#include <iostream>
using namespace std;


void solucion(){

    int num, ret=0;

    cin>>num;

    do{

        num=num/5;
        ret+=num;

    }while (num>=5);

    cout<< ret<<"\n";
}


int main(){

    int numcasos;

    cin>>numcasos;

    for(int i=0; i<numcasos;i++){

        solucion();
    }

    
}