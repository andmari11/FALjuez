#include <iostream>

using namespace std;

bool resuelveCaso(){

    int x, n;
    long long int ret=0, aux=1;

    if(!cin){

        return false;
    }


    cin>>x>>n;

    while(0<=n){


        ret+=aux;
        aux*=x;
        
        ret%=1000007;
        n--;
    }

    cout<<ret%1000007<<"\n";

    return true;
}

int main(){


    while(resuelveCaso());
}