#include <iostream>
#include <string>
#include <vector>

/*
	Zadanie 1
*/
struct Pupil {
	std::string name, surname, gender;
};

struct Teacher {
	std::string name, surname, gender;
};

struct School {
	std::string patron;
	std::vector<Pupil> pupils;
	std::vector<Teacher> teachers;
};

/*
	Zadanie 2
*/

/*
	Dłuższa wersja funkcji rekursywnej
*/
int fibonacciRec(int n) {
	if (n < 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

/*
	Skrócona wersja funkcji rekursywnej
*/
int fibonacciRec2(int n) {
	return n < 0 ? 0 : (n == 1 ? 1 : fibonacciRec(n - 1) + fibonacciRec(n - 2));
}

/*
	Wersja iteracyjna
*/
int fibonacciIterative(int n) {
	int current = 0, next = 1, temp;
	if (n < 0) {
		return current;
	}
	if (n == 1) {
		return next;
	}
	for (int i = 2; i <= n; ++i) {
		temp =  current + next;
		current = next;
		next = temp;
	}
	return next;
}

/*
	Zadanie 3:
*/
std::vector<int> fibonacciVec(int maxN) {
	std::vector<int> output;
	for (int i = 0; i < maxN; ++i) {
		output.push_back(fibonacciRec2(i));	//Na koniec wektora dołączamy kolejne liczby fibonacciego
	}
	return output;
}

void main(){
	int countOfNumbers = 17;
	std::vector<int> fibonacciVector = fibonacciVec(countOfNumbers); // Zwracamy wektor wywołując funkcję z trzeciego zadania
	for (int i = 0; i < countOfNumbers; ++i) {
		std::cout << "Fibonacci wyraz no. " << i << " to: " << fibonacciRec(i) << " / " << fibonacciRec2(i) << " / " << fibonacciIterative(i) << " / " << fibonacciVector[i] << std::endl;
	}
