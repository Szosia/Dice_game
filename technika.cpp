#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

// Tworzê strukturê zawieraj¹c¹ najwy¿szy osi¹gniêty w grze wynik i imiê osoby, która pobi³a rekord
struct najwyzszyWynik
{
	string imie;
	int wynik;
};

void grafika()
{
	// Wyœwietlam grafikê przedstawiaj¹c¹ szeœciany i wypisujê menu gry
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
	cout << "KOŒCI!" << endl;
	cout << endl;
}

void wypiszMenu()
{
	system("cls");
	// Wyœwietlam grafikê przedstawiaj¹c¹ szeœciany i wypisujê menu gry
	grafika();
	cout.width(40);
	cout << "1. Graj" << endl;
	cout.width(38);
	cout << "2. Zasady" << endl;
	cout.width(47);
	cout << "3. Najwy¿szy wynik" << endl;
	cout.width(43);
	cout << "4. Zamknij grê" << endl;
	//U¿ytkownik dokonuje wyboru
	int wybor{};
	cout << "Co chcesz zrobiæ (1/2/3/4)?  ";
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
	// Wyœwietlam grafikê przedstawiaj¹c¹ szeœciany
	grafika();
	cout.width(37);
	cout << "ZASADY" << endl;
	cout << endl;
	cout << "Cel gry" << endl;
	cout << "Celem gry w koœci jest zebranie najwiêkszej liczby punktów \
	\nprzyznawanych za ró¿ne kombinacje oczek na koœciach. \
	\nJeœli gracz pobije rekord gry, jego wynik wraz z imieniem \
	\nzostaj¹ zapisane w rankingu." << endl;
	cout << endl;
	cout << "Zasady gry" << endl;
	cout << "Gra sk³ada siê z 13 rund. W ka¿dej rundzie gracz dysponuje 3 rzutami. \
	\nNa pocz¹tku ka¿dej rundy w konsoli wyœwietlaj¹ siê wyniki rzutu \n5 szeœciennymi koœæmi. \
	Gracz ma mo¿liwoœæ dalszych rzutów wybranymi koœæmi \nlub zapisu punktów do odpowiedniej rubryki."<< endl;
	cout << endl;
	cout << "Kombinacje" << endl;
	cout << "Jedynki - suma jedynek wyrzuconych na koœciach" << endl;
	cout << "Dwójki - suma dwójek wyrzuconych na koœciach" << endl;
	cout << "Trójki - suma trójek wyrzuconych na koœciach" << endl;
	cout << "Czwórki - suma czwórek wyrzuconych na koœciach" << endl;
	cout << "Pi¹tki - suma pi¹tek wyrzuconych na koœciach" << endl;
	cout << "Szóstki - suma szóstek wyrzuconych na koœciach" << endl;
	cout << "Trzy jednakowe - suma oczek na trzech koœciach o tej samej wartoœci ({3,3,3,1,2} => 9)" << endl;
	cout << "Cztery jednakowe - suma oczek na czterech koœciach o tej samej wartoœci ({3,3,3,3,2} => 12)" << endl;
	cout << "Ful - 25 pkt za zestaw {para + trzy jednakowe} (np. {4,4,1,1,1})" << endl;
	cout << "Ma³y strit - 30 pkt za zestaw 4 kolejnych liczb (np. {1,2,3,4,1})" << endl;
	cout << "Du¿y strit - 40 pkt za zestaw 5 kolejnych liczb (np. {2,3,4,5,6})" << endl;
	cout << "Genera³ - 50 pkt za zestaw 5 takich samych liczb" << endl;
	cout << "Szansa - suma oczek na wyrzuconych koœciach" << endl;
	// Dodatkowa opcja - powrót do menu gry
	bool decyzja{};
	do
	{
		decyzja = 0;
		cout << "Wróæ do menu - 1 ";
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
	// Wyœwietlam grafikê przedstawiaj¹c¹ szeœciany
	grafika();
	// Wypisujê ranking w konsoli
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
	// Dodatkowe opcje - czyszczenie rankingu i powrót do menu gry
	bool decyzja{};
	do
	{
		decyzja = 0;
		cout << "Wyczyœæ ranking - 0, wróæ do menu - 1 ";
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
	//Wypisujê kategorie i punkty
	//Górna czêœæ tabeli
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
	cout << "dwójki " << tabela[i] << endl;
	i++;
	cout << "C";
	cout.width(18);
	cout << "trójki " << tabela[i] << endl;
	i++;
	cout << "D";
	cout.width(18);
	cout << "czwórki " << tabela[i] << endl;
	i++;
	cout << "E";
	cout.width(18);
	cout << "pi¹tki " << tabela[i] << endl;
	i++;
	cout << "F";
	cout.width(18);
	cout << "szóstki " << tabela[i] << endl;
	i++;
	//Dolna czêœæ tabeli
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
	cout << "ma³y strit " << tabela[i] << endl;
	i++;
	cout << "K";
	cout.width(18);
	cout << "du¿y strit " << tabela[i] << endl;
	i++;
	cout << "L";
	cout.width(18);
	cout << "genera³ " << tabela[i] << endl;
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
	cout << "Twój wynik: " << tabela[13] << endl;
	int wynik = tabela[13];
	string imie = "";
	if (wynik > mistrz.wynik)
	{
		mistrz.wynik = wynik;
		cout << "Rekord gry zosta³ pobity!" << endl;
		cout << "Podaj swoje imiê: ";
		cin >> imie;
		mistrz.imie = imie;
		cout << "Twój wynik i imiê zosta³y zapisane w rankingu gry. Gratulacje!" << endl;
		// Zapisujê dane mistrza gry do pliku
		fstream plik;
		plik.open("ranking.txt", ios::out | ios::trunc);
		if (plik.is_open())
		{
			plik << "Najwy¿szy wynik: " << mistrz.wynik << "\n";
			plik << "Mistrzem gry jest " << mistrz.imie;
		}
		plik.close();
	}
	// Dodatkowe opcje - zamkniêcie konsoli lub powrót do menu gry
	bool decyzja{};
	do
	{
		decyzja = 0;
		cout << "Zamknij grê - 0, wróæ do menu - 1 ";
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

