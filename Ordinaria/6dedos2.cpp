#include <iostream>
using namespace std;

int seisDedos(int n, int anos_Max, int v[]){

    int max=0;
    int anos=0;
    int a=0;
    int b=0;
    int dedos=0;

    while(b<n or anos>anos_Max){

        if(anos>anos_Max){
            
            dedos--;
            a++;
        }

        else{

            if(dedos>max){

                max=dedos;
            }
            b++;
            dedos++;
        }

        anos=v[b]-v[a];
    }
    return max;
}


bool resolver (){

    //nNacimientos, a añosPeriodo
    int n, a;
    int v[200000];

    cin>>n>>a;

    if(n==0 and a==0){

        return false;
    }

    for(int i=0;i<n;i++){

        cin>>v[i];
    }

    cout<<seisDedos(n, a, v)<<"\n";


    return true;
}

int main(){


    while(resolver());

}