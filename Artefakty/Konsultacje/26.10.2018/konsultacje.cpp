// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

// # <- oznacza dyrektywe preprocessora. Czyli przed kompilacją tego pliku, działa specjalny program.
// Najważniejszą dyrektywą jest #include <iostream>
// Drugą najważniejszą dyrektywą jest #include <string>
// Trzecia najważniejszą dyrektywą jest #include <vector>
#include <string>
#include <iostream>


/*
Na lab 2 - pracowaliśmy ze strukturami.
Struktury to są de facto definicje typu danych. 
*/

struct Book { // !!!!!!!!!! Struktura jest typem
	std::string title;
	unsigned int year;
	std::string author;
	unsigned int pages;
};

class Book2 { // To jest to samo co Book, jest ale, ALE o tym dalej
public:
	const char * title; // taka ciekawostka
	unsigned int year;
	char author[100];
	unsigned int pages;
};


// Tę częśc nazywamy SYGNATURĄ: int main(); Sygnatura skłąda się z: [typu zwracanego] [nazwy] ([parametrów])
// Za sygnaturą może być definicja która jest w {}

int main(); 
// Tu wyraziliśmy jedynie informację że w programie gdzieś jest zdefiniowana funkcja int main();
// Nazywa się to deklaracją wyprzedzająca

void f(); // że jest funkcja o nazwie f - która nie ma parametrów i ktora nic nie zwraca (void)

/*
Jeśli funkcja coś zwraca, to robi to za pomocą słowa return;
*/
int wielomian(int x, int a, int b) {
	return a * (x * x) + b;
}

int wielomian(int x) {
	return wielomian(2, 2, 1);
}

std::string cipher(std::string input) {
	for (int i = 0; i < input.length(); ++i) { // taka operacja i = i + 1; jest bardzo częsta. więc jest skrót: i++ lub ++i
		//input[i]++; // input[i] = input[i] + 1; skraca się do ++input[i] / input[i]++/ JEst drugi skrót input[i] += 2 (input[i] = input[i] + 2)
		//if (input[i] > 122) {
		//	input[i] = 'a';
		//}
		//Moja ulubiona rzecz: operator trójargumentowy. Działą tak: [warunek] ? [wartość jeśli prawada] : [wartość jeśli fałsz]; 
		input[i]++;
		input[i] = input[i] > 122 ? 'a' : input[i];
	}
	return input;
}

std::string cipher(std::string input, int key) {
	std::string output = input;
	for (int i = 0; i < (key % 26); ++i) {
		output = cipher(output);
	}
	return output;
}


void findBooksBeforeYear(Book books[], int numberOfBooks, int year) { // !! wierzymy zę numberOfBooks nie powoduje błędów przy użyciu z books
	for (int i = 0; i < numberOfBooks; ++i) {
		if (books[i].year < year) { // <= mniejszy lub równy/ analogicznie > >= / różny != / taki sam == / łaczymy warunki po && (AND) || (OR) 
			std::cout << "Book: " << books[i].title << std::endl;
		}
	}
}

struct MyLameString {
	char znak;
	MyLameString * kolejnyZnak;
};

void printLameString(MyLameString * head) {
	std::cout << head->znak;
	if (head->kolejnyZnak != 0) {
		printLameString(head->kolejnyZnak);
	}
}

void cleanup(MyLameString * node) {
	MyLameString *  next;
	if (node->kolejnyZnak != 0) {
		next = node->kolejnyZnak;
		delete node;
		cleanup(next);
	}
}

int main()
{
	// [typ] [nazwa]; - deklaracja zmiennej
	// Oznacza to powołanie do życia "moje_zmiennej" o typie int (czyli całkowitoliczbowej) - (2^31 - 2^31 -1) (4 bajty)
	int moja_zmienna;
	Book my_book;
	Book2 my_book2;
	std::string my_string; // stanowi modyfikowalny substytut tablicy znaków o dowolnej długości 


	/*
	Do składowych struktur oraz do publicznych składowych klasy możemy odwołać się za pomocą notacji kropkowej.
	*/
	Book my_book_init;
	my_book_init.pages = 1;
	my_book_init.year = 1991;
	my_book_init.title = "Tytul";
	my_book_init.author = "Maciej Penar";

	int my_int_3 = 1; // Chciałbym tak
	int my_int_4 = { 5 };
	int my_array_1[] = { 1, 2, 3 };
	Book my_book_init_2 = { "Tytul", 1, "MP", 1991 };
	Book bookstore[] = {
		{ "Tytul", 1991, "MP", 1 },
		{ "Tytul2", 1995, "MP2", 1 },
		{ "Tytul3", 2000, "MP3", 1 },
		{ "Tytul3", 1500, "MP3", 1 }
	};
 
	/*
		Inne opcje które mamy w [typ] to:
		char - pojedyńczy znak (1 bajt)

		long long - całkowitoliczbowym i po prostu jest większy niz int. long long ma 4 bajty
		unsigned int - czyli to int tylko dodatni: 0-2^32 (też 4 bajty)

		float - typ zmienno-przecinkowy, czyli potrafimy napisać 2.5, to ma 4 bajty (IEEE 754)
		double - typ zmienno-przecinkowy, tylko ma 8 bajtów (IEEE 754)

		Najważniejszym jest typ wskaźnikowy:
		[typ] * [nazwa] - i oznacza ten zapis że deklarujemy ADRES zmiennej.
		np. int * moj_wskaznik;

		Drugi ważny typ to tablica:
		[typ] [nazwa] '[rozmiar]' i oznacza że mamy kilka elementów które możemy ponumerować:
		Tablice rozwiązują nam problem:
		int a, b, c, d, e; 
		Mamy za dużo zmiennych i nie potrafimy zautomatyzować odwołonia do nich.
	*/
	int a, b, c, d, e; 
	a = 5;
	b = 6;
	c = a + b;
	e = a + b + 6;
	
	int tablica[5];
	tablica[0] = 5;
	tablica[1] = 6;
	tablica[2] = tablica[0] + tablica[1];
	tablica[4] = tablica[0] + tablica[1] + 6;

	/* 
	Dygresja odnośnie typu char i inicjalizacji
	*/
	int my_int_decl; // to jest deklaracja
	int my_int = 10; // mogę zainicjalizować  
	my_int = 15;	// mogę też zmienić

	auto my_int_2 = 100;

	// Każdy typ inicjalizuje się osobno
	char my_char = 'a'; // Pojedynczy znak za pomocą jednociapku 
	char my_string_1[100] = "abba"; // Ciąg znaków jako tablica
	auto my_string_2 = "abba"; // Ciąg znaków jako tablica. Przy przypisaniu mogę pominąć liczbę bajtów w tablicy.


	// char ''
	// std::cout - ten gość służy do wyświetalnia (wypisywania na konsole)
	// std::cin - ten gość służy do wczytywania z konsoli (wprowadzania danych)

	/*
	Komentuje ten fragment
	*/
	/*Book important_book;
	std::cout << "How many pages?" << std::endl;
	std::cin >> important_book.pages;
	std::cout << "What year was it written?" << std::endl;
	std::cin >> important_book.year;
	std::cout << "Author?" << std::endl;
	std::cin >> important_book.author;
	std::cout << "Title?" << std::endl;
	std::cin >> important_book.title;

	std::cout << "So it's: " 
		<< important_book.author << " " 
		<< important_book.title  << " " 
		<< important_book.pages << " " 
		<< important_book.year << " "
		<< std::endl;*/

	// for(inicjalizacja; warunek ; modyfikacja)
	// dozwolone jest (ale nie na tych zajęciach) for(;;){}

	// Komentuje ten fragment
	/*for (int i = 0; i < 100; ++i) {
		std::cout << "given " << i << " i get: " << wielomian(i) << std::endl;
	}*/
	//findBooksBeforeYear(bookstore, 4, 1995);

	/*
	Przeładowanie
	*/
	/*wielomian(2);
	wielomian(2, 2, 1);*/

	/*
	Dygresja dot. rzutowania:
	char w = 'a';
	int z = (int)w; // rzutownanie ([typ]) [zmienna/stała]
	int y = (int)'a';
	std::cout << w << " " << z << " " << y;
	*/

	/*
	Szyfrowanie / funkcje
	*/
	/*std::string text;

	std::cout << "Enter text: " << std::endl;
	std::cin >> text;

	std::cout << text  << std::endl;

	std::cout << "CIPHER:" << std::endl;

	for (int i = 0; i < 27; ++i) {
		std::cout << (i % 26) << " " << cipher(text, i) << std::endl;
	}*/

	// 1955
	MyLameString lame_4 = { '5', 0 };
	MyLameString lame_3 = { '5', &lame_4 };
	MyLameString lame_2 = { '9', &lame_3 };
	MyLameString lame_1 = { '1', &lame_2 };

	
	std::cout << "podaj znak / x konczy wprowadzanie" << std::endl;
	MyLameString * head;
	MyLameString * temp;
	MyLameString * old;
	int count = 0;
	char s;
	do {
		temp = new MyLameString{' ', 0};
		std::cin >> s;
		temp->znak = s;
		if (count == 0) {
			head = temp;
		}
		else {
			old->kolejnyZnak = temp;
		}
		old = temp;
		count++;

	} while (s != 'x');

	std::cout << "Wprowadzono: ";
	printLameString(head);

	cleanup(head);
	
	return 0;
}

