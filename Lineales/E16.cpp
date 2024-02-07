#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;


int inverso(int n){

    if(n==9)return 0;
    if(n==0)return 9;
    return 9-n%10;
}

void invertir(const int& n,  int& ret){

    if(n==0)return;
    
    ret=ret*10+n%10;
    invertir(n/10, ret);
}

int complementario(const int& n){

    if(n/10==0)return 9-n%10;

    return complementario(n/10)*10+ 9-n%10;
}

void complementarioInverso(const int& n,  int& ret, bool principio=true){

    if(!principio and n==0)return;

    ret=ret*10+inverso(n%10);

    complementarioInverso(n/10, ret, false);
}


bool resuelveCaso(){
    
    int n;
    cin>>n;

    cout<<complementario(n)<<" ";
    
    int ret=0;
    complementarioInverso(n, ret);

    cout<<ret<<endl;

    return true;
}



int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++)resuelveCaso();

}