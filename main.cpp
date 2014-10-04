/*
 * main.cpp
 *
 *  Created on: 24-09-2014
 *      Author: kamilbest
 */
#include <iostream>
using namespace std;

class Na_dziesietny {
	string s_liczba;
	unsigned i_podstawa;
	int dlugosc;
	unsigned i_wynik;
public:
	void powitanie() {

		cout << "Obliczanie wartości liczby zapisanej"
				<< "\nw podanym systemie pozycyjnym"
				<< "\nprzy pomocy schematu Hornera" << endl;

	}
	void pobierz_dane() {
		cout << "\nPodaj liczbe    = ";
		cin >> s_liczba;

		do { //sprawdzanie poprawności podstawy
			cout << endl << "Podaj podstawę (2..9) = ";
			cin >> i_podstawa;
			if (i_podstawa < 2 || i_podstawa > 9)
				cout << "Podana podstawa nie nalezy do przedzialu 2-9." << endl;
		} while (i_podstawa < 2 || i_podstawa > 9);


	}

	void sprawdz_dlugosc() {
		dlugosc = s_liczba.length();
	}

	void przelicz() {
		int cyfra;
		i_wynik = 0;
		for (int i = 0; i < dlugosc; i++) {

			cyfra = s_liczba[i] - int('0');
			i_wynik = i_wynik * i_podstawa + cyfra;
		}
	}
	void zwroc_wynik() {
		cout << "Liczba: " << s_liczba << "(" << i_podstawa << ")" << " = "
				<< i_wynik << "(10)\n";
	}
};

int main() {


	Na_dziesietny *system = new Na_dziesietny;
	system->powitanie();

	char repeat = 't'; //do pętli powtarzającej program
	while (repeat == 't') { //pętla powtarzająca program dopóki użytkownik wpisze t

		system->pobierz_dane();
		system->sprawdz_dlugosc();
		system->przelicz();
		system->zwroc_wynik();
		cout << "Czy chcesz cos jeszcze obliczyc? t/n" << endl;
		cin >> repeat;
	}
	cout << "Koniec programu." << endl;
	delete system;
	return 0;
}

