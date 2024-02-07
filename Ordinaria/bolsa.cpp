#include <iostream>
using namespace std;

int sol(int n, int v[], int longitudV){


    int a=0, b=0, suma=0, ret=0;


    while((a<longitudV and suma>=n) or  b<longitudV){

        if(suma<n and b<longitudV){

            suma+=v[b];
            b++;
        }
        else if(suma>=n){

            if(suma==n){

                ret++;
            }


            suma-=v[a];
            a++;
        }

    }

    return ret;

}





int resolver(){

    int n, longitudV=0;
    char aux; 

    int v[250000];

    cin>>n;
    aux=getchar();



    while(aux!='\n'){


        aux=getchar();


        if(aux!='0' and aux!='\n'){

            v[longitudV]=aux-48;
            longitudV++;
        }
    }



    
    

    return sol(n, v, longitudV);
}



int main(){

    int  numCasos;
    cin>>numCasos;

    for(;numCasos>0;numCasos--){

        cout <<resolver()<<"\n";
    }




}