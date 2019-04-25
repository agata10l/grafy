#include <iostream>

#include "Macierz.h"
#include "Lista.h"
#include "Dijkstra.h"
int main()
{
	Krawedzie* krawedzie = new Macierz(10);
	krawedzie->losuj_wagi(1.0);
	krawedzie->wyswietl_wagi();

	unsigned* odlegosci = Dijkstra(krawedzie, 0);
	for (int i = 0; i < 10; i++)
	{
		std::cout << odlegosci[i] << "  ";
	}

	system("pause");
}
