#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

// Tworz� struktur� zawieraj�c� najwy�szy osi�gni�ty w grze wynik i imi� osoby, kt�ra pobi�a rekord
struct najwyzszyWynik
{
	string imie;
	int wynik;
};

void grafika()
{
	// Wy�wietlam grafik� przedstawiaj�c� sze�ciany i wypisuj� menu gry
	string linia = "";
	ifstream pliczek;
	pliczek.open("kostki.txt");
	if (pliczek.is_open())
	{
		while (getline(pliczek, linia))
		{
			cout << linia << endl;
		}
	}
	else cout << "Nie mam pliczku." << endl;
	pliczek.close();
	cout.width(37);
	cout << endl;
	cout << "KO�CI!" << endl;
	cout << endl;
}

void wypiszMenu()
{
	system("cls");
	// Wy�wietlam grafik� przedstawiaj�c� sze�ciany i wypisuj� menu gry
	grafika();
	cout.width(40);
	cout << "1. Graj" << endl;
	cout.width(38);
	cout << "2. Zasady" << endl;
	cout.width(47);
	cout << "3. Najwy�szy wynik" << endl;
	cout.width(43);
	cout << "4. Zamknij gr�" << endl;
	//U�ytkownik dokonuje wyboru
	int wybor{};
	cout << "Co chcesz zrobi� (1/2/3/4)?  ";
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		gra();
		break;
	case 2:
		zasady();
		break;
	case 3:
		ranking();
		break;
	case 4:
		zamknijGre();
		break;
	default:
		break;
	}
}

void zasady()
{
	system("cls");
	// Wy�wietlam grafik� przedstawiaj�c� sze�ciany
	grafika();
	cout.width(37);
	cout << "ZASADY" << endl;
	cout << endl;
	cout << "Cel gry" << endl;
	cout << "Celem gry w ko�ci jest zebranie najwi�kszej liczby punkt�w \
	\nprzyznawanych za r�ne kombinacje oczek na ko�ciach. \
	\nJe�li gracz pobije rekord gry, jego wynik wraz z imieniem \
	\nzostaj� zapisane w rankingu." << endl;
	cout << endl;
	cout << "Zasady gry" << endl;
	cout << "Gra sk�ada si� z 13 rund. W ka�dej rundzie gracz dysponuje 3 rzutami. \
	\nNa pocz�tku ka�dej rundy w konsoli wy�wietlaj� si� wyniki rzutu \n5 sze�ciennymi ko��mi. \
	Gracz ma mo�liwo�� dalszych rzut�w wybranymi ko��mi \nlub zapisu punkt�w do odpowiedniej rubryki."<< endl;
	cout << endl;
	cout << "Kombinacje" << endl;
	cout << "Jedynki - suma jedynek wyrzuconych na ko�ciach" << endl;
	cout << "Dw�jki - suma dw�jek wyrzuconych na ko�ciach" << endl;
	cout << "Tr�jki - suma tr�jek wyrzuconych na ko�ciach" << endl;
	cout << "Czw�rki - suma czw�rek wyrzuconych na ko�ciach" << endl;
	cout << "Pi�tki - suma pi�tek wyrzuconych na ko�ciach" << endl;
	cout << "Sz�stki - suma sz�stek wyrzuconych na ko�ciach" << endl;
	cout << "Trzy jednakowe - suma oczek na trzech ko�ciach o tej samej warto�ci ({3,3,3,1,2} => 9)" << endl;
	cout << "Cztery jednakowe - suma oczek na czterech ko�ciach o tej samej warto�ci ({3,3,3,3,2} => 12)" << endl;
	cout << "Ful - 25 pkt za zestaw {para + trzy jednakowe} (np. {4,4,1,1,1})" << endl;
	cout << "Ma�y strit - 30 pkt za zestaw 4 kolejnych liczb (np. {1,2,3,4,1})" << endl;
	cout << "Du�y strit - 40 pkt za zestaw 5 kolejnych liczb (np. {2,3,4,5,6})" << endl;
	cout << "Genera� - 50 pkt za zestaw 5 takich samych liczb" << endl;
	cout << "Szansa - suma oczek na wyrzuconych ko�ciach" << endl;
	// Dodatkowa opcja - powr�t do menu gry
	bool decyzja{};
	do
	{
		decyzja = 0;
		cout << "Wr�� do menu - 1 ";
		cin >> decyzja;
		if (decyzja == 1) wypiszMenu();
		else
		{
			cout << "Podaj 0 lub 1!" << endl;
		}
	} while (decyzja != 1);
}

void ranking()
{
	system("cls");
	// Wy�wietlam grafik� przedstawiaj�c� sze�ciany
	grafika();
	// Wypisuj� ranking w konsoli
	fstream plik;
	plik.open("ranking.txt", ios::in);
	string linijka;
	if (plik.is_open())
	{
		while (!plik.eof()) {
			getline(plik, linijka);
			cout << "                               ";
			cout << linijka << endl;
		}
	}
	else cout << "Nie otwieram." << endl;
	plik.close();
	// Dodatkowe opcje - czyszczenie rankingu i powr�t do menu gry
	bool decyzja{};
	do
	{
		decyzja = 0;
		cout << "Wyczy�� ranking - 0, wr�� do menu - 1 ";
		cin >> decyzja;
		if (decyzja == 0)
		{
			fstream plik;
			plik.open("ranking.txt",ios::out);
			plik.flush();
			plik.close();
			plik.open("ranking.txt", ios::out);
			plik << "Ranking jest pusty";
			plik.close();
			system("cls");
			ranking();
		}
		else if (decyzja == 1) wypiszMenu();
		else
		{
			cout << "Podaj 0 lub 1!" << endl;
		}
	} while (decyzja != 0 && decyzja != 1);

}

void zamknijGre()
{
	exit(0);
	exit(4);
}

void wypiszTabele()
{
	system("cls");
	int i = 0;
	//Wypisuj� kategorie i punkty
	//G�rna cz�� tabeli
	cout << endl;
	cout.width(20);
	cout << "PUNKTACJA" << endl;
	cout << endl;
	cout << "A";
	cout.width(18);
	cout << "jedynki " << tabela[i] << endl;
	i++;
	cout << "B";
	cout.width(18);
	cout << "dw�jki " << tabela[i] << endl;
	i++;
	cout << "C";
	cout.width(18);
	cout << "tr�jki " << tabela[i] << endl;
	i++;
	cout << "D";
	cout.width(18);
	cout << "czw�rki " << tabela[i] << endl;
	i++;
	cout << "E";
	cout.width(18);
	cout << "pi�tki " << tabela[i] << endl;
	i++;
	cout << "F";
	cout.width(18);
	cout << "sz�stki " << tabela[i] << endl;
	i++;
	//Dolna cz�� tabeli
	cout << "G";
	cout.width(18);
	cout << "trzy jednakowe " << tabela[i] << endl;
	i++;
	cout << "H";
	cout.width(18);
	cout << "cztery jednakowe " << tabela[i] << endl;
	i++;
	cout << "I";
	cout.width(18);
	cout << "ful " << tabela[i] << endl;
	i++;
	cout << "J";
	cout.width(18);
	cout << "ma�y strit " << tabela[i] << endl;
	i++;
	cout << "K";
	cout.width(18);
	cout << "du�y strit " << tabela[i] << endl;
	i++;
	cout << "L";
	cout.width(18);
	cout << "genera� " << tabela[i] << endl;
	i++;
	cout << "M";
	cout.width(18);
	cout << "szansa " << tabela[i] << endl;
	i++;
	cout.width(19);
	cout << "SUMA " << tabela[i] << endl;
	i++;
}

void wyswietlRzut()
{
	switch (runda)
	{
	case 1:
		for (int i = 0; i < 5; i++)
		{
			wyniki[i] = (rand() % 6) + 1;
			cout << wyniki[i] << "  ";
		}
		cout << endl;
		break;
	case 2:
		for (int i = 0; i < 5; i++)
		{
			cout << wyniki[i] << "  ";
		}
		cout << endl;
		break;
	case 3:
		for (int i = 0; i < 5; i++)
		{
			cout << wyniki[i] << "  ";
		}
		cout << endl;
		break;
	}
}

void koniecGry()
{
	najwyzszyWynik mistrz{};
	cout << "Tw�j wynik: " << tabela[13] << endl;
	int wynik = tabela[13];
	string imie = "";
	if (wynik > mistrz.wynik)
	{
		mistrz.wynik = wynik;
		cout << "Rekord gry zosta� pobity!" << endl;
		cout << "Podaj swoje imi�: ";
		cin >> imie;
		mistrz.imie = imie;
		cout << "Tw�j wynik i imi� zosta�y zapisane w rankingu gry. Gratulacje!" << endl;
		// Zapisuj� dane mistrza gry do pliku
		fstream plik;
		plik.open("ranking.txt", ios::out | ios::trunc);
		if (plik.is_open())
		{
			plik << "Najwy�szy wynik: " << mistrz.wynik << "\n";
			plik << "Mistrzem gry jest " << mistrz.imie;
		}
		plik.close();
	}
	// Dodatkowe opcje - zamkni�cie konsoli lub powr�t do menu gry
	bool decyzja{};
	do
	{
		decyzja = 0;
		cout << "Zamknij gr� - 0, wr�� do menu - 1 ";
		cin >> decyzja;
		if (decyzja == 0)
		{
			zamknijGre();
		}
		else if (decyzja == 1) wypiszMenu();
		else
		{
			cout << "Podaj 0 lub 1!" << endl;
		}
	} while (decyzja != 0 && decyzja != 1);
}

