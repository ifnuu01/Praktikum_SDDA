#include <iostream>
#include <limits>
using namespace std;

struct pet
{
    int idPet;
    string namaPet;
    string jenisPet;
    int umurPet;
    float beratPet;
    float hargaPet;
};

void tambahPet(pet *arrPet, int &totalPet, int &dayatampungPet);
void tampilkanPet(pet *arrPet, int totalPet, int dayatampungPet);
int editPet(pet *arrPet, int totalPet);
int hapusPet(pet *arrPet, int &totalPet);
float getFloatInput(const string &prompt);
string getStringInput(const string &prompt);
int getIntInput(const string &prompt);

int main()
{
    int totalPet = 0;
    int dayatampungPet = 100;
    pet arrPet[dayatampungPet];
    arrPet[0] = {1, "Bobby", "Anjing", 12, 5.5, 150000.0};
    totalPet++;
    int status;

    int pilihan;
    do
    {
        cout << "==========================" << endl;
        cout << "\tMenu Pet Shop" << endl;
        cout << "\t1. Tambah Pet" << endl;
        cout << "\t2. Tampilkan Pet" << endl;
        cout << "\t3. Edit Pet" << endl;
        cout << "\t4. Hapus Pet" << endl;
        cout << "\t5. Keluar" << endl;
        cout << "==========================" << endl;
        pilihan = getIntInput("Pilihan : ");
        system("cls || clear");

        switch (pilihan)
        {
        case 1:
            tambahPet(arrPet, totalPet, dayatampungPet);
            break;
        case 2:
            tampilkanPet(arrPet, totalPet, dayatampungPet);
            break;
        case 3:
            status = editPet(arrPet, totalPet);
            status == -1 ? cout << "ID Pet tidak ditemukan" << endl : cout << "Pet berhasil di edit" << endl;
            cout << "==================================" << endl;
            break;
        case 4:
            status = hapusPet(arrPet, totalPet);
            status == -1 ? cout << "ID Pet tidak ditemukan" << endl : cout << "Pet berhasil dihapus" << endl;
            cout << "==================================" << endl;
            break;
        case 5:
            cout << " == Terima kasih telah menggunakan aplikasi ini == " << endl;
            return 0;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}

float getFloatInput(const string &prompt)
{
    float value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka desimal. Silakan coba lagi." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter tambahan
            return value;
        }
    }
}

string getStringInput(const string &prompt)
{
    string value;
    while (true)
    {
        cout << prompt;
        getline(cin, value);

        if (value.empty() || value.find(' ') != string::npos)
        {
            cout << "Input tidak boleh kosong atau mengandung spasi. Silakan coba lagi." << endl;
        }
        else
        {
            return value;
        }
    }
}

int getIntInput(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka. Silakan coba lagi." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void tambahPet(pet *arrPet, int &totalPet, int &dayatampungPet)
{

    if (totalPet >= dayatampungPet)
    {
        cout << "Daya tampung kandang untuk pet sudah penuh" << endl;
        return;
    }
    cout << "== Tambah Pet ==" << endl;
    cout << "==================================" << endl;
    while (true)
    {
        arrPet[totalPet].idPet = getIntInput("ID Pet\t\t: ");
        for (int i = 0; i < totalPet; i++)
        {
            if (arrPet[i].idPet == arrPet[totalPet].idPet)
            {
                cout << "ID Pet sudah digunakan" << endl;
                break;
            }
        }
        if (arrPet[totalPet].idPet != arrPet[totalPet - 1].idPet)
        {
            break;
        }
    }
    arrPet[totalPet].namaPet = getStringInput("Nama Pet\t: ");
    arrPet[totalPet].jenisPet = getStringInput("Jenis Pet\t: ");
    arrPet[totalPet].umurPet = getIntInput("Umur Pet (Bulan): ");
    arrPet[totalPet].beratPet = getFloatInput("Berat Pet\t: ");
    arrPet[totalPet].hargaPet = getFloatInput("Harga Pet\t: ");
    totalPet++;
    system("cls || clear");
    cout << "Pet berhasil ditambahkan" << endl;
}

void tampilkanPet(pet *arrPet, int totalPet, int dayatampungPet)
{
    if (totalPet == 0)
    {
        cout << "Belum ada pet yang ditambahkan" << endl;
    }
    else
    {
        cout << "==================================" << endl;
        cout << "            Daftar Pet" << endl;
        cout << "==================================" << endl;
        for (int i = 0; i < totalPet; i++)
        {
            cout << "ID Pet\t\t: " << arrPet[i].idPet << endl;
            cout << "Nama Pet\t: " << arrPet[i].namaPet << endl;
            cout << "Jenis Pet\t: " << arrPet[i].jenisPet << endl;
            cout << "Umur Pet\t: " << arrPet[i].umurPet << " (Bulan)" << endl;
            cout << "Berat Pet\t: " << arrPet[i].beratPet << " (Kg)" << endl;
            cout << "Harga Pet\t: " << "Rp. " << arrPet[i].hargaPet << endl;
            cout << "==================================" << endl;
        }
    }

    cout << "==================================" << endl;
    cout << " Total Pet Saat Ini    : " << totalPet << endl;
    cout << " Sisa Daya Tampung Pet : " << dayatampungPet - totalPet << endl;
    cout << "==================================" << endl;
    cout << "Tekan Enter 2x untuk kembali ke menu" << endl;
    cin.ignore();
    cin.get();
    system("cls || clear");
}

int editPet(pet *arrPet, int totalPet)
{
    int idPet;
    idPet = getIntInput("Masukkan ID Pet yang ingin di edit : ");

    for (int i = 0; i < totalPet; i++)
    {
        if (arrPet[i].idPet == idPet)
        {
            arrPet[i].namaPet = getStringInput("Nama Pet\t: ");
            arrPet[i].jenisPet = getStringInput("Jenis Pet\t: ");
            arrPet[i].umurPet = getIntInput("Umur Pet (Bulan): ");
            arrPet[i].beratPet = getFloatInput("Berat Pet\t: ");
            arrPet[i].hargaPet = getFloatInput("Harga Pet\t: ");
            system("cls || clear");
            return 1;
        }
    }
    system("cls || clear");
    return -1;
}

int hapusPet(pet *arrPet, int &totalPet)
{
    int idPet;
    idPet = getIntInput("Masukkan ID Pet yang ingin di hapus : ");

    for (int i = 0; i < totalPet; i++)
    {
        if (arrPet[i].idPet == idPet)
        {
            for (int j = i; j < totalPet; j++)
            {
                arrPet[j] = arrPet[j + 1];
            }
            totalPet--;
            system("cls || clear");
            return 1;
        }
    }
    system("cls || clear");
    return -1;
}