#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

bool A{};
bool B{};
bool C{};
bool D{};
bool E{};
bool F{};
bool G{};
bool H{};
bool I{};
bool J{};
bool K{};
bool L{};
bool M{};

void wpiszPunktyDoTabeli(char litera)
{
	int suma = 0;
	bool czyDwa{};
	bool czyTrzy{};
	bool czyCztery{};
	bool czyMalyStrit{};
	int indeks = 0;
	int podmiana = 0;
	int liczba{};
	int poKolei[5]{};
	int ileZamian{};
	bool czyDuzyStrit{};
	int ile{};
	bool czyPiec{};

	switch (litera)
	{
		//jedynki
	case 'A':
		if (A == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (wyniki[i] == 1) suma++;
			}
			tabela[0] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			A = 1;
		}
		break;
		//dwójki
	case 'B':
		if (B == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (wyniki[i] == 2) suma += 2;
			}
			tabela[1] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			B = 1;
		}
		break;
		//trójki
	case 'C':
		if (C == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (wyniki[i] == 3) suma += 3;
			}
			tabela[2] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			C = 1;
		}
		break;
		//czwórki
	case 'D':
		if (D == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (wyniki[i] == 4) suma += 4;
			}
			tabela[3] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			D = 1;
		}
		break;
		//pi¹tki
	case 'E':
		if (E == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (wyniki[i] == 5) suma += 5;
			}
			tabela[4] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			E = 1;
		}
		break;
		//szóstki
	case 'F':
		if (F == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				if (wyniki[i] == 6) suma += 6;
			}
			tabela[5] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			F = 1;
		}
		break;
		//trzy jednakowe
	case 'G':
		if (G == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 1; i <= 6; i++)
			{
				ile = 0;
				for (int j = 0; j < 5; j++)
				{
					if (wyniki[j] == i) ile++;
				}
				if (ile >= 3) czyTrzy = 1;
				if (czyTrzy == 1)
				{
					for (int i = 0; i < 5; i++)
					{
						suma += wyniki[i];
					}
					tabela[6] = suma;
					tabela[13] += suma;
					break;
				}
			}
			wypiszTabele();
			runda++;
			G = 1;
		}
		break;
		//cztery jednakowe
	case 'H':
		if (H == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 1; i <= 6; i++)
			{
				ile = 0;
				for (int j = 0; j < 5; j++)
				{
					if (wyniki[j] == i) ile++;
				}
				if (ile >= 4) czyCztery = 1;
				if (czyCztery == 1)
				{
					for (int i = 0; i < 5; i++)
					{
						suma += wyniki[i];
					}
					tabela[7] = suma;
					tabela[13] += suma;
					break;
				}
			}
			wypiszTabele();
			runda++;
			H = 1;
		}
		break;
		//ful
	case 'I':
		if (I == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 1; i <= 6; i++)
			{
				ile = 0;
				for (int j = 0; j < 5; j++)
				{
					if (wyniki[j] == i) ile++;
				}
				if (ile == 2) czyDwa = 1;
				if (ile == 3) czyTrzy = 1;
				if (czyDwa == 1 && czyTrzy == 1)
				{
					tabela[8] = 25;
					tabela[13] += 25;
					wypiszTabele();
					runda++;
					I = 1;
					break;
				}
			}
			wypiszTabele();
			runda++;
			I = 1;
		}
		break;
		//ma³y strit
	case 'J':
		if (J == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				poKolei[i] = wyniki[i];
			}
			do
			{
				ileZamian = 0;
				for (int k = 0; k < 4; k++)
				{
					if (poKolei[k] > poKolei[k + 1])
					{
						podmiana = poKolei[k];
						poKolei[k] = poKolei[k + 1];
						poKolei[k + 1] = podmiana;
						ileZamian++;
					}
				}
			} while (ileZamian != 0);

			for (int j = 0; j < 5; j++)
			{
				if ((poKolei[j + 1] - poKolei[j]) == 1) liczba++;
				else if ((poKolei[j + 1] - poKolei[j]) > 1) liczba = 0;
			}
			if (liczba >= 3) czyMalyStrit = 1;
			if (czyMalyStrit == 1)
			{
				tabela[9] = 30;
				tabela[13] += 30;
			}
			wypiszTabele();
			runda++;
			J = 1;
		}
		break;
		//du¿y strit
	case 'K':
		if (K == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				poKolei[i] = wyniki[i];
			}
			do
			{
				ileZamian = 0;
				for (int k = 0; k < 4; k++)
				{
					if (poKolei[k] > poKolei[k + 1])
					{
						podmiana = poKolei[k];
						poKolei[k] = poKolei[k + 1];
						poKolei[k + 1] = podmiana;
						ileZamian++;
					}
				}
			} while (ileZamian != 0);

			for (int j = 0; j < 5; j++)
			{
				if ((poKolei[j + 1] - poKolei[j]) == 1) liczba++;
				else if ((poKolei[j + 1] - poKolei[j]) > 1) liczba = 0;
			}
			if (liczba >= 4) czyDuzyStrit = 1;
			if (czyDuzyStrit == 1)
			{
				tabela[10] = 40;
				tabela[13] += 40;
			}
			wypiszTabele();
			runda++;
			K = 1;
		}
		break;
		//genera³
	case 'L':
		if (L == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 1; i <= 6; i++)
			{
				ile = 0;
				for (int j = 0; j < 5; j++)
				{
					if (wyniki[j] == i) ile++;
				}
				if (ile >= 5) czyPiec = 1;
				if (czyPiec == 1)
				{
					tabela[11] = 50;
					tabela[13] += 50;
					break;
				}
			}
			wypiszTabele();
			runda++;
			L = 1;
		}
		break;
		//szansa
	case 'M':
		if (M == 1)
		{
			cout << "Ta rubryka jest ju¿ zajêta!" << endl;
			poRzucie();
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				suma += wyniki[i];
			}
			tabela[12] = suma;
			tabela[13] += suma;
			wypiszTabele();
			runda++;
			M = 1;
		}
		break;
	default:
		break;
	}
	if (runda == 13) koniecGry();
}
