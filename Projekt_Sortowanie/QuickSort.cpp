#include "QuickSort.h"

void QuickSort::swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}

int QuickSort::partition(std::vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort::quickSort(std::vector<int>& arr, int start, int end) {
	if (start < end) {
		int pivot = partition(arr, start, end);
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}

}
void QuickSort::Wyswietl(vector<int> Tablica, int rozmiar) {
	cout << "Dane: ";
	for (int i = 0; i < rozmiar; i++) {
		cout << Tablica[i] << " ";
	}
	cout << endl;
}