// Exercise 3

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	protected:
		string _name;
		string _surname;
		char _sex;
		string _pesel;
	public:
		Person(string name, string surname, char sex, string pesel)
		{
			_name = name;
			_surname = surname;
			_sex = sex;
			_pesel = pesel;
		}
		/*
		Na przyszłość: do polimorfizmu brakuje jedynie słowa virtual:
		virtual void hello()
		*/
		void hello()
		{
			cout << "Witam, nazywam sie " << _surname << " " << _name << endl;
		}
};

class Teacher : public Person
{
	private:
		string _subject;
		string _title;
	public:
	/*
	Bardzo elegancko napisany konstruktor,
	z jednym zastrzeżeniem że mowa była o liście przedmiotów
	*/
		Teacher(string name, string surname, char sex, string pesel, string subject, string title) : Person(name, surname, sex, pesel)
		{
			_subject = subject;
			_title = title;
		}
		void hello()
		{
			cout << "Witam, nazywam sie " << _surname << " " << _name << ", jestem " << _title << " i chetnie wykladam " << _subject << endl;
		}
};

class Pupil : public Person
{
	private:
		int _classNumber;
		string _term;
		string _profile;
	public:
	/*
	Bardzo elegancko napisany konstruktor
	*/
		Pupil(string name, string surname, char sex, string pesel, int classNumber, string term, string profile) : Person(name, surname, sex, pesel)
		{
			_classNumber = classNumber;
			_term = term;
			_profile = profile;
		}
		void hello()
		{
			cout << "Witam, jestem " << _name << " i lubie kebaby" << endl;
		}
};

/*
Nic dodać nic ująć
*/

int main()
{
	Person B("Daniel", "Pajak", 'M', "97031202299");
	B.hello();
	Teacher D("Daniel", "Pajak", 'M', "97031202299", "matematyka, fizyka, informatyka", "inzynier");
	D.hello();
	Pupil C("Daniel", "Pajak", 'M', "97031202299", 1, "letni", "mechanik");
	C.hello();

	Person E("Radek", "Lach", 'M', "98031222299");
	Person F("Lukasz", "Pajak", 'M', "98031222259");
	Person G("Diana", "Benko", 'F', "98021233269");
	Person H("Patryk", "Benko", 'M', "99022033259");

	vector<Person> data;
	data.push_back(B);
	data.push_back(E);
	data.push_back(F);
	data.push_back(G);
	data.push_back(H);
	for (int i = 0; i < data.size(); i++)
	{
		data[i].hello();
	}
}