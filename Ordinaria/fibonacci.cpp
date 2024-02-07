#include <iostream>
using namespace std;


const int k=46337;

struct tMatriz{

    long long int a1=0, a2=1, b1=1, b2=1;
};


/*
    a1  a2
    b1  b2

*/


tMatriz operator*(const tMatriz a , const tMatriz b){

    tMatriz c;

    c.a1=(a.a1*b.a1+a.a2*b.b1)%k;
    c.a2=(a.a1*b.a2+a.a2*b.b2)%k;
    c.b1=(a.b1*b.a1+a.b2*b.b1)%k;
    c.b2=(a.b1*b.a2+a.b2*b.b2)%k;

    return c;

}



tMatriz fibonacci(long long int x){


    tMatriz aux;


    if(x==1)
    return aux;

    tMatriz mitad=fibonacci(x/2);

    if(x%2==0){

        return  (mitad* mitad);
    }
    else{

        return  (aux*mitad*mitad);

    }
    
}





int main(){

    long long int x;
    tMatriz sol;
    cin>>x;

    while(x!=0){

        sol=fibonacci(x);
        cout << sol.a2<<'\n';
        cin>>x;
    }
}