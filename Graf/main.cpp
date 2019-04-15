#include <iostream>

#include "Macierz.h"
#include "Lista.h"
int main()
{
	Krawedzie* krawedzie = new Lista(5);

	krawedzie->dodaj_krawedz(3, 2, 4);

	krawedzie->wyswietl_wagi();

	system("pause");
}
