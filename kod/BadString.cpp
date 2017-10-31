#include <iostream>
#include <cstring>
#include <windows.h>

typedef char character;
class StringBad {
private:
	character * str;
	int len;
	static int num_strings;
public:
	StringBad(const character * s) {
		len = std::strlen(s);
		str = new character[len + 1];
		std::strcpy(str, s);
		num_strings++;
		std::cout << num_strings << ": \"" << str << "\" - obiekt utworzony.\n";
	}
	StringBad() {
		len = 4;
		str = new character[4];
		std::strcpy(str, "C++");
		num_strings++;
		std::cout << num_strings << ": \"" << str << "\" - obiekt domyślny utworzony.\n";
	}
	~StringBad() {
		std::cout << "\"" << str << "\" - obiekt usunięty,";
		--num_strings;
		std::cout << "są jeszcze " << num_strings << ".\n";
		delete[] str;
	};
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st) {
		os << st.str;
		return os;
	}
};

int StringBad::num_strings = 0;

void callVal(StringBad val){
    std::cout << "Obiekt przekazany przez wartość:" << std::endl;
    std::cout << "\"" << val << "\"" << std::endl;
}

void callRef(StringBad & val){
    std::cout << "Obiekt przekazany przez referencje:" << std::endl;
    std::cout << "\"" << val << "\"" << std::endl;
}

int main()
{
    /*
    Wymagane dla polskich znaków na Winzgrozie
    */
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "65001");

	using std::cout; using std::endl;
	{
		cout << "Zaczynamy blok" << endl;
		StringBad msg1("Witaj na kursie Informatyka");
		StringBad msg2("Programujemy w C");
		StringBad msg3("Kiedyś będziemy uczyć się sieci");

		cout << "Pierwsza wiadomość: " << msg1 << endl;
		cout << "Druga wiadomość: " << msg2 << endl;
		cout << "Trzecia wiadomość: " << msg3 << endl << endl;

		callRef(msg1);
		cout << "Pierwsza wiadomość raz jeszcze: " << msg1 << endl << endl;

		callVal(msg2);
		cout << "Druga wiadomość raz jeszcze: " << msg2 << endl << endl;

		cout << "Spróbujmy coś innego, inicjalizacja innym obiektem: " << endl;
		StringBad evenWorse = msg3;
		cout << "Trzecia wiadomość z innej zmiennej: " << evenWorse << endl << endl;

		cout << "Ciśniemy dalej: przypisanie do innego obiektem: " << endl;
        StringBad worst;
		cout << "I teraz przypisanie!" << endl;
        worst = msg1;
		cout << "Pierwsza wiadomość z innej zmiennej: " << worst << endl << endl;

		cout << "I wychodzimy z bloku" << endl;
	}
	cout << "Koniec main";
	return 0;
}
