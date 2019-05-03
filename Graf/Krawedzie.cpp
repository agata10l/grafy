#include "Krawedzie.h"
#include "RNG.h"
#include <fstream>
#include <iostream>
#include "Macierz.h"

unsigned Krawedzie::pobierz_ilosc_wierzcholkow() const
{
	return wierzcholki_;
}

void Krawedzie::losuj_wagi(double procent_mozliwych_wag)
{
	unsigned ilosc_krawedzi = wierzcholki_ * (wierzcholki_ - 1) / 2 * procent_mozliwych_wag;
	unsigned od_wierzcholka = 1;
	unsigned do_wierzcholka = 0;

	for (int i = 0; i < ilosc_krawedzi; i++)
	{
		dodaj_krawedz(do_wierzcholka, od_wierzcholka, generuj());

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

unsigned Krawedzie::wczytaj_z_pliku(std::string nazwa_pliku)
{
	std::fstream plik(nazwa_pliku, std::ios::in);

	unsigned ilosc_krawedzi;
	unsigned ilosc_wierzcholkow;
	unsigned wierz_startowy;
	unsigned wierz_pocz;
	unsigned wierz_koncowy;
	unsigned waga;

	plik >> ilosc_krawedzi >> ilosc_wierzcholkow >> wierz_startowy;

	while (plik.eof() == false)
	{
		plik >> wierz_pocz >> wierz_koncowy >> waga;

		dodaj_krawedz(wierz_pocz, wierz_koncowy, waga);
	}

	plik.close();

	return wierz_startowy;
}


