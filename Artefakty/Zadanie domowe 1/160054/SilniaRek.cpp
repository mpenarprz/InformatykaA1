#include <iostream>
using namespace std;

int Silnia(int n);

int main() {
    int a;
    cin >> a;
    cout << Silnia(a);
    return 0;
}
int Silnia(int n){
    return n == 0 ? 0 : n == 1 ? 1 : n == 2 ? 2 : Silnia(n - 1) * n; //Sexy 
}