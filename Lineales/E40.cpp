#include <iostream>
#include <vector>
#include <string>

using namespace std;




int resolver(const vector <int>& v,const int& k, const int& l){

    int a=0;
    int b=0;
    int pares=0;
    int impares=0;
    int ret=(int)b-a==k;


    while(b<v.size() or b-a>k){

        if(b-a<=k and b<v.size()){

            if(v[b]%2==0)
                pares++;
            else
                impares++;
            b++;
        }
        else{
            if(v[a]%2==0)
                pares--;
            else
                impares--;
            a++;
        }
        if(impares<=l and b-a==k)
            ret++;
    }

    return ret;
}

void resuelveCaso(){

    int n, k, l;
    cin>>n>>k>>l;
    vector<int> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<resolver(v, k, l)<<"\n";
}


int main(){
       
    int n=0;
    cin>>n;

    for(int i=0;i<n;i++)
        resuelveCaso();
}