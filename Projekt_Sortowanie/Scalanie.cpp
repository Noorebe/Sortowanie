
#include "Scalanie.h"


//Sortowanie przez scalenie
void Scalanie::merge(vector<int>& A, int left, int mid, int right) {
;
    int n1 = mid - left + 1; // Rozmiar lewej podtablicy
    int n2 = right - mid;    // Rozmiar prawej podtablicy

    // Tworzenie tablic pomocniczych dla lewej i prawej podtablicy
    vector<int> L(n1);
    vector<int> R(n2);

    // Kopiowanie danych do tablic pomocniczych
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // Scalanie tablic pomocniczych z powrotem do tablicy A
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozosta�ych element�w z lewej tablicy pomocniczej (je�li takie s�)
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozosta�ych element�w z prawej tablicy pomocniczej (je�li takie s�)
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}


void Scalanie::mergesort(vector<int>& A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Obliczenie �rodka przedzia�u

        // Rekurencyjne sortowanie lewej i prawej po�owy tablicy
        mergesort(A, left, mid);
        mergesort(A, mid + 1, right);

        // Scalanie posortowanych cz�ci tablicy
        merge(A, left, mid, right);
    }

}




