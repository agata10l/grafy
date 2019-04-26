#ifndef KRAWEDZIE_H
#define KRAWEDZIE_H
#include<string>

#define BRAK_KRAWEDZI	UINT_MAX
#define NIESK			UINT_MAX

class Krawedzie
{
public:
	virtual ~Krawedzie() {};

	virtual void dodaj_krawedz(unsigned od_wierzcholka, unsigned do_wierzcholka,unsigned waga) = 0;
	virtual unsigned pobierz_wage(unsigned od_wierzcholka, unsigned do_wierzcholka) const = 0;
	unsigned pobierz_ilosc_wierzcholkow() const;
	virtual void wyswietl_wagi() const = 0;
	void losuj_wagi(double procent_mozliwych_wag);
	unsigned wczytaj_z_pliku(std::string nazwa_pliku);

protected:
	unsigned wierzcholki_;
};

#endif 


