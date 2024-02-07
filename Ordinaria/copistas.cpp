#include <iostream>
using namespace std;


bool solucion(){

    int x, y, ncambios;
    //cambiar a 500
    char cuadro[501][501], aux;

    cin>>y>>x;

    if(y==0 and x==0){

        return false;
    }


    for(int i=0; i<y; i++){

        for(int j=0; j< x; j++){

            cin>>cuadro[i][j];
        }
    }


    cin>>ncambios;

    for(int k=0; k<ncambios; k++){

        cin>>cambios[0][k]>>cambios[1][k];

    }


    
    for(int i=0; i<y; i++){

        for(int j=0; j< x; j++){

            for(int k=0; k<ncambios;k++){

                if(cuadro[i][j]==cambios[0][k]){

                    cuadro[i][j]=cambios[1][k];
                }

            }

            cout<<cuadro[i][j];
        }

        cout <<'\n';
    }
    


    return true;
}


int main(){

    while(solucion());
}