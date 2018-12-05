#include <iostream>
#include <cmath>

using namespace std;

int silnia(int x)
{
    if (x==0)
    {
        return 1;
    }
    return x*silnia(x-1);
}

long double taylor(int x)
{
    double y=3.14;

    if (x==0)
    {
        return y;
    }
    return (pow(-1,x)/silnia(2*x+1))*pow(y, 2*x+1) + taylor(x-1);
}

int main()
{
        cout << taylor(7) << endl;
}
