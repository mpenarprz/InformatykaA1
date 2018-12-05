#include <iostream>

using namespace std;

int main()
{
    cout << "Ile kolejnych liczb mam wymnozyc?" << endl;
    int ile;
    cin>>ile;

    int pierwsza=1, druga=2, iloczyn=0;

if(ile==0)
{
    iloczyn=0;
}
else
{
    if(ile==1)
    {
        iloczyn=1;
    }
    else
    {
        for (int i=0; i<ile-1; i++)
        {
            iloczyn = pierwsza * druga;

            pierwsza = iloczyn;

            druga = druga + 1;
        }
    }
}
    cout<<"Iloczyn wynosi: "<<iloczyn<<endl;

    return 0;
}



