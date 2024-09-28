#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

struct pet
{
    int idPet;
    string namaPet;
    string jenisPet;
    int umurPet;
    float beratPet;
    float hargaPet;
    pet *next;
};

void tambahPet(pet **head);
void tampilkanPet(pet *head);
int editPet(pet *head);
int hapusPet(pet **head);
float getFloatInput(const string &prompt);
string getStringInput(const string &prompt);
int getIntInput(const string &prompt);

int main()
{
    pet *linkedListPet = NULL;
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
            tambahPet(&linkedListPet);
            break;
        case 2:
            tampilkanPet(linkedListPet);
            break;
        case 3:
            status = editPet(linkedListPet);
            system("cls || clear");
            status == -1 ? cout << "ID Pet tidak ditemukan" << endl : cout << "Pet berhasil di edit" << endl;
            cout << "==================================" << endl;
            break;
        case 4:
            status = hapusPet(&linkedListPet);
            system("cls || clear");
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

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka desimal. Silakan coba lagi." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

        if (cin.fail() || value <= 0)
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

void tambahPet(pet **head)
{
    pet *nodePet = new pet;

    cout << "           == Tambah Pet ==" << endl;
    cout << "====================================" << endl;
    while (true)
    {
        nodePet->idPet = getIntInput("ID Pet \t\t\t: ");
        bool isUnique = true;
        pet *current = *head;
        while (current != NULL)
        {
            if (current->idPet == nodePet->idPet)
            {
                isUnique = false;
                break;
            }
            current = current->next;
        }

        if (isUnique)
        {
            break;
        }
        else
        {
            cout << "ID Pet sudah ada. Silakan masukkan ID yang berbeda." << endl;
        }
    }
    nodePet->namaPet = getStringInput("Nama Pet \t\t: ");
    nodePet->jenisPet = getStringInput("Jenis Pet \t\t: ");
    nodePet->umurPet = getIntInput("Umur Pet (Bulan)\t: ");
    nodePet->beratPet = getFloatInput("Berat Pet (Kg)\t\t: ");
    nodePet->hargaPet = getFloatInput("Harga Pet \t\t: Rp. ");
    nodePet->next = *head;
    *head = nodePet;
    system("cls || clear");
    cout << "Pet berhasil ditambahkan" << endl;
};

void tampilkanPet(pet *head)
{
    cout << "           == Tampilkan Pet ==" << endl;
    cout << "====================================" << endl;
    if (head == NULL)
    {
        cout << "Data Pet masih kosong" << endl;
    }
    else
    {
        pet *current = head;
        while (current != NULL)
        {
            cout << "ID Pet \t\t: " << current->idPet << endl;
            cout << "Nama Pet \t: " << current->namaPet << endl;
            cout << "Jenis Pet \t: " << current->jenisPet << endl;
            cout << "Umur Pet \t: " << current->umurPet << " Bulan" << endl;
            cout << "Berat Pet \t: " << current->beratPet << " Kg" << endl;
            cout << "Harga Pet \t: Rp. " << fixed << setprecision(2) << current->hargaPet << endl;
            cout << "====================================" << endl;
            current = current->next;
        }
    }

    cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
    cin.get();
    system("cls || clear");
};

int editPet(pet *head)
{
    cout << "           == Edit Pet ==" << endl;
    cout << "====================================" << endl;
    if (head == NULL)
    {
        cout << "Data Pet masih kosong" << endl;
        return -1;
    }
    else
    {
        int idPet = getIntInput("Masukkan ID Pet yang ingin di edit : ");
        pet *current = head;
        while (current != NULL)
        {
            if (current->idPet == idPet)
            {
                cout << "ID Pet \t\t: " << current->idPet << endl;
                cout << "Nama Pet \t: " << current->namaPet << endl;
                cout << "Jenis Pet \t: " << current->jenisPet << endl;
                cout << "Umur Pet \t: " << current->umurPet << " Bulan" << endl;
                cout << "Berat Pet \t: " << current->beratPet << " Kg" << endl;
                cout << "Harga Pet \t: Rp. " << current->hargaPet << endl;
                cout << "====================================" << endl;

                current->namaPet = getStringInput("Nama Pet \t\t: ");
                current->jenisPet = getStringInput("Jenis Pet \t\t: ");
                current->umurPet = getIntInput("Umur Pet (Bulan)\t: ");
                current->beratPet = getFloatInput("Berat Pet (Kg)\t\t: ");
                current->hargaPet = getFloatInput("Harga Pet \t\t: Rp. ");
                return 1;
            }
            current = current->next;
        }
        return -1;
    }
};

int hapusPet(pet **head)
{
    cout << "           == Hapus Pet ==" << endl;
    cout << "====================================" << endl;
    if (*head == NULL)
    {
        cout << "Data Pet masih kosong" << endl;
        return -1;
    }
    else
    {
        int idPet = getIntInput("Masukkan ID Pet yang ingin di hapus : ");
        pet *current = *head;
        pet *prev = NULL;
        while (current != NULL)
        {
            if (current->idPet == idPet)
            {
                if (prev == NULL)
                {
                    *head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return 1;
            }
            prev = current;
            current = current->next;
        }
        return -1;
    }
};
