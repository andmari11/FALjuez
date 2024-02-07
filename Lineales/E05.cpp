#include <iostream>
#include <string>
#include <vector>

using namespace std;

int resolver(const vector<int>& v){

    int suma=0;
    int a=v.size()-1;
    int ret=-1;

    while(a>=0 and ret<0){

        if(v[a]==suma){
            ret=a;
        }
        else{
            suma+=v[a];
        }
        a--;
    }
    
    return ret;
}

void resuelveCaso(){

    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++){

        cin>>v[i];
    }

    int ret=resolver(v);

    if(ret==-1){
        cout<<"No";
    }
    else{
        cout<<"Si "<<ret;
    }
    cout<<"\n";

}

int main(){

    int nCasos;
    cin>>nCasos;
    
    for(int i=0;i<nCasos;i++){

        resuelveCaso();
    }
}



