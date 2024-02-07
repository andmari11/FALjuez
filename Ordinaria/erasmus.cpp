#include <iostream>
using namespace std;


bool resuelveCaso (){

    int paises, ret=0;
    int estudiantes;

    cin>> paises;


    if(paises==0){
     
        return false;
    }

    for(int i=0;i<paises;i++){

        cin>>estudiantes;
    }



    cout << ret<< "\n";

    return true;

}


int main(){


    while(resuelveCaso());
}