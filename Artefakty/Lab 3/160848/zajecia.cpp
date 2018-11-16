#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct School
{
	string patron;
	vector<Pupil> uczniowie; // dobry typ.... polskie nazewnictwo zmiennych :(
	vector<Teacher> nauczyciele;
};
struct Pupil
{
	string name;
	string surname;
	char sex;


};
struct Teacher
{
	string name;
	string surname;
	char sex;
};





#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
Dokładnie tak - wszystko zgodnie z definicją
*/
int fibonacii(int m)
{
	if (m == 0) //Najbezpieczniej tu by było dać m <= 0
	{
		return 0;
	}
	else if (m == 1)
	{
		return 1;
	}
	else
	{
		return fibonacii(m - 1) + fibonacii(m - 2);
	}
}


vector<int>fibonacciVec(int maxN)
{
	// :(
}