#ifndef LISTA_H
#define LISTA_H

#include "Krawedzie.h"

struct element_listy_t
{
	unsigned waga;
	unsigned do_wierzcholka;

	element_listy_t* nastepny;
};

class Lista:
	public Krawedzie
{
public:

	Lista(unsigned ilosc_wierzcholkow);
	~Lista();

	virtual void dodaj_krawedz(unsigned od_wierzcholka, unsigned do_wierzcholka, unsigned waga);
	virtual unsigned pobierz_wage(unsigned od_wierzcholka, unsigned do_wierzcholka) const;
	virtual void wyswietl_wagi() const;

private:
	element_listy_t** listy_wag_;

};

#endif