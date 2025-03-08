#include "kopcowanie.h"

kopcowanie::kopcowanie()
{
}

void kopcowanie::Zapis(vector<int> Tablica, int rozmiar) {
    ofstream plik("zapis.txt", ios::app);

    if (plik.is_open()) {
        plik << "Dane:\n ";
        for (int i = 0; i < rozmiar; i++) {
            plik << Tablica[i] << "\n ";
        }
        plik << endl;
        plik << endl;
        plik.close();
    }
}

void kopcowanie::Wyswietl(vector<int> Tablica, int rozmiar) {
    cout << "Dane: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << Tablica[i] << " ";
    }
    cout << endl;
}

void kopcowanie::Zamiana(vector<int>& Tablica, int i, int j) {
    int zmienne = Tablica[j];
    Tablica[j] = Tablica[i];
    Tablica[i] = zmienne;
}

void kopcowanie::Kopiec(vector<int>& Tablica, int rozmiar, int i) {
    int najwiekszy = i;
    int lewy = 2 * i + 1; // Indeks lewego dziecka
    int prawy = 2 * i + 2; // Indeks prawego dziecka

    // Jeœli lewe dziecko istnieje i jest wiêksze od korzenia
    if (lewy < rozmiar && Tablica[lewy] > Tablica[najwiekszy])
        najwiekszy = lewy;

    if (prawy < rozmiar && Tablica[prawy] > Tablica[najwiekszy])
        najwiekszy = prawy;

    // Jeœli najwiêkszy element nie jest korzeniem
    if (najwiekszy != i) {
        Zamiana(Tablica, i, najwiekszy); // Zamieñ korzeñ z najwiêkszym elementem
        Kopiec(Tablica, rozmiar, najwiekszy); // Przebuduj poddrzewo, aby zachowaæ strukturê kopca
    }
}

void kopcowanie::Sortowanie(vector<int>& Tablica, int rozmiar) {

    //Budowane kopca
    for (int i = rozmiar / 2 - 1; i >= 0; i--) {
        Kopiec(Tablica, rozmiar, i);
    }

    for (int i = rozmiar - 1; i >= 0; i--) {
        Zamiana(Tablica, 0, i); //Zamiana korzenia z ostatnim elementem
        Kopiec(Tablica, i, 0);
    }
}

void kopcowanie::Zmiana_Sortowania(vector<int>& Tablica, int rozmiar) {
    for (int i = 0; i < rozmiar / 2; i++) {
        // Zamieniamy miejsca elementów symetrycznych wzglêdem œrodka wektora
        int zamienna = Tablica[i];
        Tablica[i] = Tablica[rozmiar - 1 - i];
        Tablica[rozmiar - 1 - i] = zamienna;
    }
}