#include <iostream>

#include "Macierz.h"
#include "Lista.h"
int main()
{
	Krawedzie* krawedzie = new Macierz(5);
	krawedzie->losuj_wagi(1);
	krawedzie->wyswietl_wagi();

	system("pause");
}
