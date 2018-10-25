#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// tego nie sprawdzam

struct DDT
    {
        string Gatunek;
        string Alias;
    };

int main()
{
    DDT Zwierze[10];
    cout<<"Wprowadz dane. \n";

    for(short i=0; i<10; i++)
    {
        cout<<"Podaj gatunek";
        cin>>Zwierze[i].Gatunek;
        cout<<"Podaj Alias";
        cin>>Zwierze[i].Alias;
    }
    cout<<endl<<"Oto rezultat wprowadzonych danych: "<<endl;
    for(short licz=0; licz<10; licz++)
    {
        cout<<"Zwierze"<<licz+1<<"Gatunek"<<Zwierze[licz].Gatunek<<" Alias "<<Zwierze[licz].Alias<<endl;
    }
    getch();

    return 0;
}
