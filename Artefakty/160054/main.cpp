#include <iostream>
#include <string>

/*
Tego nie używamy na produkcji
*/
using namespace std;

string cipher(std::string input, int key) { //std::string po co? skoro już robisz using namespace?
    int l = input.length();
    for (int i = 0; i < l; ++i) {
        if (input[i] >= 'a' && input[i] <= 'z') // Proszę nawiasować, brak nawiasów generuje więcej problemów niż brak nawiasów rozwiązuje. PAtrz niżej
            input[i] += key;
        if (input[i] > 'z')
            input[i] = 'a'; // Źle obsłużone zawijanie. Patrz niżej.
    }
}
/*
	Załóżmy key = 2 i ciąg "Z".
	"Z" + 1 = "A"
	"A" + 1 = "B"
	czyli 
	"Z" + 2 = "B"
	U Ciebie po wyjściu z zakresu ustawiasz sztywno "A".
	
	Nie kompensujesz wartości key po wyjściu za margines.
*/



/*
Przykład poprawnego formatowania:
*/
string cipher2(std::string input, int key) {
    int l = input.length();
    for (int i = 0; i < l; ++i) {
        if (input[i] >= 'a' && input[i] <= 'z'){
            input[i] += key;
		}
        if (input[i] > 'z'){
			input[i] = 'a'; 
		}
    }
	
	// Brak wartości zwracanej
}

int main() {

}