#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct School
{
    string patron;
    vector<Pupil> pupil1; // Dokładnie tak
    vector<Teacher> teacher; // Dokładnie tak

};


struct Pupil
{
    string name,surname,sex;
};

struct Teacher
{
    string name,surname,sex
    };
	
/* To nie wygląda jakby było zgodne z definicją...
Dla x == 0 zwraca 1.
Dla x == -1 zwraca 1.
Dla większych x>3 zwraca poprawne wyniki :P
*/

 int funkcja(int x)
 {

 if (x<3)
    return 1;
 else

 return funkcja(x-2) + funkcja(x-1); 
 }



int main()
{
    int x;
    cout<< "Podaj wyraz ciagu Fibonacciego, ktory chcesz wliczyc: ";
 cin>>x;
  cout << endl << x << "wyraz ciagu przyjmuje wartosc: "<< funkcja(x)<< endl;
    return 0;
}
