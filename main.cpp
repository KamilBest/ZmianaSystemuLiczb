/*
 * main.cpp
 *
 *  Created on: 24-09-2014
 *      Author: kamilbest
 */
#include <iostream>
using namespace std;

bool sprawdz_poprawnosc(int, string);

class Na_dziesietny {
	string s_liczba;
	unsigned i_podstawa;
	int dlugosc;
	unsigned i_wynik;
	bool poprawnie;

public:

	void powitanie() {

		cout << "Obliczanie wartości liczby zapisanej"
				<< "\nw podanym systemie pozycyjnym"
				<< "\nprzy pomocy schematu Hornera" << endl;

	}

	void pobierz_dane() {
		do { //sprawdzanie poprawności podstawy
			cout << endl << "Podaj podstawę (2..9) = ";
			cin >> i_podstawa;
			if (i_podstawa < 2 || i_podstawa > 9)
				cout << "Podana podstawa nie nalezy do przedzialu 2-9." << endl;
		} while (i_podstawa < 2 || i_podstawa > 9);

		bool poprawne;
		do {
			cout << "\nPodaj liczbe    = ";
			cin >> s_liczba;
			Na_dziesietny::sprawdz_dlugosc();

			if (i_podstawa == 2)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 3)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 4)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 5)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 6)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 7)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 8)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);
			else if (i_podstawa == 9)
				poprawne = sprawdz_poprawnosc(i_podstawa, s_liczba);

		} while (poprawne == false);
		Na_dziesietny::przelicz();
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

bool sprawdz_poprawnosc(int podstawa, string liczba) {
	int dlugosc = liczba.length();
	int cyfra;
	bool poprawnosc = true;
	for (int i = 0; i < dlugosc; i++) {
		cyfra = liczba[i] - int('0');
		if (cyfra < 0 or cyfra > podstawa - 1) {
			cout << "W systemie (" << podstawa
					<< ") mozesz uzywac tylko liczb z przedzialu 0-"
					<< podstawa - 1;
			poprawnosc = false;
			break;
		}
	}
	if (poprawnosc == false)
		return false;
	else
		return true;
}
int main() {

	Na_dziesietny *system = new Na_dziesietny;
	system->powitanie();

	char repeat = 't'; //do pętli powtarzającej program
	while (repeat == 't') { //pętla powtarzająca program dopóki użytkownik wpisze t

		system->pobierz_dane();
		system->zwroc_wynik();

		cout << "Czy chcesz cos jeszcze obliczyc? t/n" << endl;
		cin >> repeat;
	}
	cout << "Koniec programu." << endl;
	delete system;
	return 0;
}

