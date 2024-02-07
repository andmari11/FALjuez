#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

    Coste= O(n)

    P:{

        v.size()>0 ^ 0<=a<=b<v.size() ^ 0<=l<=9
    }

    nNum(v,a, b, l) returns ret

    Q:{

        ret= #i: a<=i<=b: v[i]=l
    }



    P:{

        v.size()>=0 ^ l>=1 ^ v[0]!=0 ^ v[0]!=1
    }
    resolver(v, l) returns ret
    Q:{

        ret= # (a,b : 0<=a<=b<=n : a-b>=l ^ nNum(v, a, b, 0)== nNum(v, a, b, 1)

    }

    I:{

        0<=a<=b<n ^ 0<=ret ^ ceros=nNum(v, a,b, 0)...
    }

    Funcion cota= n-(a+l)

*/
/*return ret*/
int resolver(const vector<int>& v, const int& l){


    int a=0;
    int b=0;
    int ret=0;
    int ceros=int(v[0]==0), unos=int(v[0]==1);

    while(b<v.size() or b-a>=l){

        if(unos==ceros and b-a>=l)ret++;


        if(b-a<l){

            if(v[b]==0)ceros++;
            else if(v[b]==1) unos++;
            b++;
        }
        else{

            if(v[a]==0)ceros--;
            else if(v[a]==1) unos--;

            a++;
        }
    }

    return ret;
}

void resuelveCaso(){

    int n, l;
    cin>>l>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++){

        cin>>v[i];
    }

    int ret=resolver(v, l);


    cout<<ret;
    cout<<"\n";

}

int main(){

    int nCasos;
    cin>>nCasos;
    
    for(int i=0;i<nCasos;i++){

        resuelveCaso();
    }
}



