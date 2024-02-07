#include <iostream>
using namespace std;


bool resuelveCaso(){

    int n, valor, v[100000][2], nValores=0;

    cin>>n;

    if(n==0){

        return false;
    }

    for(int i=0; i<n; i++){


        cin>>valor;

        int j=0;

        while(j<nValores and valor!=v[j][0]){

            j++;
        }    

        if(j==nValores){

            nValores++;
            v[j][0]=valor;
            v[j][1]=1;
        }
        else{

            v[j][1]++;
        }
    }

    int ret=0;

    for(int i=1;i<nValores;i++){

        if(v[ret][1]<v[i][1]){

            ret=i;
        }
    }


    cout<<v[ret][0]<<"\n";


    return true;


}




int main(){

    while(resuelveCaso());
}