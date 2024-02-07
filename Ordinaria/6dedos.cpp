#include <iostream>
using namespace std;


bool resolver (){

    int n, a, v[2][10], aux, year, suma=0, max=0;

    cin>>n>>a;

    if(n==0 and a==0){

        return false;
    }

    int i=0;

    cin >> year;
    n--;

    while(n>0){

        v[i]=0;

        do{

            v[i]++;
            n--;
            cin>>aux;

        }while(aux==year );


        suma+=v[i];
        year=aux;
        i++;

        
        if(i>=a){

            suma-=v[i-a];
        }

        if(max<suma){

            max=suma;
        }

    }

    cout <<max<<"\n";

    return true;

}






int main(){


    while(resolver());

}