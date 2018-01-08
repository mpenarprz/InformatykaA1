#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <time.h> 
#include <string>

const int THREADS = 7;

std::mutex WRITE_LOCK;

class philosopher {
protected:
	int _id;
	bool _alive, _shouldContinue;
	std::thread _selfAwarness;
	std::mutex * _table;
	/*
	Pomocnicza funkcja do wyświetlania stanu filozofa.
	*/
	void show(std::string activity) {
		WRITE_LOCK.lock();
		std::cout << "Philosopher " << _id << " " << activity << std::endl;
		WRITE_LOCK.unlock();
	}
	void nap() {
		std::this_thread::sleep_for(std::chrono::seconds(rand() % 3 + 1));
	}
	virtual void eat() {
		
		/*
		Biorę moją a potem kolejną łyżkę. Wzięcie łyżki trwa
		*/
		show("is preparing to eat");
		_table[_id].lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); //TU podbijać jakby się nie blokowali
		_table[(_id + 1) % THREADS].lock(); 

		/*
		Jem - to trochę trwa
		*/
		show("will eat");
		std::this_thread::sleep_for(std::chrono::seconds(rand() % 5 + 2));

		/*
		Odkładam moją a potem kolejną łyżkę. Odłożenie nie trwa
		*/
		_table[_id].unlock(); 
		_table[(_id + 1) % THREADS].unlock();
		show("is done with meal");
	}

public:
	philosopher(int id, std::mutex table[]) : _id(id), _table(table) {
		_alive = _shouldContinue = true;
		_selfAwarness = std::thread(&philosopher::live, this);
	};
	~philosopher() {
		_selfAwarness.detach();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	/*
	Pętla życia dla filozofa
	*/
	void live() {
		while (_shouldContinue) {
			nap();
			if(_shouldContinue)
				eat();
		}
		_alive = false;
	}
	/*
	Metoda do śmiertelnego ugodzenia filozofa
	*/
	void wound() {
		_shouldContinue = false;
	}
	
};

int main() {
	srand(time(NULL));
	std::mutex table[THREADS];
	philosopher * haters[THREADS];

	/*
	Tworzymy imprezę przekazująć identyfikator oraz stół (mutexy to nasze łyżki)
	*/
	std::cout << "Let's start!" << std::endl;
	for (int i = 0; i < THREADS; ++i) {
		haters[i] = new philosopher(i, table);
	}

	std::this_thread::sleep_for(std::chrono::seconds(60));

	/*
	Teraz wszystkich śmiertelnie godzimy
	*/
	std::cout << "Let's wrap it up!" << std::endl;
	for (int i = 0; i < THREADS; ++i) {
		haters[i]->wound();
	}

	/*
	Sprzątamy - brzydko więc się nie wzorować
	*/
	std::cout << "Let's wait for sleepers" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(8));
	for (int i = 0; i < THREADS; ++i) {
		delete haters[i];
	}

	std::cout << "Bye!" << std::endl;
	return 0;
}

