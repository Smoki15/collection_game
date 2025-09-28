#include <iostream>
#include "collection_game.h"
#include "chrono";
#include <fstream>


using namespace std;
using namespace chrono;


int rozgadai() {
	system("chcp 1251>null");

	srand(time(NULL));

	ofstream file("info.txt", ios::app);
	if (!file) {
		cout << "ERROR" << endl;
		return 0;
	}

	const int riddle = 8, call = 2;
	string masiv[riddle][call]{
		{"��� �� � ����, �� � ����, ��� ���������� �� ����",  "������"},
		{ "�� ��� ������ ������ ���� � ���������� ������",  "�����" },
		{ "���'����� �����, � ����'����� �� �����",  "�������" },
		{ "����� ���� ������� �������� ����� ��������� ���� �����", "�������" },
		{"��� ���, ��� ��, � �������� �쳺", "���"},
		{"������, � �� �� ��", "����"},
		{"����� � � �� ���, ��� � � �� �����", "�������"},
		{"�� ������, � ��������", "������"}
	};
	int random = rand() % riddle;
	cout << "�������: " << masiv[random][0] << endl;
	string answer = masiv[random][1];
	int  len = answer.size();
	string bol = "";
	int count = 0;
	for (int i = 0; i < len; i++) {
		bol += "*";

	}
	cout << "C����: " << bol << endl;

	auto startPlayer = high_resolution_clock::now();
	while (true)
	{
		cout << "\n����: \n[1] ����� \n[2] ����� \n[3] �������� \n[4] ����� \n������ �����: ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			char litra;
			cout << "������ �����: ";
			cin >> litra;
			int a = 0;
			for (int i = 0; i < len; i++) {
				if (litra == answer[i] && bol[i] == '*') {
					bol[i] == litra;
					a = 1;
				}
			}
			if (a == 0) {
				cout << "���� ����� ����";
			}
			else {
				cout << "�����: " << bol;
			}
		}
		else if (choice == 2) {
			cout << "���� �����: ";
			string user_answer;
			cin >> user_answer;
			if (user_answer == answer) {
				cout << "�� �������!";
				count++;
				break;
			}
			else {
				cout << "³������ �� ����: (������� �� ���)";
				continue;
			}
		}
		else if (choice == 3) {
			int rnd = rand() % len;
			char rand1 = answer[rnd];
			for (int i = 0; i < len; i++) {
				if (answer[i] == rand1 && bol[i] == '*') {
					bol[i] = rand1;
					cout << rand1;
				}
			}
			cout << "�� ������������ ���������: " << bol;
		}
		else if (choice == 4) {
			cout << "��� �����������, ���������� ����������";
			break;
		}
	}

	auto endPlayer = high_resolution_clock::now();
	duration<double> elapsedPlayer = endPlayer - startPlayer;
	double timePlayer = elapsedPlayer.count();
	file << count << ") �����" << answer << " ���� ������� �� " << timePlayer << "���." << endl;
	cout << "���������� ���������";


	cout << endl;
	int menu;
	cout << "\n[1] ��ղ� \n[2] ���� \n��� ����: ";
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