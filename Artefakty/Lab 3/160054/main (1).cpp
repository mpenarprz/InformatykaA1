#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pupil{
   string name , surname , gender;
};

struct Teacher{
   string name , surname , gender;

   struct School{ //Cóż to za zagnieżdzęnie struktur?
       string patron;
       vector<Pupil> nStud;
       vector<Teacher> nTeach; 
  };
};

/*
Powinno być tak:
*/

struct Pupil{
   string name , surname , gender;
};

struct Teacher{
   string name , surname , gender;

   
};

struct School{
       string patron;
       vector<Pupil> nStud;
       vector<Teacher> nTeach; 
};
/*
Koniec
*/

int fibonacci (int n);
vector<int> fibonacciVec(int maxN);

int main() { //Test
    vector<int> tester = fibonacciVec(20);
    vector<int>::iterator testerEnd = tester.end();
    for (vector<int>::iterator it = tester.begin(); it < testerEnd ; ++it) {
        cout << *it << endl;
    }
    return 0;
}

int fibonacci(int n) {
    return n == 0 ? 0 : n == 1 ? 1 : fibonacci(n - 1) + fibonacci(n - 2); // Like a boss
}

vector<int> fibonacciVec(int maxN){
    vector<int> vec;
    for (int i = 0; i < maxN ; ++i) {
        vec.push_back(fibonacci(i));  // Dokładnie o to chodziło
    }
    return vec;
}

/*
Ogółem - bardzo ładny kod
*/