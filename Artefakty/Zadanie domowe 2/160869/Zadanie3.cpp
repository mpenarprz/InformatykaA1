#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	protected:
		string Name;
		string Surname;
		bool Male;
		string Pesel;

	public:
		Person(string name, string surname, bool male, string pesel)
		{
			Name = name;
			Surname = surname;
			Male = male;
			Pesel = pesel;
		}
		void hello()
		{
			cout << "Witam, nazywam sie " << Surname << " " << Name << endl << endl;
		}
};

class Teacher : public Person
{
	private:
		string Subject;
		string Title;
	public:
		Teacher(string name, string surname, bool male, string pesel, string subject, string title) : Person(name, surname, male, pesel)
		{
			Subject = subject;
			Title = title;
		}
		void hello()
		{
			cout << "Witam, nazywam sie " << Surname << " " << Name << ", jestem " << Title << " i chetnie wykladam " << Subject << endl << endl;
		}
};

class Pupil : public Person
{
	private:
		char WhatClass;
		int Term;
		string Profile;
	public:
		Pupil(string name, string surname, bool male, string pesel, char whatClass, int term, string profile) : Person(name, surname, male, pesel)
		{
			WhatClass = whatClass;
			Term = term;
			Profile = profile;
		}
		void hello()
		{
			cout << "Witam, jestem " << Name << " i lubie kebaby" << endl << endl;
		}
};

int main()
{
	Person A("Sebastian", "Gdyk", 1, "12312312312");
	A.hello();
	Teacher B("Norbert", "Skrzek", 1, "32132131232", "Matematyka, Informatyka", "Profesor");
	B.hello();
	Pupil C("Joanna", "Skrzek", 0, "23123123123", 'E', 2, "Elektryk");
	C.hello();

	cout << endl;

	Person D("Mariusz", "Cwel", 1, "45345345345");
	Person E("Patrycja", "Wanat", 0, "34534534534");
	Person F("Kamil", "Bak", 1, "53453453453");

	vector<Person> data;
	data.push_back(A);
	data.push_back(B);
	data.push_back(C);
	data.push_back(D);
	data.push_back(E);
	data.push_back(F);

	for (int i = 0; i < data.size(); i++)
	{
		data[i].hello();
	}
}
