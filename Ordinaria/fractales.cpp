#include <iostream>
using namespace std;

long long int Fractal( int longitud){

    long long int ret=0;

    if(longitud==1){

        ret=4;
    }
    else{

        ret=4*longitud+4*Fractal(longitud/2);

    }

    return ret;
}


bool resuelve(){


    int longitud;

    if(!cin){

        return false;
    }

    cin>>longitud;

    cout<<Fractal(longitud)<<"\n";

    return true;
}


int main(){

    while(resuelve());


}