#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tInfo{

    vector<vector<int>> pacientesDistancia;
    vector<int> hospitalesAforo;


};

void resolver(const tInfo& info, int distanciaParcial,int &sol, vector <int>& pacientesHospital, int k=0 ){

    for(int i=0;i<info.hospitalesAforo.size();i++){

        if(pacientesHospital[i]<info.hospitalesAforo[i]){

            distanciaParcial+=info.pacientesDistancia[k][i]*2;
            pacientesHospital[i]++;
        
            if(true){

                if(k+1==info.pacientesDistancia.size()){

                    if(distanciaParcial<sol or sol==-1){
                        sol=distanciaParcial;
                    }
                
                }
                else if(true){

                    resolver(info, distanciaParcial, sol, pacientesHospital,k+1);
                }
            }
            distanciaParcial-=info.pacientesDistancia[k][i]*2;
            pacientesHospital[i]--;
        }
    }
}


void resuelveCaso(){

    int nHospitales, nPacientes;

    cin>>nPacientes>>nHospitales;

    vector<int> hospitales(nHospitales);

    for(int i=0;i<nHospitales;i++){

        cin>>hospitales[i];
    }

    vector<vector<int>> pacientes(nPacientes);
    vector<int> distancias;

    for(int i=0;i<nPacientes;i++){
        for(int j=0;j<nHospitales;j++){
            int aux;
            cin>>aux;
            distancias.push_back(aux);
        }
        pacientes[i]=distancias;
        distancias.clear();
    }

    int ret=-1;
    vector<int> pacientesHospital(nHospitales);
    resolver({pacientes, hospitales}, 0, ret, pacientesHospital );

    cout <<ret<<"\n";

}


int main()
{
    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++)
        resuelveCaso();
}