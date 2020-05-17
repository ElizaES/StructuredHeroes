#include <iostream>
#include <time.h>
using namespace std;

struct equipment
{
	int atk;
	int def;
};

struct hero
{
	char name[20];
	int level;
	equipment eqp;
};

void WpisywanieIndeksu(int &indeks, int ilosc, int *add_ind, int &ilosc_wpisanych) {

	do {
		cout << "Jezeli chesz stworzyc bohatera - wpisz indeks: ";
		cin >> indeks;
	} while (indeks < 0 || indeks > ilosc);

		*(add_ind + ilosc_wpisanych) = indeks;
		ilosc_wpisanych++;
}

void MakeHero(int indeks, hero *wsk) {

	cout<< "Name: ";
	cin>> wsk[indeks].name;
	cout<< "Level: ";
	cin>> wsk[indeks].level;
	cout << "Attack: ";
	cin >> wsk[indeks].eqp.atk;
	cout << "Defense: ";
	cin >> wsk[indeks].eqp.def;
}

void ShowHero(int *wpisane_ind, hero *wsk, int ilosc_wpisanych) {

	for (int i = 0; i < ilosc_wpisanych; i++) {
		cout<<(*wpisane_ind)<< ")" <<" Name: "<< wsk[*wpisane_ind].name <<endl;
		cout<< " Level: "<< wsk[*wpisane_ind].level<< endl;
		cout<< " Attack: "<< wsk[*wpisane_ind].eqp.atk<< endl;
		cout<< " Defense: "<< wsk[*wpisane_ind].eqp.def<< endl;
		cout<< "\n";
		wpisane_ind++;
	}
}

int main() {

	int ilosc, opcja = 1;
	int indeks = 0;
	int ilosc_wpisanych = 0;

	cout<< "Wpisz ilosc bochaterow: ";
	cin>> ilosc;

	hero *wsk = new hero[ilosc];
	int *add_ind = new int[ilosc];

	while (opcja) {

		WpisywanieIndeksu (indeks, ilosc, add_ind, ilosc_wpisanych);
		MakeHero(indeks, wsk);

		cout<< "Utworzyc nowego bohatera tak/nie"<< "\n (0 - nie, 1 - tak)";
		cin>> opcja;
	}
	cout<< "\n";

	ShowHero(add_ind, wsk, ilosc_wpisanych);

	delete[]wsk;
	delete[]add_ind;
	system("pause");
	return 0;
}