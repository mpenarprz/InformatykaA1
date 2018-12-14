#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
/****************
	CZEŚĆ CZYTANA 1/4:
	Tu dodajemy nową, ciekawą bibliotekę, której jedyne zastosowanie to wypisywanie liczby
	w binarnym formacie. Nie musimy wiedzieć co dokładnie w środku jest.
	Tak naprawdę ta biblioteka potrzebna jest tylko dla funkcji:
	void print();
*****************/
#include <bitset>  

/****************
	CZEŚĆ CZYTANA 2/4:
	Nie modyfikujemy tej klasy - jedynie się z nią zapoznajemy.
	Modyfikacja na własną odpowiedzialność :P
*****************/
class EncodedNumber {
private:
	/*
	Tu trzymamy oryginalną wartość
	*/
	int _value;				
protected:
	/*
	Tu trzymamy liczbę zakodowaną w odpowiednim formacie na 32-bitach
	*/
	unsigned int _encoded;
	/*
	Abstrakcyjna funkcja konwersji:
		originalValue - to oryginalna przekazana liczba
		absoluteValue - to wartość bezwględna tej liczby, przekazana jako unsigned int
	*/
	virtual unsigned int encode(int originalValue, unsigned int absoluteVal) = 0;
public:
	/*
	Konstruktor przyjmujący 1 wartośc typu INT
	*/
	EncodedNumber(int value) : _value(value){}

	/*
	Metoda konwertujaca przekazaną liczbę oraz wypisująca wartości
	*/
	void print() {
		_encoded = encode(_value, _value > 0 ? _value : -_value);
		std::cout << std::dec << "dec: " << _value
			<< std::hex << " hex: " << _value
			<< std::oct << " oct: " << _value
			<< " binary: " << std::bitset<sizeof(_encoded) * 8>(_encoded) << std::endl;
	}

};

/****************
	CZEŚĆ CZYTANA 3/4:
	Przykładowy encoder dla NBC
*****************/
class NBC : public EncodedNumber {
protected:
	/*
	Implementacja kodowania
	*/
	unsigned int encode(int originalValue, unsigned int absoluteVal) {
		if (originalValue >= 0) 
		{
			return originalValue;
		}
		else {
			std::cout << "! Nie da rady !";
			return 0;
		}
	}
public:
	NBC(int value) : EncodedNumber(value) {}
};

/****************
	CZEŚĆ CZYTANA 4/4:
	Przykładowy encoder dla U1
*****************/
class U1 : public EncodedNumber {
protected:
	/*
	Implementacja kodowania.
	Pamiętamy że w U1 liczby ujemne to inwersja wartości bezwględnej liczby.
	*/
	unsigned int encode(int originalValue,  unsigned int absoluteVal) {
		return originalValue > 0 ? absoluteVal : ~absoluteVal;
	}
public:
	U1(int value) : EncodedNumber(value) {}
};

/*******************************************************
	Zadanie 1: 
	Napisać encoder dla U2
********************************************************/
class U2 : public EncodedNumber {
protected:
	/*
	Ten fragment uzupełnić:
	Podpowiedź: niewiele różni się to od U1
	*/
	unsigned int encode(int originalValue, unsigned int absoluteVal) {
		std::cout << "Nie zaimplementowano" << std::endl;
 		return 0;
	}
public:
	U2(int value) : EncodedNumber(value) {}
};

/*******************************************************
	Zadanie 2:
	Napisać encoder dla ZM
********************************************************/
class ZM : public EncodedNumber {
protected:
	/*
	Ten fragment uzupełnić
	Podpowiedź: pamiętać o operatorach bitowych & | ~.
	W szczególności o |.
	*/
	unsigned int encode(int originalValue, unsigned int absoluteVal) {
		std::cout << "Nie zaimplementowano" << std::endl;
		return 0;
	}
public:
	ZM(int value) : EncodedNumber(value) {}
};

/*******************************************************
Zadanie 3:
Napisać encoder dla BIAS
********************************************************/
class BIAS : public EncodedNumber {
private:
	int _bias;	// Tu mamy nowe pole - bias
protected:
	/*
	Ten fragment uzupełnić
	Podpowiedź: pamiętamy o polu _bias!
	*/
	unsigned int encode(int originalValue, unsigned int absoluteVal) {
		std::cout << "Nie zaimplementowano" << std::endl;
		return 0;
	}
public:
	BIAS(int value, int bias) : EncodedNumber(value), _bias(bias){}
};

/****
	Tego nie zmieniamy
*****/
int main(){
	int const RANGE = 128;

	std::cout << std::endl << "Kodowanie NBC:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		NBC(i).print();
	}

	std::cout << std::endl << "Kodowanie U1:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		U1(i).print();
	}

	std::cout << std::endl << "Kodowanie U2:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		U2(i).print();
	}

	std::cout << std::endl << "Kodowanie ZM:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		ZM(i).print();
	}

	std::cout << std::endl << "Kodowanie BIAS -64:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		BIAS(i, -64).print();
	}

	std::cout << std::endl << "Kodowanie BIAS 64:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		BIAS(i, 64).print();
	}

	std::cout << std::endl << "Kodowanie BIAS 10:" << std::endl;
	for (int i = -RANGE; i < RANGE; ++i) {
		BIAS(i, 10).print();
	}
    return 0;
}

