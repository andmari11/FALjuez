#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct tCiudad
{
    int maxPersonas, minPersonas, sueldoPPersona;
};

struct tInfo
{
    int nCiudades, nPatrullas, sueldoReserva;
    vector<tCiudad> ciudades;
    vector<int> patrullas;
};

struct tSol
{
    int nPersonas = 0, sueldoTotal = 0;
};

bool esPrometedor(/*const tInfo &info, tSol solParcial, vector<int> &distribucionActual, tSol &sol, vector<bool> &marcajePatrulla, int k = 0*/)
{

    bool ret = true;

    return ret;
}

void resolver(const tInfo &info, tSol solParcial, vector<int> &distribucionActual, tSol &sol, int k = 0, int i = 0)
{   

    // i--->patrullas
    // k--->ciudades

    // cogemos
    distribucionActual[k] += info.patrullas[i];
    solParcial.nPersonas += info.patrullas[i];
    solParcial.sueldoTotal += info.ciudades[k].sueldoPPersona * info.patrullas[i];

    if (info.ciudades[k].maxPersonas >= distribucionActual[k])
    {
        int kPlus=info.ciudades[k].minPersonas <= distribucionActual[k];

        if (k+kPlus== info.nCiudades  and i+1==info.nPatrullas)
        {
            if (solParcial.sueldoTotal < sol.sueldoTotal or sol.nPersonas==-1)
                sol = solParcial;
        }

        // multiplicar los nSiguientesMInimosGuardas * suPrecio
        else if (esPrometedor() and k+kPlus < info.nCiudades and i+1<info.nPatrullas)
        {
            resolver(info, solParcial, distribucionActual, sol, k+kPlus, i+1);
        }
    }

    distribucionActual[k] -= info.patrullas[i];
    solParcial.nPersonas -= info.patrullas[i];
    solParcial.sueldoTotal -= info.ciudades[k].sueldoPPersona * info.patrullas[i];





    // no cogemos
    solParcial.sueldoTotal += info.sueldoReserva * info.patrullas[i];
        if (k== info.nCiudades  and i+1==info.nPatrullas)
        {
            if (solParcial.sueldoTotal < sol.sueldoTotal)
                sol = solParcial;
        }

        // multiplicar los nSiguientesMInimosGuardas * suPrecio
        else if (esPrometedor() and k < info.nCiudades and i+1<info.nPatrullas)
        {
            resolver(info, solParcial, distribucionActual, sol, k, i+1);
        }

    solParcial.sueldoTotal -= info.sueldoReserva * info.patrullas[i];
}

void resuelveCaso()
{

    tInfo info;
    int aux;
    cin >> info.nCiudades >> info.nPatrullas >> info.sueldoReserva;

        vector<tCiudad> ciudades(info.nCiudades);


    for (tCiudad& c:ciudades)
    {
        cin>>c.minPersonas;
    }

    for (tCiudad& c:ciudades)
    {
        cin>>c.maxPersonas;
    }
    for (tCiudad& c:ciudades)
    {
        cin>>c.sueldoPPersona;
    }

    info.ciudades=ciudades;
    for (int i = 0; i < info.nPatrullas; i++)
    {

        cin >> aux;
        info.patrullas.push_back(aux);
    }

    vector<int> distribucion(info.nCiudades, 0);
    tSol ret = {-1, -1};
    resolver(info, {0, 0}, distribucion, ret);

    if (ret.nPersonas == -1)
    {

        cout << "NO\n";
    }
    else
    {

        cout << ret.sueldoTotal << "\n";
    }
}

int main()
{
    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++)
        resuelveCaso();
}