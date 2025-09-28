#include "collection_game.h"
#include <iostream>
#include <locale>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

struct Task {
    string word;
    string hint;
    bool used = false;
};

string shuffleWord(const string& word) {
    string shuffled = word;
    static random_device rd;
    static mt19937 g(rd());
    shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int vgadai() {
    system("chcp 1251>null");
    ifstream file("riddle.txt");
    if (!file) {
        cout << "Файл riddle.txt не знайдено!" << endl;
        return 1;
    }

    vector<Task> tasks;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        size_t pos = line.find('|');
        if (pos != string::npos) {
            Task t;
            t.word = line.substr(0, pos);
            t.hint = line.substr(pos + 1);
            tasks.push_back(t);
        }
    }
    file.close();

    if (tasks.empty()) {
        cout << "Файл порожній!" << endl;
        return 0;
    }

    srand((unsigned)time(NULL));
    int penaltySeconds = 30;

    while (true) {
        vector<int> available;
        for (int i = 0; i < (int)tasks.size(); i++) {
            if (!tasks[i].used) available.push_back(i);
        }
        if (available.empty()) {
            cout << "\nУсі слова використані. Гра завершена!" << endl;
            break;
        }

        int randIndex = available[rand() % available.size()];
        Task& task = tasks[randIndex];
        task.used = true;

        string shuffled = shuffleWord(task.word);
        cout << "\nВідгадайте слово: " << shuffled << endl;

        bool guessed = false;
        bool hintUsed = false;

        auto start = steady_clock::now();

        while (!guessed) {
            cout << "\nВаш варіант (введіть 'hint' для підказки, 'exit' для виходу): ";
            string answer;
            cin >> answer;

            if (answer == "exit") {
                cout << "\nВи вийшли з гри." << endl;
                return 0;
            }

            if (answer == "hint") {
                cout << "Підказка: " << task.hint << endl;
                hintUsed = true;
                continue;
            }

            if (answer == task.word) {
                auto end = steady_clock::now();
                int seconds = duration_cast<std::chrono::seconds>(end - start).count();
                if (hintUsed) seconds += penaltySeconds;

                cout << "Правильно! Слово: " << task.word << endl;
                if (hintUsed) cout << "(Використана підказка, +" << penaltySeconds << " сек)" << endl;
                cout << "Час: " << seconds << " секунд" << endl;
                guessed = true;
            }
            else {
                cout << "Неправильно, спробуйте ще!" << endl;
            }
        }
    }

    return 0;
}
