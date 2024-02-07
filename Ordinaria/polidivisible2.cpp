#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool resuelve(long long n, int &i);
bool solucion();

int main() {


	long long numero;
	while (cin >> numero) {
		int i = 0;
		if (resuelve(numero, i))
			cout << "POLIDIVISIBLE" << "\n";
		else
			cout << "NO POLIDIVISIBLE" << "\n";
	}

	return 0;
}

bool solucion(){

    long long numero;
    int i = 0;


    if(!cin){

        return false;
    }

	if (resuelve(numero, i))
		cout << "POLIDIVISIBLE" << "\n";
	else
		cout << "NO POLIDIVISIBLE" << "\n";

}


bool resuelve(long long n, int &i) {
	if (n / 10 == 0) {
		i++;
		return n % i == 0;
	}

	bool p = resuelve(n / 10, i);
	i++;
	return p && n % i == 0;
}