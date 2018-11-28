#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

unsigned int Suma_licz(unsigned int x)		//³adny typ w parametrze
{
    unsigned int suma=0;
    for(int i=1; i<=x; i++)
    {
        suma =suma+i;			// mo¿na skróciæ do suma += i;
    }
    return suma;
}


unsigned int RSuma_liczb(unsigned int R)
{
    if (R<=0)
    {
        return 0;
    }
     return R + RSuma_liczb(R-1);

}

unsigned int Silnia(unsigned int S)
{
    unsigned int wynik=1;
    for (int i=1; i<S; i++)
    {
        wynik = wynik * i;
    }
    if (wynik==0)
    {
        return 1;
    }
    return wynik;
}

double RSilnia( double H)
{
    if(H == 0)
    {
     return 1;
    }
    else if (H<0)
    {
        cout << "nie ma ujemnych wyrazów silni" << endl; // Zamiar szlachetny, wykonanie z³e - dalej wejdziesz w return i zabraknie Ci pamiêci.
    }
    return H * RSilnia(H - 1);
}






int main()
{
    cout << "Hello world!" << endl;
    cout << Suma_licz(0);
    cout << RSuma_liczb(6);

    int zmienna
    vector<int> tablica;
    do
    {
        cin >> zmienna;
        if(zmienna >=0 && zmienna < 5000)
        {
            tablica.push_back(zmienna);
        }

    }
    while(zmienna != -1);
    sort(tablica.begin(), tablica.end());
    for (auto item : tablica)		//Yuppie
    {
        cout << item << "/n"
    }

    return 0;

}
