#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Edificio{

    string nombre;
    int altura;
    int piso;
};



/*
P:{v.size()>=0 ^ para todo i:0<=i<v.size(): v[i].altura>=v.piso}
Q:{0<=sol.size()<=v.size()^
    
    todo v[i].nombre : 0<=i<v.size(): v[i]>maxAltura(v, 0, i)}
maxAltura =v[a] para todo i: 0<=i<v.size(): v[i]<v[a]

I:{0<=i<v.size() ^ maxAltura= ^ret={v[i].nombre::v[piso]>maxAltura}}



*/
vector<string> resolver(const vector<Edificio>&v){

    int maxAltura=-1;
    vector<string> ret;

    for(int i=v.size()-1; i>=0; i--){

        if(v[i].piso>maxAltura){
            ret.push_back(v[i].nombre);

            if(v[i].altura>maxAltura){
                
                maxAltura=v[i].altura;
            }
        }
        
    }

    return ret;

}


bool resuelveCaso(){

    int n;
    cin>>n;

    if(n==0)return false;



    return true;
}


int main(){

    while(resuelveCaso());
}