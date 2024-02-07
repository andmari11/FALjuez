#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tInfo{

    int longitud, nColores, consumoMax;
 
};

bool esPrometedora(){
    bool ret=true;
    return ret;

}
bool esValida(const tInfo& info, const vector<int>& consumo,vector<int> marcaje,vector<int> combinacionActual, int consumoActual, int k, int bombilla){
    bool ret=true;

    if(consumoActual>info.consumoMax){

        ret=false;
    }
    else if(k>2 and combinacionActual[k]==combinacionActual[k-1] and combinacionActual[k-1]==combinacionActual[k-2]){
        ret=false;
    }
   else if(marcaje[bombilla]>k+1-marcaje[bombilla]+1){
       ret=false;
    }


    return ret;
}

int resolver(const tInfo& info, const vector<int>& consumo,vector<int> marcaje, vector<int> combinacionActual, int consumoActual=0, int k=0 ){

    int nCasosExito=0;

    for(int i=0;i<info.nColores;i++){

       // if(marcaje[i]==0){

            consumoActual+=consumo[i];
            marcaje[i]++;
            combinacionActual.push_back(i);

            if(esValida(info, consumo, marcaje, combinacionActual, consumoActual, k, i)){
                if(k+1==info.longitud){
/*
                    for(int i:combinacionActual){
                        cout<<i<<" ";
                    }
                    cout<<endl;*/
                    nCasosExito++;
                }
                else if(esPrometedora()){

                    nCasosExito+=resolver(info, consumo, marcaje, combinacionActual,consumoActual, k+1);
                }

            }

            combinacionActual.pop_back();
            consumoActual-=consumo[i];
            marcaje[i]--;
        //}
    }

    return nCasosExito;

}


bool resuelveCaso(){

    tInfo info;
    cin>>info.longitud>>info.nColores>>info.consumoMax;

    if(info.longitud==0)    return false;

    vector<int> consumo(info.nColores);
    vector<int> marcaje(info.nColores);
    vector<int> v;


    for(int i=0;i<info.nColores;i++){

        int aux;
        cin>>aux;
        consumo[i]=aux;
    }

    cout<<resolver(info, consumo, marcaje, v )<<"\n";

    return true;
}

int main(){

    while(resuelveCaso());
}