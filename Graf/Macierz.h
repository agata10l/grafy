#ifndef MACIERZ_H
#define MACIERZ_H

#include "Krawedzie.h"

class Macierz:
	public Krawedzie
{
public:
	Macierz(unsigned ile_wierzcholkow);
	~Macierz();

	virtual void dodaj_krawedz(unsigned od_wierzcholka, unsigned do_wierzcholka, unsigned waga);
	virtual unsigned pobierz_wage(unsigned od_wierzcholka, unsigned do_wierzcholka) const;
	virtual void wyswietl_wagi() const;
	void stan_poczatkowy_macierzy();
private:
	unsigned** macierz_;
};

#endif 


