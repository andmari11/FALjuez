#include <iostream>
#include <vector>
#include <string>

using namespace std;




//log n
char fuga (const vector <char>& v, int ini, int fin){

    if(ini+1==fin)  return ' ';


    int mitad=(ini+fin)/2;
    
    if(v[mitad]!=v[mitad+1]){
        char ret=mitad+1;
        return ret;
    }


    return max(fuga(v, ini, mitad), fuga(v, mitad, fin));

}


//log n
int asintota (const vector<int>&v, int ini, int fin){

    if(ini+1==fin)   return v[ini];

    int m=(ini+fin)/2;

    if(v[m-1]<v[m]){

        return asintota(v, ini, m);
    }
    else{

        return asintota(v, m, fin);
    }
}

int menorVector(const vector<int>&v, int ini, int fin){

    if(ini+1==fin)   return v[ini];

    int m=(ini+fin)/2;

    if(v[ini]<v[m]){

        return menorVector(v, ini, m);
    }
    else{

        return menorVector(v, m, fin);
    }
}

pair<string, int> canicas(const vector <pair<string, int>>&v, int ini, int fin){

    if(ini+1==fin){

        return v[ini];
    }
    int mitad=(ini+fin/2);
    pair<string, int> izq=canicas(v, ini, mitad);
    pair<string, int> der=canicas(v, mitad, fin);

    if(izq.second>=der.second){

        return {izq.first, izq.second+der.second/2} ;
    }
    else{
        return {der.first, der.second+der.second/2};
    }
}

int perdido(const vector <int>&v1,const vector <int>&v2, int ini, int fin){

    if(ini+1==fin or v2.empty())   return v1[ini];

    int mitad=(ini+fin)/2;

    if(v1[mitad]<v2[mitad]){
        
        return perdido(v1, v2, ini, mitad);
    }
    else{

        return perdido(v1, v2, mitad, fin);
    }
}

int bongo(const vector<int>&v, const int k, int ini, int fin){

    if(ini+1==fin) {
        if(v[ini]-ini==k)
            return v[ini];
        else
            return -1;
    } 

    int m=(ini+fin)/2;

    if(v[m]-m>k){

        return bongo(v, k, ini, m);
    }
    else{

        return bongo(v, k, m, fin);
    }
}

bool resuelveCaso() {
    int n, k;
    cin >> n>>k;

    if(!cin)return false;
    vector<int> v1(n);

    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }

    int ret=bongo(v1,k, 0, n );

    if(ret!=-1)
        cout <<  ret<< '\n';
    else
        cout<<"NO\n";

    return true;
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
        resuelveCaso();

    //while(resuelveCaso());
}