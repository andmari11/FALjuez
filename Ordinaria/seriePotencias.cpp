#include <iostream>
using namespace std;


int abadias (int numMontanas, int v[]){

    int i=numMontanas-1;
    int max=-100000;
    int ret=0;

    while(i>=0){

        if(v[i]>max){

            ret++;
            max=v[i];
        }


        i--;
    }

    return ret;
}

bool resolver(){

    int numMontanas;
    int v[100000];

    cin>>numMontanas;

    if(numMontanas==0){

        return false;
    }

    for(int i=0;i<numMontanas;i++){

        cin>>v[i];
    }

    cout<<abadias(numMontanas, v)<<"\n";

    return true;
}


int main(){

    while(resolver());

    return 0;
}