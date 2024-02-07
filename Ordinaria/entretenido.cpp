#include <iostream>
using namespace std;



/*
Pre: num>=0

Post: para todo k : 0 <= k < num.length : num/(10^k)!=num/(10^(k+1))

*/
void entretenido(unsigned long long int num){

    int digitNow=num%10;
    int digitBefore;
    num/=10;

    while(num>0 and digitNow!=digitBefore){

        digitBefore=digitNow;
        digitNow=num%10;
        num/=10;
    }

    if(digitNow!=digitBefore){
        
        cout<<"ENTRETENIDO"<<endl;
    }
    else{

        cout<<"NO ENTRETENIDO"<<endl;

    }
}


/*

Pre: num>=0 && posible>=0

Post: 

*/
void entretenido2(const unsigned long long int num, int& ret,unsigned long long int posible=0){

    //caso base
    if(posible>num or (posible%10==(posible/10)%10 and posible!=0)){

        return;
    }

    //caso recursivo
    ret++;
    
    //posible*10<=num
    if(posible*10<=num){

        for(int i=0;i<10; i++){

            if(posible+i==0){

                i++;
            }

            entretenido2(num,ret, posible*10+i);
        }
    }
}






bool resuelve(){

    unsigned long long int num;
    int ret=0;

    cin>>num;

    if(num==-1){
        return false;
    }

    entretenido2(num, ret);
    cout<<ret<<"\n";

    return true;
}






int main(){

    while(resuelve());
}