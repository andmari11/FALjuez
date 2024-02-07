#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct tSol
{

    int nPartidos = 0, nVeces = 0, haceCuanto = 0;
};

tSol resolver(vector<int> const &v)
{

    int rachaActual = 0;
    tSol ret;

    for (int i = 0; i < v.size(); i++)
    {
        ret.haceCuanto++;

        if (v[i] > 0)
        {

            rachaActual++;
        }
        if (v[i] >= 0)
        {

            if (rachaActual == ret.nPartidos)
            {
                ret.nVeces++;
                ret.haceCuanto = 1;
            }
            else if (rachaActual > ret.nPartidos)
            {
                ret.nVeces = 1;
                ret.nPartidos = rachaActual;
                ret.haceCuanto = 1;
            }
            rachaActual = 0;
        }
        return ret;
    }

    if (rachaActual == ret.nPartidos)
    {
        ret.nVeces++;
        ret.haceCuanto = 0;
    }
    else if (rachaActual > ret.nPartidos)
    {
        ret.nVeces = 1;
        ret.nPartidos = rachaActual;
        ret.haceCuanto = 0;
    }

    return ret;
}