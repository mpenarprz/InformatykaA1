#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
protected:
    string _name;
    string _surname;
    string _gender;
    int _pesel;

public:
    Person(string imie, string nazwisko, string plec, int pesel) : _name(imie), _surname(nazwisko), _gender(plec), _pesel(pesel){};

	/*
	Tu można osiągnąć polimorfizm z użyciem słowa kluczowego virtual:
	virtual void hello()
	*/
    void hello(){
        cout << "Witam, nazywam sie" << _surname << " " << _name << endl;
    }
};


class Teacher : public Person{
private:
    vector <string> _listOfSub;
    string _title;

public:
    Teacher(string imie, string nazwisko, string plec, int pesel, vector<string> listaprzed, string tytul) : Person(imie, nazwisko, plec, pesel), _title(tytul) {
        for(int i = 0; i < listaprzed.size(); i++){
            _listOfSub.push_back(listaprzed[i]);
        }
    }

    void hello(){
        cout << "Witam, nazywam sie" << _surname << " " << _name << ", jestem " << _title << " i chetnie wykladam:" << endl;
        for (int i = 0; i < _listOfSub.size() ; ++i) {
            cout << "- " << _listOfSub[i] << endl;
        }
    }
};

class Student : public Person{
private:
    string _class;
    bool _term;
    string _profile;

public:
    Student(string imie, string nazwisko, string plec, int pesel, string klasa, bool semestr, string profil) : Person (imie, nazwisko, plec, pesel), _class(klasa), _term(semestr), _profile(profil) {}

    void hello(){
        cout << "Witam, jestem " << _surname << " " << _name << " i lubie Kebaby" << endl;

    }
};

/*
Nic dodać, nic ująć
*/

int main() {
   // new Student ("Bartlomiej", "Lobos", "Man", 989847365823, "Ostatnia", 1, "Informatyk");

    return 0;
}