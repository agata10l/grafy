#include <iostream>
#include <fstream>
#include "Macierz.h"
#include "Lista.h"
#include "Dijkstra.h"
#include <chrono>

using  namespace std;

unsigned ILOSC_WIERZCHOLKOW[] = { 10, 50, 100, 500, 1000 };
double PROCENT_WYPELNIENIA[] = { 0.25, 0.50, 0.75, 1 };
unsigned ILOSC_TESTOW = 100;

//Krawedzie* wczytaj(string nazwa_pliku)
//{
//	std::fstream plik(nazwa_pliku, std::ios::in);
//
//	unsigned ilosc_krawedzi;
//	unsigned ilosc_wierzcholkow;
//	unsigned wierz_startowy;
//
//	plik >> ilosc_krawedzi >> ilosc_wierzcholkow >> wierz_startowy;
//	plik.close();
//
//	Krawedzie* krawedzie = new Macierz(ilosc_wierzcholkow);
//	krawedzie->wczytaj_z_pliku(nazwa_pliku);
//
//	return krawedzie;
//}

int main()
{
	long unsigned czas[2];
	fstream wyniki[2] = { fstream("macierz.txt", ios::out), fstream("lista.txt", ios::out) };

	for (int i = 0; i < 5; i++)
	{
		cout << ILOSC_WIERZCHOLKOW[i] << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << '\t' << PROCENT_WYPELNIENIA[j] << endl;

			czas[0] = czas[1] = 0;
			for (int g = 0; g < ILOSC_TESTOW; g++)
			{
				Krawedzie* krawedzie[2] = { new Macierz(ILOSC_WIERZCHOLKOW[i]), new Lista(ILOSC_WIERZCHOLKOW[i]) };

				for (int k = 0; k < 2; k++)
				{
					krawedzie[k]->losuj_wagi(PROCENT_WYPELNIENIA[j]);

					auto begin = std::chrono::high_resolution_clock::now();
					delete Dijkstra(krawedzie[k], 0);
					auto end = std::chrono::high_resolution_clock::now();

					czas[k] += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
				}

				delete krawedzie[0];
				delete krawedzie[1];
			}
			for (int g = 0; g < 2; g++)
			{
				wyniki[g] << ILOSC_WIERZCHOLKOW[i] << '\t' << PROCENT_WYPELNIENIA[j] << '\t' << czas[g] / ILOSC_TESTOW << endl;
			}
		}
	}
	wyniki[0].close();
	wyniki[1].close();

	system("pause");
}
