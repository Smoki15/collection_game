#include <iostream>
#include "Rozg.h"
#include "vgad.h"
#include "sped.h"

using namespace std;

int main()
{
	system("chcp 1251>null");
	int collection;
	cout << "КОЛЕКЦІЯ ІГОР: \n[1] Швидкість друку \n[2] Вгадай слово \n[3] Розгадай загадку \nВаш вибір: ";
	cin >> collection;
	int zmina = 0;
	switch (collection) {
	case 1: zmina = speed();
		break;
	case 2: zmina = vgadai();
		break;
	case 3: zmina = rozgadai();
		break;
	default: cout << "ERROR";
		break;
	}
}
