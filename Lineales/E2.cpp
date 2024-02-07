#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
P:{v.size()>=0 ^ 0<=k<v.size()}
@return para todo i: k<i<v.size(): i>max(v, 0, k)

max(v, a, b) return m= para todo i: a<=i<=b: m>=v[i]

I1:{0<=i<=k ^ mayor=max(v, 0, k)}
I2:{k<i<v.size() ^ ret=v[i]<max}


*/

bool resuelveCaso()
{

    long long nElementos, k;

    cin >> nElementos >> k;

    if (nElementos == 0)
    {

        return false;
    }

    vector<long long> v;
    long long aux;

    for (long long i = 0; i < nElementos; i++)
    {

        cin >> aux;
        v.push_back(aux);
    }

    bool ret = true;
    long long i = 0;
    long long max = v[0];

    while (i < nElementos and ret)
    {
        if (i <= k and v[i] > max)
        {

            max = v[i];
        }
        else if (i > k and v[i] <= max)
        {
            ret = false;
        }

        i++;
    }

    if (ret)
        cout << "SI"
             << "\n";

    else
        cout << "NO"
             << "\n";
    return true;
}

int main()
{

    int ncasos = 0;

    cin >> ncasos;

    for (int i = 0; i < ncasos; i++)
        resuelveCaso();
}