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
		{"Йде то в гору, то з гори, але залишається на місці",  "дорога"},
		{ "По якій тварині ходять люди і проїжджають машини",  "зебра" },
		{ "Зав'язати можна, а розв'язати не можна",  "розмова" },
		{ "Перед яким простим смертним навіть президент знімає шапку", "перукар" },
		{"Без рук, без ніг, а малювати вміє", "тінь"},
		{"Біжить, а ніг не має", "річка"},
		{"Крила є — не літає, очі є — не моргає", "окуляри"},
		{"Не людина, а говорить", "дзвінок"}
	};
	int random = rand() % riddle;
	cout << "Загадка: " << masiv[random][0] << endl;
	string answer = masiv[random][1];
	int  len = answer.size();
	string bol = "";
	int count = 0;
	for (int i = 0; i < len; i++) {
		bol += "*";

	}
	cout << "Cлово: " << bol << endl;

	auto startPlayer = high_resolution_clock::now();
	while (true)
	{
		cout << "\nМеню: \n[1] літера \n[2] слово \n[3] підсказка \n[4] вихід \nВведіть цифру: ";
		int choice;
		cin >> choice;

		if (choice == 1) {
			char litra;
			cout << "Введіть літеру: ";
			cin >> litra;
			int a = 0;
			for (int i = 0; i < len; i++) {
				if (litra == answer[i] && bol[i] == '*') {
					bol[i] == litra;
					a = 1;
				}
			}
			if (a == 0) {
				cout << "Такої літери немає";
			}
			else {
				cout << "слово: " << bol;
			}
		}
		else if (choice == 2) {
			cout << "Ваше слово: ";
			string user_answer;
			cin >> user_answer;
			if (user_answer == answer) {
				cout << "Ви вгадали!";
				count++;
				break;
			}
			else {
				cout << "Відповідь не вірна: (спробуй ще раз)";
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
			cout << "Ви скористалися підсказкую: " << bol;
		}
		else if (choice == 4) {
			cout << "Гра завершилась, статистика збереглась";
			break;
		}
	}

	auto endPlayer = high_resolution_clock::now();
	duration<double> elapsedPlayer = endPlayer - startPlayer;
	double timePlayer = elapsedPlayer.count();
	file << count << ") Слово" << answer << " Було вгадано за " << timePlayer << "сек." << endl;
	cout << "Статистику збережено";


	cout << endl;
	int menu;
	cout << "\n[1] ВИХІД \n[2] МЕНЮ \nВаш вибір: ";
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