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
bool isEmpty(pet *head);
void peek(pet *head);
void front(pet *head);
void rear(pet *head);
float getFloatInput(const string &prompt);
string getStringInput(const string &prompt);
int getIntInput(const string &prompt);
void splitList(pet *head, pet **left, pet **right);
pet *mergeListAsc(pet *left, pet *right);
void mergeSortAsc(pet **head);
void shellSortDesc(pet **head);
void display(pet *head);

int main()
{
    pet *linkedListPet = NULL;
    int status;
    int pilihan;
    do
    {
        cout << "=========================================" << endl;
        cout << "             MENU PETS SHOP" << endl;
        cout << "\t1. Tambah Pet (Stack / Queue)" << endl;
        cout << "\t2. Tampilkan Pet" << endl;
        cout << "\t3. Edit Pet" << endl;
        cout << "\t4. Hapus Pet  (Stack / Queue)" << endl;
        cout << "\t5. Merge Sort Harg Pet (ASC)" << endl;
        cout << "\t6. Shell Sort Harga Pet (DSC)" << endl;
        cout << "\t7. Keluar" << endl;
        cout << "==========================================" << endl;
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
            if (status == -1)
            {
                cout << "Pet tidak ditemukan" << endl;
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            else if (status == -2)
                system("cls || clear");
            else
            {
                cout << "Pet berhasil diubah" << endl;
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            break;
        case 4:
            status = hapusPet(&linkedListPet);
            if (status == -1)
            {
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            else if (status == -2)
                system("cls || clear");
            else
            {
                cout << "Pet berhasil dihapus" << endl;
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            break;
        case 5:
            mergeSortAsc(&linkedListPet);
            display(linkedListPet);
            cout << "Data Pet berhasil diurutkan secara Ascending menggunakan Merge Sort" << endl;
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 6:
            shellSortDesc(&linkedListPet);
            display(linkedListPet);
            cout << "Data Pet berhasil diurutkan secara Descending menggunakan Shell Sort" << endl;
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 7:
            cout << " == PROGRAM MANAGEMENT PETS SHOP BERAKHIR == " << endl;
            return 0;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (pilihan != 7);
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
    int pilihanTambah;

    while (true)
    {
        cout << "          OPSI TAMBAH DATA :" << endl;
        cout << "=========================================" << endl;
        cout << "1. Menambahkan di Awal  (Push)    <Stack>" << endl;
        cout << "2. Menambahkan di Akhir (Enqueue) <Queue>" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "=========================================" << endl;
        pilihanTambah = getIntInput("OPSI ANDA : ");

        if (pilihanTambah == 1 || pilihanTambah == 2)
            break;
        else if (pilihanTambah == 3)
        {
            system("cls || clear");
            return;
        }
        else
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }

    pet *nodePet = new pet;
    cout << "           == Tambah Pet ==" << endl;
    cout << "=========================================" << endl;
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

    if (pilihanTambah == 1)
    {
        nodePet->next = *head;
        *head = nodePet;
    }
    else if (pilihanTambah == 2)
    {
        if (*head == NULL) // jika data null maka itu adalah data awal
        {
            *head = nodePet;
            nodePet->next = NULL;
        }
        else
        {
            pet *temp = *head;
            while (temp->next != NULL) // Karena saya tidak menggunakan tail maka saya perlu mencari data paling akhir untuk ditambahkan
                temp = temp->next;
            temp->next = nodePet;
            nodePet->next = NULL;
        }
    }

    system("cls || clear");
    cout << "Pet berhasil ditambahkan." << endl;
}

void tampilkanPet(pet *head)
{
    cout << "           == Tampilkan Pet ==" << endl;
    cout << "=========================================\n"
         << endl;

    if (head == NULL)
    {
        cout << "Data Pet masih kosong" << endl;
    }
    else
    {
        cout << "                PILIH OPSI" << endl;
        cout << "=========================================" << endl;
        cout << "1. Tampilkan Semua Data" << endl;
        cout << "2. Tampilkan Data Teratas  (Peek) <Stack>" << endl;
        cout << "3. Tampilkan Data Pertama  (Front)<Queue>" << endl;
        cout << "4. Tampilkan Data Terakhir (Rear) <Queue>" << endl;
        cout << "5. Cek Data Kosong <isEmpety>" << endl;
        cout << "6. Kembali ke Menu Utama" << endl;
        cout << "=========================================\n"
             << endl;
        int tampilOpsi = getIntInput("OPSI ANDA : ");
        system("cls || clear");
        pet *current = head;
        switch (tampilOpsi)
        {
        case 1:
            display(head);
            break;
        case 2:
            peek(head);
            break;
        case 3:
            front(head);
            break;
        case 4:
            rear(head);
            break;
        case 5:
            cout << (isEmpty(head) ? "Data kosong" : "Data tidak kosong") << endl;
            break;
        case 6:
            return;
            break;
        default:
            cout << "Opsi tidak tersedia." << endl;
            break;
        }
    }
    cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
    cin.get();
    system("cls || clear");
}

void display(pet *head)
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

bool isEmpty(pet *head)
{
    return head == NULL;
}

void peek(pet *head)
{
    if (isEmpty(head))
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        cout << "Data teratas (Peek):" << endl;
        cout << "====================================" << endl;
        cout << "ID Pet \t\t: " << head->idPet << endl;
        cout << "Nama Pet \t: " << head->namaPet << endl;
        cout << "Jenis Pet \t: " << head->jenisPet << endl;
        cout << "Umur Pet \t: " << head->umurPet << " Bulan" << endl;
        cout << "Berat Pet \t: " << head->beratPet << " Kg" << endl;
        cout << "Harga Pet \t: Rp. " << fixed << setprecision(2) << head->hargaPet << endl;
        cout << "====================================" << endl;
    }
}

void front(pet *head)
{
    if (isEmpty(head))
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        cout << "Data pertama (Front):" << endl;
        cout << "====================================" << endl;
        cout << "ID Pet \t\t: " << head->idPet << endl;
        cout << "Nama Pet \t: " << head->namaPet << endl;
        cout << "Jenis Pet \t: " << head->jenisPet << endl;
        cout << "Umur Pet \t: " << head->umurPet << " Bulan" << endl;
        cout << "Berat Pet \t: " << head->beratPet << " Kg" << endl;
        cout << "Harga Pet \t: Rp. " << fixed << setprecision(2) << head->hargaPet << endl;
        cout << "====================================" << endl;
    }
}

void rear(pet *head)
{
    if (isEmpty(head))
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        pet *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        cout << "Data terakhir (Rear):" << endl;
        cout << "====================================" << endl;
        cout << "ID Pet \t\t: " << current->idPet << endl;
        cout << "Nama Pet \t: " << current->namaPet << endl;
        cout << "Jenis Pet \t: " << current->jenisPet << endl;
        cout << "Umur Pet \t: " << current->umurPet << " Bulan" << endl;
        cout << "Berat Pet \t: " << current->beratPet << " Kg" << endl;
        cout << "Harga Pet \t: Rp. " << fixed << setprecision(2) << current->hargaPet << endl;
        cout << "====================================" << endl;
    }
}

int editPet(pet *head)
{
    cout << "           == Edit Pet ==" << endl;
    cout << "====================================" << endl;
    if (head == NULL)
    {
        cout << "Data Pet masih kosong" << endl;
        return -2;
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
    int pilihanHapus;

    while (true)
    {
        cout << "           PILIH OPSI HAPUS DATA : " << endl;
        cout << "===========================================" << endl;
        cout << "1. Menhapus Data Teratas  (Pop)     <Stack>" << endl;
        cout << "2. Menghapus Data Pertama (Dequeue) <Queue>" << endl;
        cout << "3. Hapus Pet Berdasarkan ID" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "===========================================" << endl;
        pilihanHapus = getIntInput("OPSI ANDA : ");
        system("cls || clear");

        if (pilihanHapus >= 1 && pilihanHapus <= 3)
            break;
        else if (pilihanHapus == 4)
        {
            return -2;
        }
        else
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }

    if (*head == NULL)
    {
        cout << "Data Pet masih kosong" << endl;
        return -1;
    }

    pet *temp = *head;
    pet *prev = NULL;

    if (pilihanHapus == 1)
    {
        *head = (*head)->next;
        delete temp;
        cout << "Pet berhasil dihapus (Mode Stack - Pop)." << endl;
        return 1;
    }
    else if (pilihanHapus == 2)
    {
        *head = (*head)->next; // Disini sama kea pop karean enqueue menambah data di akhir dan dequeue menghapus data di awal (FIFO)
        // Sehingga ini sama dengan pop namun dalam segi konsep implementasi queue ini benar sesuai modul.
        delete temp;
        cout << "Pet berhasil dihapus (Mode Queue - Dequeue)." << endl;
        return 1;
    }
    else if (pilihanHapus == 3)
    {
        int idPet = getIntInput("Masukkan ID Pet yang ingin dihapus : ");
        while (temp != NULL && temp->idPet != idPet)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "ID Pet tidak ditemukan." << endl;
            return -1;
        }

        if (prev == NULL)
        {
            *head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Pet berhasil dihapus berdasarkan ID." << endl;
        return 1;
    }

    return -1;
}

void splitList(pet *head, pet **left, pet **right)
{
    pet *slow = head;
    pet *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

pet *mergeListAsc(pet *left, pet *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    pet *result = NULL;

    if (left->hargaPet <= right->hargaPet)
    {
        result = left;
        result->next = mergeListAsc(left->next, right);
    }
    else
    {
        result = right;
        result->next = mergeListAsc(left, right->next);
    }

    return result;
}

void mergeSortAsc(pet **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    pet *left = NULL;
    pet *right = NULL;

    splitList(*head, &left, &right);

    mergeSortAsc(&left);
    mergeSortAsc(&right);

    *head = mergeListAsc(left, right);
}

void shellSortDesc(pet **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    int n = 0;
    pet *current = *head;
    while (current != NULL)
    {
        n++;
        current = current->next;
    }

    pet **array = new pet *[n];
    current = *head;
    for (int i = 0; i < n; i++)
    {
        array[i] = current;
        current = current->next;
    }

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            pet *temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap]->hargaPet < temp->hargaPet; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        array[i]->next = array[i + 1];
    }
    array[n - 1]->next = NULL;
    *head = array[0];

    delete[] array;
}