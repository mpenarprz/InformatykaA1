#include <iostream>
#include <string>
#include <vector>


using namespace std;


struct School;
struct Pupil;
struct Teacher;

int main()
{
    struct School
    {
    string Patron;
    vector <Pupil> Quantity1; // Typ dobry, nazwa myląca - sugeruje trzymanie LICZBY pod nazwą Quantity1, w rzeczywistości to lista studentów. Można było nazwać: pupils
    vector <Teacher> Quantity2; // Typ dobry, nazwa myląca - sugeruje trzymanie LICZBY pod nazwą Quantity2, w rzeczywistości to lista nauczycieli. Można było nazwać: teachers
    };

    struct Pupil
    {
    string Name;
    string Surename; //Surname
    bool Kobieta;
    };

    struct Teacher
    {
    string Name;
    string Surename //Surname + średnik
    bool Kobieta;
    };

    return 0;
}

//b

int ktora;
long double l1,l2,ls;
int main()
{
    cin >> ktora;
    l1=0;
    l2=1;

	/*
	To powinno być w osobnej funkcji.
	Sama logika wydaje się być nawet ok.
	*/
    if(ktora==0)
    {
        ls=0;
    }

    else if(ktora==1)
    {
        ls=1;
    }

    else
    {
        for(int i=2;i<=ktora; i++)
        {
            ls = l1+l2;
            l1=l2;
            l2=ls;
        }
    }

    cout << ktora << ":  " << ls << endl;


    return 1;

}
