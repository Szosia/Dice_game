#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

int tabela[14]{};
int wyniki[5]{};

int main()
{
	srand(time(NULL));
	//Ustawiam polskie znaki
	setlocale(LC_CTYPE, "Polish");
	wypiszMenu();
	system("pause");
}