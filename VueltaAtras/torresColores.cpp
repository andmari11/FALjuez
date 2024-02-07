#include <iostream>
#include <vector>
#include <string>

//O(n^3)

using namespace std;

enum tColor{AZUL, ROJO, VERDE};

struct tInfo{
    int r, v, a, nAltura;
};


bool esValido(tInfo& info, vector <tColor> sol, int k, vector<int>& marcas){
    bool ret=true;

    if(sol[k-1]==VERDE and sol[k]==VERDE){
        ret=false;
    }
    else if( marcas[0]<marcas[2]){
        ret=false;
    }
    else if(sol[k]==AZUL and marcas[0]>info.a){

        ret=false;
    }
    else if(sol[k]==ROJO and marcas[1]>info.r){

        ret=false;
    }
    else if (sol[k]==VERDE and marcas[2]>info.v){

        ret=false;
    }



    return ret;
}
int torres(tInfo& info, vector <tColor> sol, int k, vector<int>& marcas){

    int nSoluciones=0;


    for(int i=0;i<3;i++){
        if(k==0){

            sol[0]=(tColor)1;
            marcas[1]++;
        }
        else{

            sol[k]=(tColor)i;
            marcas[i]++;
        }



        if(esValido(info, sol, k, marcas)){

            if(k+1==info.nAltura){

                if(marcas[1]>marcas[0]+marcas[2]){
                nSoluciones++;

                for(tColor color: sol){

                    if(color==AZUL) cout<<"AZUL ";
                    else if(color== ROJO) cout <<"ROJO ";
                    else cout<<"VERDE ";
                }
                cout<<"\n";
                }
            }
            else{

                nSoluciones+=torres(info, sol, k+1, marcas);
            }

        }

        marcas[i]--;
    }

    return nSoluciones;
}


bool resuelveCaso(){

    int rojo, verde, azul, nAltura;
    cin>>nAltura>>azul>>rojo>>verde;

    if(nAltura==0)return false;

    vector <tColor> sol(nAltura);
    vector<int> marcas(3);
    tInfo info={rojo, verde, azul, nAltura};

    int n=torres(info,sol, 0,marcas );
    if(n==0)
        cout<<"SIN SOLUCION\n";
       
        cout<<"\n";


    return true;
}


int main(){

    while(resuelveCaso());
}