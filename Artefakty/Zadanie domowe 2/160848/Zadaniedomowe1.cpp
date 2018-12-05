#include <iostream>
#include <cmath>
using namespace std;

/*
To coś nowego :P
*/

/*
	1) Nie podoba mi się tu zwracany typ, lepiej: double
*/
void taylor(int x, int n)
{
	double sin = 0;			// Dobrze dobrany typ wyjściowy
	int silnia = 1;
	for (int k = 0; k <= n; k++)
	{    
		
		sin += (pow(-1.0, k)/silnia)*pow(x,(2.0*k+1));
		/*
				2) Tu zrobiłaś nieortodoksyjną rzecz - zmieniłaś wartość k (tzw. zmienną iteracyjną, czyli stanowiącą bazę działania pętli) w ramach pętli - na ogół jest to bardzo niebezpieczne...
				ponieważ zaburza pamięć programisty kiedy myśli 'na którym przebiegu jestem?'
				Tu to zadziała całkiem sexy, bo zaraz później robisz cofnięcie do k--
		*/
		k++;
		silnia *= (2*k) * (2*k + 1) ;
		k--;
		
	}      
	cout << sin << endl;
	/*
	1) I tu zwrócić wartość: sin, a nie wypisywać na konsole (return sin;)
	Refleksja:
	Wypisywanie na konsole jest istotne dla człowieka - to tylko jeden ze sposobów prezentacji wyników działania programu.
	W rzeczywistości z funkcji sinusa chciałabyś skorzystać w bardziej złożonym programie np. liczącym jakieś śmieszne rzeczy z trójkątami w roli głównej
	Dlatego funkcje na ogół powinny zwracać wartości, a nie korzystać z słowa void
	*/

}
int main()
{
	
	/*
	Jakbyś miała sygnaturę: double taylor(int x, int n)
	To mogłabyś robić wywołania:
	double x = taylor(3,6);
	Albo:
	double y = taylor(taylor(10,1), 4);
	
	Gdy masz void nie możesz nic z tym zrobić....
	tylko:
	taylor(3,6);
	*/
	taylor(3,6);
	system("pause");
}

/*
Pomimo tego że zrobiłaś niebezpicznie k++ / k-- w środku pętli for bazującej na k...
Pomimo braku wartości zwracanej
To skopałaś d**y wszystkim wcześniejszym oddającym zadanie - Twoje rozwiązanie jest diablo-szybkie
Na ogół pozostali wyliczali silnie osobno w każdym przebiegu pętli
*/