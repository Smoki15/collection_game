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
	cout << "��� �������� ��������� �����, ������ ���� ������. \n��� ������ ��� - ENTER";
	cin.ignore();
	string res = rndWords();
	cout << endl << "\033[33m" << res << "\033[0m" << endl;
	auto startPlayer = high_resolution_clock::now();

	string user;
	while (res != user) {
		cin >> user;
		if (res == user) break;
		cout << "������� ����� �� ����. ��������� �� ���!\n";
	}

	auto endPlayer = high_resolution_clock::now();
	duration<double> elapsedPlayer = endPlayer - startPlayer;
	double timePlayer = elapsedPlayer.count();
	cout << "��� ���: " << timePlayer << endl;

	cout << "\n����� �� ";
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
	cout << "\n��� ��: " << timePC << endl;

	if (timePC > timePlayer) {
		cout << "�������� ������";
	}
	else if (timePC < timePlayer) {
		cout << "���������� ������";
	}
	else {
		cout << "ͳ���";
	}
}

void modTwo() {
	cout << "������� ����������� ������� ��� �� 1 ������� ��� ������� ��� - ENTER" << endl;
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
			cout << "����� �� ���� ��������� �� ���" << endl;
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
	cout << "���� ���: \n[1] ����� �� ����� \n[2] ���� �� 1�� \n �� �������? ";
	int game;
	cin >> game;
	switch (game) {
	case 1: modeW();
		break;
	case 2: modTwo();
		break;
	default: cout << "³������ �����";
		break;
	}



	int menu;
	cout << "[1] ��ղ� \n[2] ���� \n��� ����: ";
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