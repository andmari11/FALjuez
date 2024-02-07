#include <iostream>

using namespace std;


int sumar(int suma){

    char aux=getchar();
    int num=aux-48;

    if(aux=='\n'){


        cout<<" = "<<suma<<'\n';
    }
    else{

        cout<<" + "<<aux;
        suma+=num;
        sumar(suma);
        return suma;
    }

    return 0;
}




bool solucion(){

    char aux;


    aux=getchar();

    if(aux=='-'){

        return false;
    }


    


        cout<<aux;
        sumar(aux-48);

    





    return true;
}



int main(){

    while(solucion());
}