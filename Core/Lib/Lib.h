#pragma once

#define _CRT_SECURE_NO_WARNINGS
//<--------iostream-------->
#include <iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<iomanip>
//<--------std-------->
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::ifstream;
using std::setw;
//<--------define-------->
#define center 55
#define CLEAR system("cls")
#define PAUSE system("PAUSE")
int GetMaxGames(); 
static int gamesAvailable= GetMaxGames();
static string* gamesAvailableArr = new string[gamesAvailable];

static int usersAmount = 0;
static string* userNames;
static int index = 0;

static int GetMaxGames() {
    string buf;
    ifstream f1("../Inf/GamesNames.txt", ios::in);
    if (f1.is_open()) {
        while (getline(f1, buf)) {
            gamesAvailable++;
        }
        f1.close();
    }
    else {
        cout << "Error opening file!!" << endl;
    }

    return gamesAvailable;
}
static void PrintPhrase(string phrase, int dig) {
    char inStr[256];
    _itoa(dig, inStr, 10);
    string str = string(inStr);
    string s = phrase + str ;

    int width_field = 105; //ширина поля
    string v(width_field, ' '); //для наглядности заполняем точками
    string v1;

    int l_word = s.size();
    int l_field = v.size();
    int step = (l_field - l_word) / 2;

    for (int i = 0; i < l_word; i++) {
        v1.push_back(s[i]);
    }
    copy(v1.begin(), v1.end(), v.begin() + step);
    for (auto x : v) {
        cout << x;
    }
    cout << endl;
}

static void PrintWord(string phrase) {
   

    int width_field = 105; //ширина поля
    string v(width_field, ' '); //для наглядности заполняем точками
    string v1;

    int l_word = phrase.size();
    int l_field = v.size();
    int step = (l_field - l_word) / 2;

    for (int i = 0; i < l_word; i++) {
        v1.push_back(phrase[i]);
    }
    copy(v1.begin(), v1.end(), v.begin() + step);
    for (auto x : v) {
        cout << x;
    }
    cout << endl;
}



