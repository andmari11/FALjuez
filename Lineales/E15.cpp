#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

void invertir(const int& n,  int& ret){

    if(n==0)return;
    
    ret=ret*10+n%10;
    invertir(n/10, ret);
}


bool resuelveCaso(){
    
    int n, ret=0;
    cin>>n;

    if(n==0)return false;

    invertir(n, ret);
    cout<<ret<<endl;

    return true;
}



int main(){

    while(resuelveCaso());
}