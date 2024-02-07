#include <iostream>
using namespace std;


int hermanoPeq(int num);

int hermanoMay(int num);


bool resolver(){

    int num;

    cin>>num;

    if(num==0){

        return false;
    }

    cout<<hermanoPeq(num)<<'\n';
    return true;
}

int main(){

    while(resolver());
}


int hermanoPeq(int num){
    if(num==0){

        return 0;
    }

    return 1+hermanoMay(num-1);

}

int hermanoMay(int num){

    if(num==0){

        return 0;
    }

    if(num%2==0){

        return 1+(hermanoPeq(num-2));
    }
    return 1+hermanoPeq(num-1);

}