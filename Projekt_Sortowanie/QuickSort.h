#pragma once
#include "kopcowanie.h"

using namespace std;
class QuickSort
{
public:
	void swap(int& a, int& b);
	int partition(std::vector<int>& arr, int low, int high);
	void quickSort(std::vector<int>& arr, int start, int end);
	void Wyswietl(vector<int> Tablica, int rozmiar);
};

