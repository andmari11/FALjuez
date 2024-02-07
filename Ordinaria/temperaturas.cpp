#include <iostream>

using namespace std;


void resolver(){

    int n, picos=0, valles=0, temp, temp0;
    bool ascendente=false, descendente;

    cin>> n; 
    n--;
    cin>>temp0;

    while(n>0){

        cin>>temp;
        
        if(temp<temp0){

            if(ascendente){

                picos++;
            }
            ascendente=false;
            descendente=true;

        }
        else if(temp>temp0 ){


            if(descendente){

                valles++;
            }
            ascendente=true;
            descendente=false;
        }
        else{

            descendente=false;
            ascendente=false;
        }

        temp0=temp;

        n--;
    }








    cout<<picos<<" "  << valles<<"\n";



}



int main(){

    int casos;

    cin>>casos;

    for(int i=0; i<casos; i++){

        resolver();
    }
}