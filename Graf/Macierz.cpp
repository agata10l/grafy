#include<iostream>
#include "Macierz.h"

Macierz::Macierz(unsigned ile_wierzcholkow)
{
	wierzcholki_ = ile_wierzcholkow;

	macierz_ = new unsigned*[wierzcholki_];
	for (int i = 0; i < wierzcholki_; i++)
	{
		macierz_[i] = new unsigned[wierzcholki_];
	}

	stan_poczatkowy_macierzy();
}

Macierz::~Macierz()
{
	for (int i = 0; i < wierzcholki_; i++)
	{
		delete[] macierz_[i];
	}

	delete[] macierz_;
}

void Macierz::dodaj_krawedz(unsigned od_wierzcholka, unsigned do_wierzcholka, unsigned waga)
{
	macierz_[od_wierzcholka][do_wierzcholka] = waga;
}

unsigned Macierz::pobierz_wage(unsigned od_wierzcholka, unsigned do_wierzcholka) const
{
	return macierz_[od_wierzcholka][do_wierzcholka];
}

void Macierz::wyswietl_wagi() const
{
	for (int i = 0; i < wierzcholki_; i++)
	{
		for (int j = 0; j < wierzcholki_; j++)
		{
			std::cout << pobierz_wage(i, j) << '\t';
		}
		std::cout << std::endl;
	}
}

void Macierz::stan_poczatkowy_macierzy()
{
	for (int i = 0; i < wierzcholki_; i++)
	{
		for (int j = 0; j < wierzcholki_; j++)
		{
			dodaj_krawedz(i, j, BRAK_KRAWEDZI);
		}
	}
}



