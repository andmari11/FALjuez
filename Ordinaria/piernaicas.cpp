#include <iostream>
using namespace std;

//dado vector devuelve num de posiciones q son mayores a lso numeros de su derecha

void sol(int v[], int n){

    
    int ret=0, posMax=0, restantes=n;

    for(int i=0;i<n;i++){

        cin>>v[i];

        if(v[i]>=v[posMax]){

            posMax=i;
        }
    }

    do{

        restantes= n-posMax;
        ret++;
        posMax++;

        for(int i=posMax; i<n;i++){

            if(v[i]>=v[posMax]){

                posMax=i;
            }
        }

    } while(restantes>1);


    cout<< ret<<"\n";
}

bool resuelve(){

    int n;
    int v[100000];

    cin >> n;

    if(n==0){

        return false;
    }

    sol (v, n);
    return true;
}

int main(){

    while(resuelve());

    return 0;
}