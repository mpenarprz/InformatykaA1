#include <iostream>

using namespace std;

/*
To żadna funkcja.
*/
int main()
{
    cout << "Ktory wyraz ciagu Fibonacciego mam wyznaczyc?" << endl;
    int ktory;
    cin>>ktory;

	/*
	To pod spodem trzeba przenieść do funkcji
	zaznaczmy całość stąd
	*/
    int pierwszy=0;
    int kolejny;
    int drugi = 1;

	
    if(ktory==0)
    {
        cout<<"Twoj wyraz to: "<<0;
    }
    else
    {
        if(ktory==1)
        {
            cout<<"Twoj wyraz to: "<<1;
        }
        else{
            for(int i = 0; i<ktory-1; i++)
            {
                kolejny = pierwszy + drugi;
                pierwszy = drugi;
                drugi = kolejny;
            }
                cout<<"Twoj wyraz to: "<<kolejny;
            }
    }
	/*
	Kończymy zaznaczanie
	*/
    return 0;
}

/*
Tworzymy sygnature
*/
int toMojaŁadnieNazwanaFunkcjaLiczącaFibonacciegoDlaPewnejLiczbyKtoraNazywamKTORY(int ktory){
	// Wklejamy
    if(ktory==0)
    {
        // Ten fragment: cout<<"Twoj wyraz to: "<<0;
		// Zamieniamy na:
		return 0;
    }
    else
    {
        if(ktory==1)
        {
			// Ten fragment: cout<<"Twoj wyraz to: "<<1;
			// Zamieniamy na:
			return 1;
        }
        else{
            for(int i = 0; i<ktory-1; i++)
            {
                kolejny = pierwszy + drugi;
                pierwszy = drugi;
                drugi = kolejny;
            }
			
			// Ten fragment: cout<<"Twoj wyraz to: "<<kolejny;
			// Zamieniamy na:
			return kolejny;
		}
    }
}

/*
Przykłąd użycia:
*/
int main(){
	 cout << "4-ty wyraz to: " << toMojaŁadnieNazwanaFunkcjaLiczącaFibonacciegoDlaPewnejLiczbyKtoraNazywamKTORY(4) << std::endl;
	 cout << "5-ty wyraz to: " << toMojaŁadnieNazwanaFunkcjaLiczącaFibonacciegoDlaPewnejLiczbyKtoraNazywamKTORY(5) << std::endl;
	 cout << "1-ty wyraz to: " << toMojaŁadnieNazwanaFunkcjaLiczącaFibonacciegoDlaPewnejLiczbyKtoraNazywamKTORY(1) << std::endl;
	 cout << "10-ty wyraz to: " << toMojaŁadnieNazwanaFunkcjaLiczącaFibonacciegoDlaPewnejLiczbyKtoraNazywamKTORY(10) << std::endl;
}