#ifndef GRAF_H
#define GRAF_H

#include "Krawedzie.h"

enum Graf_typ_t
{
	GRAF_TYP_MACIERZ,
	GRAF_TYP_LISTA
};

class Graf
{
public:
	Graf(Graf_typ_t typ = GRAF_TYP_MACIERZ, unsigned ilosc_wierzcholkow = 0);
	~Graf();

	void inicjalizuj(Graf_typ_t typ, unsigned ilosc_wierzcholkow);

	unsigned* Dijkstra(unsigned wierzcholek_startowy);

	unsigned wczytaj_z_pliku();

	Krawedzie* pobierz_krawedzie();
	
private:
	Krawedzie* krawedzie;
};

#endif 