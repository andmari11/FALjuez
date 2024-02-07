#include <iostream>

using namespace std;


void resolver(){

    int num, ret=0, boleto; 

    cin>> num;

    while(num>0){

        cin>>boleto;

        if(boleto%2==0){
            ret++;
        }

        num--;
    }


    cout<<ret<<"\n";

}



int main(){

    int casos;

    cin>>casos;

    for(int i=0; i<casos; i++){

        resolver();
    }
}