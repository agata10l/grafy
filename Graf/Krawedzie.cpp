#include "Krawedzie.h"
#include "RNG.h"

#include <iostream>

unsigned Krawedzie::pobierz_ilosc_wierzcholkow() const
{
	return wierzcholki_ ;
}

void Krawedzie::losuj_wagi(double procent_mozliwych_wag)
{
	unsigned ilosc_krawedzi = wierzcholki_ * (wierzcholki_ - 1) / 2 * procent_mozliwych_wag;
	unsigned od_wierzcholka = 1;
	unsigned do_wierzcholka = 0;

	for (int i = 0; i < ilosc_krawedzi; i++)
	{
		dodaj_krawedz(od_wierzcholka, do_wierzcholka, generuj());

		if (od_wierzcholka - 1 == do_wierzcholka)
		{
			od_wierzcholka++;
			do_wierzcholka = 0;
		}
		else
		{
			do_wierzcholka++;
		}
	}
}


