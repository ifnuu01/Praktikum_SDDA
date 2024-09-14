#include <iostream>
using namespace std;

int operasiPascal(int baris, int kolom)
{
    if (kolom == 0 || kolom == baris)
    {
        return 1;
    }

    return operasiPascal(baris - 1, kolom) + operasiPascal(baris - 1, kolom - 1);
}

void printPascalSikuSiku(int tingkat)
{
    for (int i = 0; i < tingkat; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << operasiPascal(i, j) << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int tingkat = 3;

    cout << "NAMA\t: Ifnu Umar\nNIM\t: 2309106060\n";
    cout << "TUGAS\t: Segitiga Pascal 3 Tingkat (Nim Genap), Segitiga Siku-Siku\n";
    cout << "JAWABAN\t:\n";
    printPascalSikuSiku(tingkat);
    return 0;
}
