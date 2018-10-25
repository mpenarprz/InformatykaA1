#include <iostream>
#include <string>
using namespace std;

typedef struct Zwierze {
    string gatunek;
    string alias;
};

/*
Kompiluje z typedefami? :P
*/
typedef struct Student {
    string name;
    string surname;
    string age; // Age jest złego typu
    struct Zwierze pet; // Tu jest coś podejrzanego, ja bym pominął słowo struct w tej linii
};

/*
PO REFACTORZE:
*/
struct Zwierze {
    string gatunek, alias;
};
 struct Student {
    string name, surname, age;
    Zwierze pet;
};
/*
KONIEC RECATORU:
*/

void findStudents(Student *students, int numberOfStudents, string species); // spacje po * 
void findStudents(Student * students, int numberOfStudents, string species); // like this

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
Dokładnie o to chodziło, tylko pilnować nawiasów
*/
void findStudents(Student *students, int numberOfStudents, string species) {
    for (int i = 0; i < numberOfStudents; ++i) {
        if (students[i].pet.gatunek == species)
            cout << students[i].surname << " " << students[i].name << endl;
    }
}

/*
Like this:
*/
void findStudents(Student *students, int numberOfStudents, string species) {
    for (int i = 0; i < numberOfStudents; ++i) {
        if (students[i].pet.gatunek == species){
            cout << students[i].surname << " " << students[i].name << endl;
		}
    }
}