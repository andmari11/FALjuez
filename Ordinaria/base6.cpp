#include <iostream>
using namespace std;


unsigned long long int base6(unsigned long long int num){

    if(num<6){

        return num;
    }
    
    return base6(num/6)*10+num%6;

}



void resolver (){

    long long unsigned int num;

    cin>>num;

    cout<<base6(num)<<'\n';

}

int main(){

    int numCasos;
    cin>>numCasos;

    for(int i=0; i<numCasos; i++){

        resolver();
    }

}