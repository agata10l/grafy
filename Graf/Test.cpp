#include "Test.h"

#include <iostream>
#include <fstream>
#include <chrono>

#include "Graf.h"

using namespace std;

void test_start()
{
	long unsigned czas[2];
	fstream wyniki[2] = { fstream("macierz.txt", ios::out), fstream("lista.txt", ios::out) };

	cout << "Rozpoczeto testy." << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << ILOSC_WIERZCHOLKOW[i] << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << '\t' << PROCENT_WYPELNIENIA[j] << endl;

			czas[0] = czas[1] = 0;
			for (int g = 0; g < ILOSC_TESTOW; g++)
			{
				Graf graf[2] = { Graf(GRAF_TYP_MACIERZ, ILOSC_WIERZCHOLKOW[i]), Graf(GRAF_TYP_LISTA, ILOSC_WIERZCHOLKOW[i]) };

				for (int k = 0; k < 2; k++)
				{
					graf[k].pobierz_krawedzie()->losuj_wagi(PROCENT_WYPELNIENIA[j]);

					auto begin = std::chrono::high_resolution_clock::now();
					delete graf[k].Dijkstra(0);
					auto end = std::chrono::high_resolution_clock::now();

					czas[k] += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
				}
			}
			for (int g = 0; g < 2; g++)
			{
				wyniki[g] << ILOSC_WIERZCHOLKOW[i] << '\t' << PROCENT_WYPELNIENIA[j] << '\t' << czas[g] / ILOSC_TESTOW << endl;
			}
		}
	}
	wyniki[0].close();
	wyniki[1].close();

	cout << "Testy zakonczyly sie." << endl;
}

void test_z_pliku()
{
	Graf graf;
	unsigned* odlegosci;
	unsigned wierzcholek_startowy;
	char opcja;

	wierzcholek_startowy = graf.wczytaj_z_pliku();
	cout << "Wyswietlic wczytany graf?" << endl;
	cout << "[1] - Tak" << endl;
	cout << "Inne - Nie" << endl;
	cin >> opcja;
	if (opcja == '1')
	{
		graf.pobierz_krawedzie()->wyswietl_wagi();
	}

	odlegosci = graf.Dijkstra(wierzcholek_startowy);
	cout << "Wyswietlic wynik algortmu Dijkstry?" << endl;
	cout << "[1] - Tak" << endl;
	cout << "Inne - Nie" << endl;
	cin >> opcja;
	if (opcja == '1')
	{
		cout << "Odleglosci od wierzcholka: " << wierzcholek_startowy << "\ndo pozostalych wynosza :";

		for (int i = 0; i < graf.pobierz_krawedzie()->pobierz_ilosc_wierzcholkow(); i++)
		{
			cout << odlegosci[i] << ", ";
		}
		cout << endl;
	}

	delete odlegosci;
}
