// gerke.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <fstream>
using namespace std;

int point(int speed) {
	return Beep(700, 300/speed); // частота сигнала 700 продолжительность 300
}

int dash(int speed) {
	return Beep(700, 900/speed); // частота сигнала 700 продолжительность 300
}

int morzeAlphabet(int letterNumber, int speed) {
	switch (letterNumber) {
	case 0:
		return point(speed), dash(speed);
		break;
	case 1:
		return dash(speed), point(speed), point(speed), point(speed);
		break;
	case 2:
		return dash(speed), point(speed), dash(speed), point(speed);
		break;
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int speed = 1;
	cout << "введите скорость ";
	cin >> speed;
	ifstream fin;
	char buff[50];
	char alphabet[3] = { 'a', 'b', 'c' };
	
	fin.open("text.txt");
	if (!fin.is_open()) {
		cout << "not found" << endl;
	}
	else {
		fin >> buff;
		while (strlen(buff) > 0) {	// перебираем слова
			for (int i = 0; i < strlen(buff); i++) { // вынимаем буквы
				cout << buff[i] << endl;
				for (int j = 0; j < 3; j++) { // 3 - кол букв в алфавите
					if (buff[i] == alphabet[j]) {
						morzeAlphabet(j, speed);
					}
				}
				Sleep(1000/speed);
			}
			cout << endl;  // пробел между словами
			fin >> buff;
		};
	}
	/*
	char buff[50]; // буфер промежуточного хранения считываемого из файла текста
	//ifstream fin("C:/Documents/text.txt"); // открыли файл
	ifstream fin;
	fin.open("C:/Documents/text.txt", ios::in);
	fin >> buff; // считали первое слово из файла
	cout << buff; */

	system("pause");
    return 0;
}

