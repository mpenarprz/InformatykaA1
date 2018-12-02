/***********
W tym projekcie pokazujemy spektrum możliwości związanych z obiektowością w C++ 
************/

#include "stdafx.h"
#include <iostream>
#include <string>

/****
1) Klasy i struktury w C++ są pojęciami równoważnymi.
Oba pojęcia odpowiadają za definicję typu.
Konwencją (nieformalną umową) wsród programistów jest trzymanie w strukturach tylko danych.
W strukturach/klasach możemy zdefiniować następujące elementy:
	- funkcje (tzw. metody) - odpowiadające za zachowanie obiektów
	- pola - odpowiadające za przechowywanie stanu obiektów, czyli dane
Z pojęciem klasy związane są modyfikatory dostępu:
	- private - metody/pola są dostępne tylko wewnątrz klasy
	- protected - metody/pola są dostępne tylko wewnątrz klasy oraz w klasach pochodnych
	- public - metody/pola w dowolnym miejscu gdzie mamy dany obiekt danej klasy

Jedyna różnica pomiędzy strukturami, a klasami w C++ dot. modyfikatorów dostępu.
W klasach domyślnym modyfikatorem jest private.
W strukturach domyślnym modyfikatorem jest public.

Stąd równoważność klasy pod spodem: MyFirstClass oraz MyFirstStructure
****/
class MyFirstClass {
public:
	int a, b, c, d;
};

class MyFirstStructure {
	int a, b, c, d;
};

/*
Lub równoważność klasy pod spodem: MySecondClass oraz MySecondStructure
*/

class MySecondClass {
	int a, b, c, d;
};

class MySecondStructure {
private:
	int a, b, c, d;
};

/*
	W dalszej części rozważać będziemy tylko klasy.
*/

/****
2) Paradygmat (styl) obiektowy pozwala nam na nałożenie ograniczeń (warunków) na użytkowanie Klasy.
Dzięki temu:
	a) programista klasy może zagwarantować dostarczenie pewnej poprawnie działającej funkcjonalności.
	b) użytkownik ma gwarancje poprawnego funkcjonowania klasy (po spełnieniu pewnych kryteriów)
Pierwszym ograniczeniem jest modyfikacja poziomu dostępu (private, protected, public).
Dla naszych dwóch klas zdefiniowanych w 1):  MyFirstClass, MySecondClass - przynosi ona następujące rezultaty.
****/
void rangeModifiers() {
	MyFirstClass firstObject;					// Powołano do życia nowy obiekt klasy MyFirstClass o nazwie firstObject
	firstObject.a = 1;							// Mogę odwołać się do pola 'a', ponieważ ma modyfikator 'public'
	firstObject.b = firstObject.c = 2;			//Tak samo 'b', tak samo 'c'

	MySecondClass secondObject;					// Powołano do życia nowy obiekt klasy MySecondClass o nazwie secondObject
	// secondObject.a = 1;						To się nie skompiluje, bo w definicji MySecondClass pole 'a' zostało oznaczone jako prywatne
}

/****
3) Istotną funkcjonalnością klas jest możliwość definiowania metod (funkcji)
Załóżmy że mamy klasę BadClock która będzie umożliwiać wyświetlenie informacji na temat czasu.
****/
class BadClock {
private:
	unsigned short godzina, minuta;
public:
	std::string show() {
		return std::to_string(godzina) + ":" + std::to_string(minuta);
	}
};

/*
Mając obiekt klasy BadClock, możemy z wykorzystaniem notacji kropkowej wywołać poza definicją klasy publiczne metody.
Taka realizacja klasy BadClock powoduje że nie wiadomo jak jest stan początkowy godziny/minuty, obrazuje to wywołanie poniższej funkcji:
*/
void testBadClock() {
	BadClock clock;
	std::cout << clock.show() << std::endl;		
}

/****
4) Ze względu na problem w 3), drugim BARDZO istotnym ograniczeniem które może zdefiniować programista klasy jest stan początkowy obiektu.
Odpowiadają za to KONSTRUKTORY.
Istotne informacje:
	a) Programista może zdefiniować dowolną liczbę konstruktorów
	b) !!! jeśli żaden konstrukor nie jest zdefiniowany, to kompilator automatycznie wygeneruje tzw. konstruktor domyślny - taki który nie ma żadnych parametrów
	Dlatego linijka:
	BadClock clock;
	Pozwoliła na kompilacje.
Konstruktory przypominają funkcję, ale mają pół-"sztywny" format: 
	* nazwa konstruktora to zawsze nazwa klasy
	* lista parametrów jest dowolna
	* dowolne dwa konstruktory muszą różnić się co do sygnatury
	* konstruktory nic nie zwracają

Załóżmy że poprawimy BadClock: chcemy dać możliwość użytkownikowi wykonstruowania poprawionych obiektów klasy SlightlyBetterClock na pewien stan początkowy
****/

class SlightlyBetterClock {
private:
	unsigned short godzina, minuta;
public:
	// Triumfalny konstruktor
	SlightlyBetterClock(int godz, int min) {
		godzina = godz;
		minuta = min;
	}

	std::string show() {
		return std::to_string(godzina) + ":" + std::to_string(minuta);
	}
};

/*
Teraz powołanie obiektu SlightlyBetterClock zawsze wymaga podania godziny oraz minuty
*/
void testSlightlyBetterClock() {
	SlightlyBetterClock clock(15, 20);
	std::cout << clock.show() << std::endl;
	// SlightlyBetterClock clock(); to się nie skompiluje teraz, bo nie ma konstruktora domyślnego
	// SlightlyBetterClock clock; to się nie skompiluje teraz, bo nie ma konstruktora domyślnego
}

/****
5) Dwa interesujace skróty dot. konstruktorów to 
	a) wywołania jednego konstruktora z poziomu drugiego
	b) wywołania konstruktorów pół wchodzących w skład klasy
Załóżmy że chcemy użytkownikowi dać możliwość powołania obiektu zegarka bez podawania godziny oraz minuty.
Domyślny zegarek będzie utworzony z godziną 00:00... (np. moja mikrofalówka po każdej przerwie w dostawie prądu ustawia się na taką godzinę)
Pokażemy jak to zrobić w klasie ImprovedClock za pomocą skrótów a) oraz b)
****/

class ImprovedClock {
private:
	unsigned short godzina, minuta;
public:
	// Nasz podstawowy konstruktor, użyjemy tutaj inicjalizacji pól - to jest skrót B)
	// Składania wygląda tak że po parametrach umieszczamy znak : po czym po przecinku nazwa_pola(wartość)
	ImprovedClock(int godz, int min) : godzina(godz), minuta(min){}

	// Nasz drugi "domyślny" konstruktor reużyjemy tutaj pierwszego konstruktora - skoro ImprovedClock(int godz, int min) ustawia poprawnie godzine, to wywołajmy go z 0,0
	// Składania wygląda tak samo jak linika na górze z tym że umieszczamy nazwę konstruktora z odpowiednimi wartościami
	ImprovedClock() : ImprovedClock(0,0) {}

	std::string show() {
		return std::to_string(godzina) + ":" + std::to_string(minuta);
	}
};

void testImprovedClock() {
	ImprovedClock clock(15, 20);
	std::cout << clock.show() << std::endl;

	ImprovedClock defaultClock;							// Mogę tak zrobić, bo mam konstruktor (), który ustawia godzię/minutę na (0,0)
	std::cout << defaultClock.show() << std::endl;
}

/****
6) Ostatnie ograniczenie jest związane z dziedziczeniem pól,metod pomiędzy klasami.
Jeśli zauważamy część wspólną zachowań/pól pomiędzy dwoma klasami możemy ustalić relację rodzic-dziecko pomiędzy nimi.
Klasę nadrzędną nazywamy klasą bazową.
Klasę podrzędną nazywamy klasą pochodną.
By to zrobić, po nazwie klasy wypisujemy :, modyfikator dostępu (public, protected, private) po czym nazwę klasy która jest klasą bazową.

Gdy zastosujemy dziedziczenie z modyfikatorem:
	* public - to wszystkie pola/metody public oraz protected są włączane do klasy pochodnej bez zmian
	* protected - to wszystkie pola/metody public są włączane do klasy pochodnej jako protected. Pola/metody protected są włączane do klasy pochodnej bez zmian
	* private - to wszystkie pola/metody public/protected są włączane do klasy pochodnej jako private

Pola/metody private NIE są dziedziczone.

By zobrazować mechanizm dziedziczenia, zmodyfikujmy klasę naszego zegara:
	* pola private zmieniamy na gotowe do dziedziczenia - jako pola protected
	* dodajemy operację modulo 24 przy inicjalizacji godziny - żeby nie można było zainicjalizować np. godziny 26, lub minuty 195
****/
class Clock24 {
protected:
	unsigned short godzina, minuta;
public:
	Clock24(int godz, int min) : godzina(godz % 24), minuta(min % 60) {}

	Clock24() : Clock24(0, 0) {}

	std::string show() {
		return std::to_string(godzina) + ":" + std::to_string(minuta);
	}
};

/*
	Załóżmy że chcemy napisać klasę zegara 12 godzinnego, bazując na naszej klasie Clock24.
	Wykonujemy dziedziczenie po Clock24 w nowej klasie ClockAMPM.
	Żeby przystosować nową klasę do działania:
	1) Zmodyfikujemy działanie metody show żeby pokazywała czy godzina jest przed południem (AM) czy po południu (PM)
	2) Zdefiniujemy konstruktory dla klasy ClockAMPM wywołujące konstruktory klasy bazowej
*/
class ClockAMPM : public Clock24 {
public:
	ClockAMPM(int godz, int min) : Clock24(godz, min){}

	ClockAMPM() : Clock24(0, 0) {}

	std::string show() {
		std::string suffix = godzina >= 12 ? "PM" : "AM";
		return std::to_string(godzina > 12 ? godzina - 12 : godzina) + ":" + std::to_string(minuta) + suffix;
	}
};

void newClockTest() {
	Clock24 firstClock = Clock24(13, 50);
	ClockAMPM secondClock = ClockAMPM(13, 50);

	std::cout << firstClock.show()  << std::endl;
	std::cout << secondClock.show() << std::endl;
}


int main()
{
	newClockTest();
}

