#include <iostream>

using namespace std;

int main()
{
    cout << "Ile kolejnych liczb mam zsumowac?" << endl;
    int ile;
    cin>>ile;

    int pierwsza=1, druga=2, suma=0;

if(ile==0)
{
  suma=0;
}
else
{
    if(ile==1)
    {
        suma=1;
    }
    else
    {
        for (int i=0; i<ile-1; i++)
        {
            suma = pierwsza + druga;

            pierwsza = suma;

            druga = druga + 1;
        }
    }
}
    cout<<"Suma wynosi: "<<suma<<endl;

    return 0;
}
