#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Wpisz liczbe" << endl;
    int liczba;
    cin>>liczba;
    if((liczba!=-1)&&(liczba>=0)&&(liczba<=5000))
    {
    vector <int> tab;
    tab.push_back(liczba);
    }
    else
        {
           if(liczba!=-1) {cout<<"Zla liczba! Wybierz liczbe z zakresu 0....5000";}
           else
            {
            int temp;
            for(int i=0; i<tab.size(); i++)
            {
                for(int j=0; j<(tab.size()-1);j++)
                {
                    if (tab[j]>tab[j+1])
                    temp=tab[j];
                    tab[j]=tab[j+1];
                    tab[j+1]=temp;
                }
            }
            for(int i=0;int<tab.size();i++) {cout<<i+1<<". ="<<tab[i]<<endl;}
            }
        }

    return 0;
}
