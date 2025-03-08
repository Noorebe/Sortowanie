#include "QuickSort.h"
#include "Scalanie.h"
#include "Babelkowe.h"


using namespace std;

int main()
{
    kopcowanie k;
    QuickSort q;
    Scalanie s;
    Babelkowe b;
    int opcja;
    cout << "Wybierz opcje:\n1 - sortowanie przez kopcowanie,\n2 - QuickSort,\n3-sortowanie przez scalanie,\n4- sortowanie babelkowe,\ninna - wyjscie\n";
    cin >> opcja;

    int n; // Zmienna n zadeklarowana na pocz¹tku funkcji main()

    ifstream file("plik.txt"); // Otwieramy plik do odczytu
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku!" << endl;
        return 1; // Zakoñcz program z kodem b³êdu
    }

    vector<int> A;
    int ilosc;

    while (file >> ilosc) { // Wczytujemy liczby z pliku do wektora
        A.push_back(ilosc);
    }

    file.close(); // Zamykamy plik

    // Wypisujemy iloœæ elementów
    n = A.size();

    k.Wyswietl(A, n);

    switch (opcja)
    {
    case 1:
        int wybor;
        do {
            cout << "1-sortowanie niemalejace, 2- sortowanie nierosnace: ";
            cin >> wybor;
        } while (wybor != 1 && wybor != 2);

        k.Sortowanie(A, n);

        switch (wybor)
        {
        case 1:
            cout << "Po kopcowaniu ";
            k.Wyswietl(A, n);
            break;
        case 2:
            k.Zmiana_Sortowania(A, n);
            cout << "Po kopcowaniu ";
            k.Wyswietl(A, n);
            break;
        default:
            cout << "Zle podana opcja.";
            break;
        }
        break;
    case 2:
        q.quickSort(A, 0, n-1);
        cout << "Po QuickSort ";
        q.Wyswietl(A, n);
        break;
    case 3:

        s.mergesort(A, 0, n - 1);


        cout << "Posortowana tablica: ";
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        cout << endl;
        break;
    case 4:
        b.Sortowanie(A);

        cout << "Po sortowaniu:" << endl;
        b.Wypisz(A);
    default:
        cout << "Zakonczono program.";
        break;
    }
    k.Zapis(A, n);
    return 0;
}
