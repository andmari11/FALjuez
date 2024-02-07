#include <iostream>
using namespace std;


int resolver(int n, int k, int v[]){
    int ret=0;
    int b=0, a=0;
    int numCeros=k+1;


    while(b<n){



        if(v[b]==0){

            numCeros++;
        }
        else{

            numCeros=0;
        }

        b++;


        if(numCeros>k){

            numCeros=0;
            a=b;
        }
        else if(b-a>ret and v[b-1]) {

            ret=b-a;
        }
        

    }

    return ret;
}




bool sol(){
    int n,k, v[100000];

    cin>>n>>k;

    if(n==0 and k==0){

        return false;
    }

    for(int i=0;i<n;i++){

        cin>>v[i];
    }

    cout<<resolver(n, k, v)<< '\n';

    return true;
}


int main(){

    while (sol());
}