#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

int runda = 0;

void gra()
{
	wypiszTabele();
	// Gra ma 13 rund - tyle razy wykona si� p�tla
	for (int i = 0; i < 13; i++)
	{
		if (i > 0)
		{
			char decyzja{};
			do
			{
				decyzja = 0;
				cout << "Graj dalej - 0, wr�� do menu - 1, zako�cz gr� - 2 ";
				cin >> decyzja;
				if (decyzja == '0')
				{
					break;
				}
				else if (decyzja == '1')
				{
					wypiszMenu();
				}
				else if (decyzja == '2')
				{
					koniecGry();
				}
				else
				{
					cout << "Podaj 0, 1 lub 2!" << endl;
				}
			} while (decyzja != 0 && decyzja != 1 && decyzja!=2);
		}
		rzutPierwszy();
		wyswietlRzut();
		poRzucie();
	}
	koniecGry();
}

void rzutPierwszy()
{
	runda = 1;
	cout << endl;
	cout << "    a        b        c        d        e" << endl;
}

void poRzucie()
{
	char rubryka = 0;

	// Gdy u�ytkownik rzuci� ko��mi trzy razy w trakcie jednej rundy
	if (runda == 3)
	{
		bool czyRubrykaPoprawna{};
		do
		{
			cin.ignore();
			cout << "Do kt�rej rubryki zapisa� punkty? Podaj liter� z pierwszej kolumny tabeli ";
			cin >> rubryka;
			// Sprawdzenie poprawno�ci wpisanego znaku (jest du�a litera)
			if ((rubryka >= 'A' && rubryka <= 'M'))
			{
				wpiszPunktyDoTabeli(rubryka);
				czyRubrykaPoprawna = 1;
			}
			else cout << "Podaj du�� liter� odpowiadaj�c� kolumnie!" << endl;
		} while (czyRubrykaPoprawna == 0);
		return;
	}
	cin.ignore();
	char kosciDoRzutu[20]{};
	char czyDalej{};

	// Gracz podejmuje decyzj� o dalszych rzutach b�d� zapisie punkt�w do tabeli
	cout << "Rzucasz dalej czy zgarniasz punkty (0/1)? ";
	cin >> czyDalej;

	// Gracz decyduje si� rzuca� dalej
	if (czyDalej == '0')
	{
		bool czyMaleLitery{};
		bool czyDuzeLitery{};
		cin.ignore();
		do
		{
			cout << "Kt�rymi ko��mi chcesz rzuci� ponownie? Podaj litery nad ko��mi: ";
			cin.get(kosciDoRzutu, 20);
			// Sprawdzenie poprawno�ci wpisanych znak�w (jest min. 1 ma�a litera)
			int i = 0;
			while(kosciDoRzutu[i]!=0)
			{
				if (kosciDoRzutu[i] >= 'a' && kosciDoRzutu[i] <= 'e') czyMaleLitery = 1;
				i++;
			}
			if (czyMaleLitery == 0)
			{
				cout << "Podaj ma�e litery odpowiadaj�ce ko�ciom!" << endl;
			}
			else break;
		} while (czyMaleLitery == 0);


		// Gdy u�ytkownik rzuci� ko��mi tylko raz podczas rundy i zdecydowa� si� na dalsze rzuty
		if (runda == 1) rzutDrugi(kosciDoRzutu);

		// Gdy u�ytkownik rzuci� ko��mi dwa razy podczas rundy i zdecydowa� si� na dalsze rzuty
		else if (runda == 2) rzutTrzeci(kosciDoRzutu);
	}

	// Gracz decyduje si� na zapis punkt�w do tabeli
	else if (czyDalej == '1')
	{

		bool czyRubrykaPoprawna{};
		do
		{
			cin.ignore();
			cout << "Do kt�rej rubryki zapisa� punkty? Podaj liter� z pierwszej kolumny tabeli ";
			cin >> rubryka;
			// Sprawdzenie poprawno�ci wpisanego znaku (jest du�a litera)
			if ((rubryka >= 'A' && rubryka <= 'M'))
			{
				wpiszPunktyDoTabeli(rubryka);
				czyRubrykaPoprawna = 1;
			}
			else cout << "Podaj du�� liter� odpowiadaj�c� kolumnie!" << endl;
		} while (czyRubrykaPoprawna == 0);
	}
	else
	{
		cout << "Podaj 0 lub 1!" << endl;
		poRzucie();
	}
}


void rzutDrugi(char tekst[20])
{
	runda = 2;
	for (int i = 0; i < 20; i++)
	{
		switch (tekst[i])
		{
		case 'a':
			wyniki[0] = (rand() % 6) + 1;
			break;
		case 'b':
			wyniki[1] = (rand() % 6) + 1;
			break;
		case 'c':
			wyniki[2] = (rand() % 6) + 1;
			break;
		case 'd':
			wyniki[3] = (rand() % 6) + 1;
			break;
		case 'e':
			wyniki[4] = (rand() % 6) + 1;
			break;
		}
		if (tekst[i] == '/0') break;
	}
	cout << "    a        b        c        d        e" << endl;
	wyswietlRzut();
	poRzucie();
}

void rzutTrzeci(char tekst[20])
{
	runda = 3;
	for (int i = 0; i < 20; i++)
	{
		switch (tekst[i])
		{
		case 'a':
			wyniki[0] = (rand() % 6) + 1;
			break;
		case 'b':
			wyniki[1] = (rand() % 6) + 1;
			break;
		case 'c':
			wyniki[2] = (rand() % 6) + 1;
			break;
		case 'd':
			wyniki[3] = (rand() % 6) + 1;
			break;
		case 'e':
			wyniki[4] = (rand() % 6) + 1;
			break;
		}
		if (tekst[i] == '/0') break;
	}
	cout << "    a        b        c        d        e" << endl;
	wyswietlRzut();
	poRzucie();
}


