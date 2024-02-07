#include <iostream>
using namespace std;



int getLengthTotal(int n){

    if(n==0){

        return 0;
    }

    else{
        // b+h+ n veces u's
        return n+2*(1+getLengthTotal(n--));
    }
}

char letraGrito(int length, int n){

    int longitudT=getLengthTotal(n);

    if(longitudT%2==0){

        if(n>longitudT){

            
        }
    }

    
}



void resuelveCaso(){

    int length, n;

    cin>>length>>n;

    cout<<letraGrito(length, n)<<'\n';
}




int main(){

    while(!cin){

        resuelveCaso();
    }
}