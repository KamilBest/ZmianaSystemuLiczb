/*
 * main.cpp
 *
 *  Created on: 24-09-2014
 *      Author: kamilbest
 */
#include <iostream>
using namespace std;

int main() {
	string liczba;
	char repeat = 't'; //do pętli powtarzającej program

	unsigned podstawa, wynik, cyfra;

	cout << "Obliczanie wartości liczby zapisanej"
			<< "\nw podanym systemie pozycyjnym"
			<< "\nprzy pomocy schematu Hornera" << endl;

	while (repeat == 't') { //pętla powtarzająca program dopóki użytkownik wpisze t

		cout << "\nPodaj liczbe    = ";
		cin >> liczba;
		int dlugosc = liczba.length();

		do { //sprawdzanie poprawności podstawy
			cout << endl << "Podaj podstawę (2..9) = ";
			cin >> podstawa;
			if (podstawa < 2 || podstawa > 9)
				cout << "Podana podstawa nie nalezy do przedzialu 2-9." << endl;
		} while (podstawa < 2 || podstawa > 9);

		wynik = 0;
		for (int i = 0; i < dlugosc; i++) {

			cyfra = liczba[i] - int('0');
			wynik = wynik * podstawa + cyfra;
		}
		cout << "Liczba: " << liczba << "(" << podstawa << ")" << " = "
				<< wynik << "(10)\n";
		cout << "Czy chcesz cos jeszcze obliczyc? t/n" << endl;
		cin >> repeat;
	}
	cout << "Koniec programu." << endl;
	return 0;
}

