#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tInfo{

    int pesoMax;
    vector<int>pesosUvas;
};

void resolver(const tInfo& info, int pesoParcial, int& ret,int nUvas=0, int k=0){

    if (nUvas== 12)
    {
        ret++;
        return;
    }

    pesoParcial+=info.pesosUvas[k];
    if(pesoParcial<=info.pesoMax){

        if(k+1<=info.pesosUvas.size())
            resolver(info, pesoParcial, ret, nUvas+1, k+1);        
    }
    pesoParcial-=info.pesosUvas[k];

    if(k+1<=info.pesosUvas.size()){

        resolver(info, pesoParcial, ret, nUvas, k+1);
    }
}

bool resuelveCaso(){

    int pesoMax, nUvas;

    cin>>pesoMax>>nUvas;

    if(pesoMax+nUvas==0)
        return false;

    vector<int>pesosUvas(nUvas);
    for(int i=0;i<nUvas;i++){

        cin>>pesosUvas[i];
    }


    int ret=0;

    resolver({pesoMax, pesosUvas}, 0, ret);

    cout<<ret<<"\n";

    return true;
}


int main(){

    while(resuelveCaso());
}