#include <iostream>
#include <vector>
#include <string>

using namespace std;

int resolver(const vector<int> &v, int ini, int fin){

    if(ini+2==fin)
        return ;

    int m=(ini+fin)/2;
    int derecha=resolver(v, ini, m);
    int izquierda=resolver(v, m, fin);
    
    return max(izquierda, derecha);
}


bool resuelveCaso(){

    int n;
    cin>>n;
    if(!cin)return false;

    vector<int>v(n);

    for(int i=0;i<n;i++){

        cin>>v[i];
    }

    cout<<resolver(v, 0, n)<<"\n";

    return true;
}


int main(){
       
    while(resuelveCaso());

}