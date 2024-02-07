#include <iostream>
using namespace std;

/*
P: numBoletos>=0

Q: ret= #boletos : boleto%2==0


*/
void resuelve(){

    int ret=0;
    int numBoletos;
    int boleto;

    cin>>numBoletos;

    for(int i=0;i<numBoletos;i++){

        cin>>boleto;

        if(boleto%2==0){
            ret++;
        }

        //I: 0<=i<0 ^ ret<=numBoletos
    }

    cout << ret<<"\n";
}




int main(){

    int casos;

    cin>>casos;

    for(int i=0; i<casos;i++){

        resuelve();
    }
}