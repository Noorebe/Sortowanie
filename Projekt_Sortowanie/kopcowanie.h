#pragma once
#include <iostream>
#include <vector>
#include <ctime>   // Do funkcji time()
#include <fstream>
#include <string>
using namespace std;
class kopcowanie
{
public:
	kopcowanie();
	void Zapis(vector<int> Tablica, int rozmiar);
	void Wyswietl(vector<int> Tablica, int rozmiar);
	void Zamiana(vector<int>& Tablica, int i, int j);
	void Kopiec(vector<int>& Tablica, int rozmiar, int i);
	void Sortowanie(vector<int>& Tablica, int rozmiar);
	void Zmiana_Sortowania(vector<int>& Tablica, int rozmiar);
};

