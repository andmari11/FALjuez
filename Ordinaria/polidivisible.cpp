#include <iostream>
using namespace std;


bool polidivisible (long long  int num, int divisor){

    bool ret=false;


    if(divisor==1){


        ret=true;
    }

    else if(num%divisor==0){

        ret=polidivisible(num/10, divisor-1);
    }

    return ret;
}

int contarDigitos(long long  int num){

    int ret=1;

    while (num>9){

        num/=10;
        ret++;
    }

    return ret;
}


bool resuelve(){

    if(!cin){

        return false;
    }

    long long  int num;
    cin>>num;


    if(polidivisible(num,contarDigitos(num) )){

        cout<<"POLIDIVISIBLE \n";
    }
    else{

        cout<<"NO POLIDIVISIBLE \n";

    }

    return true;
}


int main(){

    while(resuelve());


}