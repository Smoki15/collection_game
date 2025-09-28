#include <iostream>
#include <vector>
#include <chrono>
#include <CoreWindow.h> 
#include "collection_game.h"

using namespace std;
using namespace std::chrono;

vector<string> words{ "speed", "animal", "apple", "banana", "menu" };

string rndWords() {
	return words[rand() % words.size()];
}

void modeW() {
	cout << "Вам надається випадкове слово, введіть його швидше. \nДля старту гри - ENTER";
	cin.ignore();
	string res = rndWords();
	cout << endl << "\033[33m" << res << "\033[0m" << endl;
	auto startPlayer = high_resolution_clock::now();

	string user;
	while (res != user) {
		cin >> user;
		if (res == user) break;
		cout << "Введено слово не вірно. Спробуйте ще раз!\n";
	}

	auto endPlayer = high_resolution_clock::now();
	duration<double> elapsedPlayer = endPlayer - startPlayer;
	double timePlayer = elapsedPlayer.count();
	cout << "Ваш час: " << timePlayer << endl;

	cout << "\nДрукує ПК ";
	auto pcPlayer = high_resolution_clock::now();
	for (int i = 0; i < 3; i++) {
		cout << ".";
		//cout.flush();
		Sleep(1000);
	}
	auto pc = high_resolution_clock::now();
	duration<double> player = pc - pcPlayer;
	int random = 500 + rand() % 1500;
	double timePC = player.count();
	cout << "\nЧас ПК: " << timePC << endl;

	if (timePC > timePlayer) {
		cout << "Компютер переміг";
	}
	else if (timePC < timePlayer) {
		cout << "Користувач переміг";
	}
	else {
		cout << "Нічья";
	}
}

void modTwo() {
	cout << "Введить максимальне кількість слів за 1 хвилину для початку гри - ENTER" << endl;
	cin.ignore();

	string user_words;
	int true_words = 0;

	auto start = steady_clock::now();


	while (true)
	{
		string res = rndWords();
		cout << endl << "\033[33m" << res << "\033[0m" << endl;
		cin >> user_words;
		if (res == user_words) {
			true_words++;
		}
		else {
			cout << "Слово не вірне спробуйте ще раз" << endl;
		}
		auto pc = high_resolution_clock::now();
		duration<double> player = pc - start;
		double timePC = player.count();
		if (timePC >= 10) {
			break;
		}
	}
}


int speed() {
	system("chcp 1251>null");
	srand(time(NULL));
	cout << "Меню гри: \n[1] Режим по слову \n[2] Друк за 1хв \n Що обираєте? ";
	int game;
	cin >> game;
	switch (game) {
	case 1: modeW();
		break;
	case 2: modTwo();
		break;
	default: cout << "Відсутній режим";
		break;
	}



	int menu;
	cout << "[1] ВИХІД \n[2] МЕНЮ \nВаш вибір: ";
	cin >> menu;
	int zmina = 0;
	switch (menu) {
	case 1: zmina = main();
		break;
	case 2: exit;
		break;
	default: cout << "ERROR";
		break;
	}
	return 0;
}