#include<iostream>
#include "Lista.h"

Lista::Lista(unsigned ilosc_wierzcholkow)
{
	wierzcholki_ = ilosc_wierzcholkow;

	listy_wag_ = new element_listy_t*[wierzcholki_] {};
}

Lista::~Lista()
{
	for (int i = 0; i < wierzcholki_; i++)
	{
		element_listy_t* pomocnicza;
		while (listy_wag_[i] != nullptr)
		{
			pomocnicza = listy_wag_[i]->nastepny;
			delete listy_wag_[i];

			listy_wag_[i] = pomocnicza;
		}
	}
	delete[] listy_wag_;
}

void Lista::dodaj_krawedz(unsigned od_wierzcholka, unsigned do_wierzcholka, unsigned waga)
{
	element_listy_t* pomocnicza = listy_wag_[od_wierzcholka];
	element_listy_t* nowy = new element_listy_t{ waga, do_wierzcholka, nullptr };

	if (listy_wag_[od_wierzcholka] == nullptr)
	{
		listy_wag_[od_wierzcholka] = nowy;
	}
	else
	{
		while (pomocnicza->nastepny != nullptr)
		{
			pomocnicza = pomocnicza->nastepny;
		}

		pomocnicza->nastepny = nowy;
	}

}

unsigned Lista::pobierz_wage(unsigned od_wierzcholka, unsigned do_wierzcholka) const
{
	element_listy_t* pomocnicza = listy_wag_[od_wierzcholka];

	for (int i = 0; i < wierzcholki_; i++)
	{
		if (pomocnicza == nullptr)
		{
			return NIESK;
		}

		if (pomocnicza->do_wierzcholka == do_wierzcholka)
		{
			return pomocnicza->waga;
		}

		pomocnicza = pomocnicza->nastepny;
	}
}

void Lista::wyswietl_wagi() const
{
	for (int i = 0; i < wierzcholki_; i++)
	{
		element_listy_t* pomocnicza = listy_wag_[i];

		while (pomocnicza != nullptr)
		{
			std::cout << pomocnicza->do_wierzcholka << ',' << pomocnicza->waga << '\t';
			pomocnicza = pomocnicza->nastepny;
		}
		std::cout << std::endl;
	}

}

