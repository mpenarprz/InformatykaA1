#include <iostream>

using namespace std;

int n;

int main()
{
int dodawanie(n);

if(n==0) {return 0;}
else
{
    if(n==1){return 1;}
    else {return n+dodawanie(n-1)}

}
    return 0;
