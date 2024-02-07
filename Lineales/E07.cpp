#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Especificaciones:

P:{0<=v.size()}

Q:{}

I:{-1<=a<=b<=v.size() ^ max(intervalo(v,0, b) ^ 0<=retA<=retB< v.size())}

*/
bool resuelveCaso(){

    int n, t, aux;

    cin>>n>>t;


    vector<int> v;

    for(int i=0;i<n;i++){
        cin>>aux;
        v.push_back(aux);
    }    

    int a=-1, b=0, max=-1;
    int retA=0, retB=0;

    while(b<n){

        if(v[b]>t){

            if(a==-1){
                a=b;
            }

            if(b-a>max){
                retA=a;
                retB=b;
                max=b-a;
            }

        }
        else{
            a=-1;
        }
        b++;
    }

    cout<<retA<<" "<<retB<<endl;


    return true;
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        resuelveCaso();
}