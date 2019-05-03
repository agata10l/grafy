#include "Graf.h"

#include <iostream>
#include <fstream>

#include "Macierz.h"
#include "Lista.h"

using namespace std;

Graf::Graf(Graf_typ_t typ, unsigned ilosc_wierzcholkow) :
	krawedzie(nullptr)
{
	inicjalizuj(typ, ilosc_wierzcholkow);
}

Graf::~Graf()
{
	delete krawedzie;
}

void Graf::inicjalizuj(Graf_typ_t typ, unsigned ilosc_wierzcholkow)
{
	if (krawedzie != nullptr)
	{
		delete krawedzie;
	}

	switch (typ)
	{
	case GRAF_TYP_MACIERZ:

		krawedzie = new Macierz(ilosc_wierzcholkow);

		break;

	case GRAF_TYP_LISTA:

		krawedzie = new Lista(ilosc_wierzcholkow);

		break;
	}
}

unsigned* Graf::Dijkstra(unsigned wierzcholek_startowy)
{
	unsigned ilosc_wierzcholkow = krawedzie->pobierz_ilosc_wierzcholkow();
	unsigned* odleglosci = new unsigned[ilosc_wierzcholkow];
	bool* czy_odwiedzone = new bool[ilosc_wierzcholkow] { false };
	unsigned indeks_min_odleglosci = 0;

	for (int i = 0; i < ilosc_wierzcholkow; i++)
	{
		odleglosci[i] = NIESK;
	}
	odleglosci[wierzcholek_startowy] = 0;

	for (int i = 0; i < ilosc_wierzcholkow - 1; i++)
	{
		unsigned min_odleglosc = NIESK;
		for (int j = 0; j < ilosc_wierzcholkow; j++) //szukanie najmniejszej liczby w tablicy odleglosci do nieodwiedzonego wierz
		{
			if (czy_odwiedzone[j] == false && min_odleglosc >= odleglosci[j])
			{
				min_odleglosc = odleglosci[j];
				indeks_min_odleglosci = j;
			}
		}
		czy_odwiedzone[indeks_min_odleglosci] = true;


		for (int j = 0; j < ilosc_wierzcholkow; j++)
		{
			unsigned odleglosc = krawedzie->pobierz_wage(indeks_min_odleglosci, j); //odl do ktorego chcemy pojsc

			if (czy_odwiedzone[j] == false &&
				odleglosci[j] > odleglosci[indeks_min_odleglosci] + odleglosc &&
				odleglosc != NIESK &&
				odleglosci[indeks_min_odleglosci] != NIESK)
			{
				odleglosci[j] = odleglosci[indeks_min_odleglosci] + odleglosc;
			}
		}
	}

	return odleglosci;
}

unsigned Graf::wczytaj_z_pliku()
{
	char opcja;
	fstream plik;
	string nazwa_pliku;
	unsigned ilosc_krawedzi, ilosc_wierzcholkow, wierzcholek_startowy,
		wierzcholek_poczatkowy, wierzcholek_koncowy, waga;

	cout << "Rozpoczeto proces wczytywania z pliku." << endl;
	
	do
	{
		cout << "Podaj nazwe pliku: ";

		cin >> nazwa_pliku;

		plik.open(nazwa_pliku, ios::in);
	} while (plik.good() == false);

	cout << "W jaki sposób reprezentowaæ macierz" << endl;
	cout << "[1] - Macierz" << endl;
	cout << "[2] - Lista" << endl;

	do
	{
		cout << "Wybierz opcje: ";
		cin >> opcja;
	} while (opcja != '1' && opcja != '2');

	plik >> ilosc_krawedzi >> ilosc_wierzcholkow >> wierzcholek_startowy;

	switch (opcja)
	{
	case '1':

		inicjalizuj(GRAF_TYP_MACIERZ, ilosc_wierzcholkow);

		break;

	case '2':

		inicjalizuj(GRAF_TYP_LISTA, ilosc_wierzcholkow);

		break;
	}

	for (int i = 0; i < ilosc_krawedzi; i++)
	{
		plik >> wierzcholek_poczatkowy >> wierzcholek_koncowy >> waga;

		krawedzie->dodaj_krawedz(wierzcholek_poczatkowy, wierzcholek_koncowy, waga);
	}

	return wierzcholek_startowy;
}

Krawedzie* Graf::pobierz_krawedzie()
{
	return krawedzie;
}
