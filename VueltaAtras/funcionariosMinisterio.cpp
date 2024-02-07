#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tFuncionario{
    vector<int>tiempo;
};



void resuelve(const vector<tFuncionario>& funcionarios, vector<int>marcaje, int k, int actual, int &ret){


        for(int i=0;i<funcionarios.size();i++){

            if(marcaje[i]==0){

                actual+=funcionarios[i].tiempo[k];
                marcaje[i]=1;


                    if(k+1==funcionarios.size()){

                        if(ret==-1 or ret>actual){

                            ret=actual;
                        }
                    }
                    else if(ret==-1 or actual<ret){

                        resuelve(funcionarios, marcaje, k+1, actual, ret);
                    }
                

                actual-=funcionarios[i].tiempo[k];
                marcaje[i]=0;

            }
        }

    
}

bool resuelveCaso(){

    int n, aux;
    cin>>n;

    if(n==0)return false;

    vector<tFuncionario> funcionarios(n);
    vector<int> marcaje;

    for(tFuncionario &f:funcionarios){
        marcaje.push_back(0);

        for(int i=0;i<n;i++){

            cin>>aux;
            f.tiempo.push_back(aux);
        }
    }
    int ret=-1;
    resuelve(funcionarios,marcaje, 0, 0, ret);

    cout <<ret<<"\n";


    return true;
}


int main(){

    while(resuelveCaso());
}