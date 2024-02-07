#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

    Coste= O(n)

    P:{}
    todosPares(v, a, b) returns ret
    Q:{ret = para todo i :a<=i<b: v[i]%2==0}

    P:{}
    resolver(v) returns ret
    Q:{ret=#a,b:0<=a<b<=n: todosPares(v, a, b)}

    I:{0<=a<=b<=v.size() ^ par= #i:a<=i<=b: v[i]%==0 ^ ret=#i, j:0<=i<j<=b: todosPares(v, i, j)}

    Función cota= 2*v.size()-a-b

*/

int resolver(const vector<int>& v){

    if(v.empty())   return 0;

    int ret=0;
    int a=0;
    int b=0;
    int impar=0;
    int par=0;
    // or b>a
    while(b<v.size() or b>a){

        if((a==b or impar==0) and b<v.size()){
            
            impar+=(int)v[b]%2==1;
            par+=(int)v[b]%2==0;
            b++;
        }
        else{
            
            while(par>0){

                ret+=par;
                par--;
            }
            impar=0;
            a=b;
        }

    }

    return ret;
}

void resuelveCaso(){

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){

        cin>>v[i];
    }

    cout<<resolver(v)<<"\n";
}

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){

        resuelveCaso();
    }
}