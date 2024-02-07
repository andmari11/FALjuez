#include <iostream>
#include <ctype.h>

using namespace std;



void resolver();

int main(){
    int numcasos;

    cin>>numcasos;

    for(int i=0; i<numcasos; i++){


        resolver();
    }
}


long long int operacion(char op, long long int num1, long long int num2){


    if(op=='+'){

        return num1+num2;
    }
    else if(op=='-'){

        return num2-num1;
    }
    else if(op=='*'){

        return num1*num2;
    }
    else{

        return num2/num1;
    }
}


long long int calcularR(){
    
    long long int num2;
    char op2;

    cin>>op2;

    
    if(isalnum(op2)){

        return op2-'0';
    }
    

    return operacion(op2, calcularR(), calcularR());
    

 
}



void resolver(){


    cout<<calcularR()<<"\n";
}

