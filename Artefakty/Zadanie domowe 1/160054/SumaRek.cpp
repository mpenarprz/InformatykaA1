#include <iostream>
using namespace std;

int Suma (int n);

int main() {
    int amount;
    cin >> amount;
    cout << Suma(amount);

    return 0;
}
int Suma (int n){
    return n == 0 ? 0 : n == 1 ? 1 : Suma(n - 1) + n; //Sexy
}