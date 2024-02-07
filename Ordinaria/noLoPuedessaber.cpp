#include <iostream>
using namespace std;



void adivina(int ini, int fin, int n){



    int i=0, m, intentos;
    bool encontrado=false;
    cin>>intentos;

    while(i<intentos){

        cin>>m;
        if(!encontrado){

            if(n>=m){

                if(m>ini)
                ini=m;
            }
            else {
                if(m-1<fin)
                fin=m-1;
            }

        }

        i++;
    }



    if((fin-ini)+1>1){

        cout <<"NO LO SABE"<< '\n' ;

    }
    else{

        cout <<"LO SABE"<< '\n' ;
    }


}

int main(){

    int ini, n, fin;

    cin>>ini>> fin >> n;

    while (ini!=0 and fin!=0){


        adivina(ini, fin, n);
        cin>>ini>> fin >> n;

    }
}