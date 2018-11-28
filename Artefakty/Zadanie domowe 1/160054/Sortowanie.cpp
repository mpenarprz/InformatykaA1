#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int main() {
    vector <int> dane;

    int n = 0;

    while(n != -1){
        cin >> n;
        if (n >= 0 && n <= 5000)
            dane.push_back(n);
    }
    n = dane.size();
    sort(dane.begin(), dane.end()); // użycie sort() wyceniam na 0,5 pkt/2 pkt - tu powinen być algorytm sortujący. Nie wspominaliśmy o #include<algorithm>
    for (int i = 0; i < n ; ++i) {

        cout << dane[i] << endl;

    }
    return 0;
}


