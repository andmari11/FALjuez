#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



  long long int elevame(  long long int x,  long long int n){


    if(n==0){

        return 1;
    }
	else
    {
        long long int var = elevame(x, n / 2);
		if (n % 2 == 0)
        { 
			return (var * var) % 31543;
		}
		else 
        {
			return ((x % 31543) * var * var) % 31543;
		}

    }
}



bool resuelveCaso() {
	long long int x;
	int n;
	cin >> x >> n;
	if (x == 0 and n == 0) 
    return false;
	
    
    cout << elevame(x, n) << '\n';
	
    return true;
}
int main() {
    
	while (resuelveCaso());

}
