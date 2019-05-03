#include <iostream>
#include <fstream>
#include <chrono>

#include "Test.h"

using namespace std;

void menu();

int main()
{
	menu();

	system("pause");
}

void menu()
{
	char opcja;

	cout << endl << endl << endl;
	cout << "\t PAMSI - Grafy" << endl;
	cout << "[1] - Rozpocznij testy" << endl;
	cout << "[2] - Wczytaj graf z pliku" << endl << endl;
	
	do
	{
		cout << "Wybierz opcje: ";
		cin >> opcja;
	} while (opcja != '1' && opcja != '2');


	switch (opcja)
	{
	case '1':
		test_start();
		break;

	case '2':
		test_z_pliku();

		break;
	default:
		cout << "Blad" << endl;
	}

}