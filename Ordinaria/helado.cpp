#include <iostream>
using namespace std;


void calcular( int uvas, int pos, int umbral, int pesos[], int contadorSol, long pesoTotal, int &ret){

    //caso base
    if(pesoTotal<= umbral and contadorSol>=12){
        
        ret++;
        return;
    }

    if(pesoTotal>umbral or pos==uvas){

        return;
    }





    



   //caso recursivo

   //coges
   calcular(uvas, pos+1, umbral, pesos, contadorSol+1, pesoTotal+pesos[pos], ret);

   //no coges
   calcular(uvas, pos+1, umbral, pesos, contadorSol, pesoTotal, ret);



}




bool resolver(){

    int uvas, umbral, ret=0;
    int pesos[23];

    cin>>umbral>>uvas;

    if(umbral==uvas and uvas==0){
        
        return false;
    }

    for(int i=0; i<uvas;i++){
        
        cin>>pesos[i];
    }
    
    calcular(uvas,0,umbral, pesos, 0, 0 , ret);

    cout <<ret <<"\n";

    return false;

}



int main(){

    while(resolver());
}