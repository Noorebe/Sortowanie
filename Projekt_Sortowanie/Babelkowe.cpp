#include "Babelkowe.h"

void Babelkowe::Wypisz(const vector<int>& vec)
{
    for (const auto& val : vec)
        cout << val << " ";
    cout << endl << endl;
}

void Babelkowe::Sortowanie(vector<int>& vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
        for (size_t j = 0; j < vec.size() - 1; j++)
            if (vec[j] > vec[j + 1])
            {
                int pomoc = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = pomoc;
            }
}




