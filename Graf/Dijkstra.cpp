#include "Dijkstra.h"
#include<iostream>

unsigned * Dijkstra(Krawedzie* krawedzie, unsigned wierz_startowy)
{
	unsigned ilosc_wierzcholkow = krawedzie->pobierz_ilosc_wierzcholkow();
	unsigned* odleglosci = new unsigned[ilosc_wierzcholkow];
	bool* czy_odwiedzone = new bool[ilosc_wierzcholkow] { false };
	unsigned indeks_min_odleglosci = 0;

	for (int i = 0; i < ilosc_wierzcholkow; i++)
	{
		odleglosci[i] = NIESK;
	}
	odleglosci[wierz_startowy] = 0;

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
