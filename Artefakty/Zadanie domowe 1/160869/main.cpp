#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

//1a
int IntigersSum1(int number)
{
    int sum=0;

    for(int i=0 ; i<=number ; i++)
    {
        sum = sum+i;			//To można skrócić do sum += i;
    }
    return sum;
}

//1b
int IntigersSum2(int number)
{
    if(number==0)
    {
        return 0;
    }
    return number + IntigersSum2(number-1);
}

//2a
int Factorial1(int number)
{
    int result=1;

    for(int i=1 ; i<=number ; i++)
    {
        result = result*i;			//To można skrócić do result *= i;
    }
    return result;
}

//2b
int Factorial2(int number)
{
    if(number==0)
    {
        return 1;
    }
    return number*Factorial2(number-1);
}

/*
Do tego momentu jest sexownie.
Ogólnie rzecz biorąc: ładne, konsekwentne stylowanie.
IMO możesz wprowadzić więcej "oddechu" pomiędzy operatorami: number*Factorial2(number-1); zapisać jako: number * Factorial2(number - 1);
Lub: number==0 zapisać jako: number == 0
*/


//3
void WriteAndSort()
{
    int number;
    vector<int> data;

    do
    {
        cin >> number;
        if (number >= 0 && number <=5000)
        {
            data.push_back(number);
        }
    }while(number != -1);

    sort(data.begin(),data.end());	// To jest smutne, spodziewałem się tu algorytmu konkretnego :((

    cout << "Here are your sorted numbers:" << endl << endl;
    for(int i=0 ; i<data.size() ; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Iteracyjnie: " << IntigersSum1(10) << endl;
    cout << "Rekursywnie: " << IntigersSum2(10) << endl << endl;

    cout << "Iteracyjnie: " << Factorial1(5) << endl;
    cout << "Rekursywnie: " << Factorial2(5) << endl << endl;

    system("pause");
    system("cls");

    cout << "Write the numbers you want to sort:" << endl;
    WriteAndSort();
    return 0;
}
