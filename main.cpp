#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

int tabela[14]{};
int wyniki[5]{};

int main()
{
	// Ta funkcja sprawia, ¿e za ka¿dym razem w programie pojawia siê inna sekwencja liczb
	srand(time(NULL));
	grafika();
	// Ustawiam polskie znaki
	setlocale(LC_CTYPE, "Polish");
	wypiszMenu();
	system("pause");
}