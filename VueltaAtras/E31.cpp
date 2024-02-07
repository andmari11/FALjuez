#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tInfo
{

    int nSupermercados, nProductos;
    vector<vector<int>> lista;
    vector<int> minimosAcumulados;

};

void resolver(const tInfo &info, int solParcial, int &sol, vector<int> &marcaje,int k = 0)
{

    for (int i = 0; i < info.nSupermercados; i++)
    {
        // mirar marcaje aqui??
        if (marcaje[i] < 3)
        {

            solParcial += info.lista[i][k];
            marcaje[i]++;

            if (k + 1 == info.nProductos)
            {

                if (solParcial < sol or sol==-1)
                {
                    sol = solParcial;
                }
            }
            else if (sol==-1 or solParcial+info.minimosAcumulados[k+1]<=sol )
            {
                resolver(info, solParcial, sol, marcaje, k + 1);
            }

            solParcial -= info.lista[i][k];
            marcaje[i]--;
        }
    }
}

void resuelveCaso()
{

    int aux;
    tInfo info;
    cin >> info.nSupermercados >> info.nProductos;
    vector<int> supermercado;
    vector<int> marcaje(info.nSupermercados, 0);
    vector<int> minimosAcumulados(info.nProductos, 100000);

    int ret = -1;

    for (int i = 0; i < info.nSupermercados; i++)
    {

        for (int j = 0; j < info.nProductos; j++)
        {

            cin >> aux;
       
            supermercado.push_back(aux);

            minimosAcumulados[j]= min(aux, minimosAcumulados.at(j));

        }
        info.lista.push_back(supermercado);
        supermercado.clear();
    }

    for(int i=info.nProductos-2;i>=0;i--){

        minimosAcumulados[i]+=minimosAcumulados[i+1];
    }

    info.minimosAcumulados=minimosAcumulados;
    resolver(info, 0, ret, marcaje);

    if (ret == -1)
        cout << "Sin solución factible\n";
    else
        cout << ret << "\n";
}

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        resuelveCaso();
}