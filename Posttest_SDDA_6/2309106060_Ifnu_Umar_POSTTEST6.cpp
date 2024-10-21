#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <vector>
#include <unordered_set>
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
void display(pet *head);
bool compareByHargaDescending(pet *a, pet *b);
bool compareByBeratDescending(pet *a, pet *b);
bool compareByUmurDescending(pet *a, pet *b);
void shellSort(pet **headRef, bool (*compare)(pet *, pet *));
int getLength(pet *head);
pet *getNodeAt(pet *head, int index);
void mergeSort(pet **headRef, bool (*compare)(pet *, pet *));
void mergeSortedLists(pet *list1, pet *list2, pet **headRef, bool (*compare)(pet *, pet *));
void splitList(pet *source, pet **front, pet **back);
bool compareByHarga(pet *a, pet *b);
bool compareByBerat(pet *a, pet *b);
bool compareByUmur(pet *a, pet *b);
void fibonacciSearchExact(pet *head, float keyHarga);
void jumpSearchByUmur(pet *head, int keyUmur);
void boyerMooreSearch(pet *head, string pattern);
void preprocessBadChar(string pattern, vector<int> &badChar);

int main()
{
    pet *linkedListPet = NULL;
    int status;
    int pilihan;
    float keyHarga;
    int keyUmur;
    string pattern;
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
        cout << "\t7. Search Fibonacci (Harga Pet)" << endl;
        cout << "\t8. Search Jump (Umur Pet)" << endl;
        cout << "\t9. Search Boyer-Moore (Nama Pet)" << endl;
        cout << "\t10. Keluar" << endl;
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
            mergeSort(&linkedListPet, compareByHarga);
            display(linkedListPet);
            cout << "Data Pet berhasil diurutkan secara Ascending menggunakan Merge Sort" << endl;
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 6:
            shellSort(&linkedListPet, compareByHargaDescending);
            display(linkedListPet);
            cout << "Data Pet berhasil diurutkan secara Descending menggunakan Shell Sort" << endl;
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 7:
            cout << " == PROGRAM SEARCH FIBONACCI HARGA PET ==" << endl;
            cout << "=========================================" << endl;
            mergeSort(&linkedListPet, compareByHarga);
            keyHarga = getFloatInput("Masukkan harga pet yang ingin dicari : ");
            fibonacciSearchExact(linkedListPet, keyHarga);
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 8:
            cout << " == PROGRAM SEARCH JUMP UMUR PET ==" << endl;
            cout << "=========================================" << endl;
            mergeSort(&linkedListPet, compareByUmur);
            keyUmur = getIntInput("Masukkan umur pet yang ingin dicari : ");
            jumpSearchByUmur(linkedListPet, keyUmur);
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 9:
            cout << " == PROGRAM SEARCH BOYER-MOORE NAMA PET ==" << endl;
            cout << "=========================================" << endl;
            pattern = getStringInput("Masukkan nama pet yang ingin dicari : ");
            boyerMooreSearch(linkedListPet, pattern);
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 10:
            cout << " == PROGRAM MANAGEMENT PETS SHOP BERAKHIR == " << endl;
            return 0;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (pilihan != 10);
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

int getLength(pet *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}

pet *getNodeAt(pet *head, int index)
{
    int counter = 0;
    pet *current = head;
    while (current != nullptr && counter < index)
    {
        current = current->next;
        counter++;
    }
    return current;
}

void shellSort(pet **headRef, bool (*compare)(pet *, pet *))
{
    int n = getLength(*headRef);

    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i++)
        {

            pet *temp = getNodeAt(*headRef, i);
            pet *current = getNodeAt(*headRef, i - gap);

            int j = i;
            while (j >= gap && compare(current, temp))
            {
                pet *nextCurrent = getNodeAt(*headRef, j - gap);

                swap(getNodeAt(*headRef, j)->idPet, current->idPet);
                swap(getNodeAt(*headRef, j)->namaPet, current->namaPet);
                swap(getNodeAt(*headRef, j)->jenisPet, current->jenisPet);
                swap(getNodeAt(*headRef, j)->umurPet, current->umurPet);
                swap(getNodeAt(*headRef, j)->beratPet, current->beratPet);
                swap(getNodeAt(*headRef, j)->hargaPet, current->hargaPet);

                j -= gap;
                if (j >= gap)
                    current = nextCurrent;
            }
        }
    }
}

bool compareByHargaDescending(pet *a, pet *b)
{
    return a->hargaPet < b->hargaPet;
}

bool compareByBeratDescending(pet *a, pet *b)
{
    return a->beratPet < b->beratPet;
}

bool compareByUmurDescending(pet *a, pet *b)
{
    return a->umurPet < b->umurPet;
}

void splitList(pet *source, pet **front, pet **back)
{
    pet *slow;
    pet *fast;

    slow = source;
    fast = source->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

pet *mergeSortedLists(pet *list1, pet *list2, bool (*compare)(pet *, pet *))
{
    pet *result = nullptr;

    if (list1 == nullptr)
        return list2;
    else if (list2 == nullptr)
        return list1;

    if (compare(list1, list2))
    {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2, compare);
    }
    else
    {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next, compare);
    }

    return result;
}

void mergeSort(pet **headRef, bool (*compare)(pet *, pet *))
{
    pet *head = *headRef;
    pet *list1;
    pet *list2;

    if ((head == nullptr) || (head->next == nullptr))
    {
        return;
    }

    splitList(head, &list1, &list2);

    mergeSort(&list1, compare);
    mergeSort(&list2, compare);

    *headRef = mergeSortedLists(list1, list2, compare);
}

bool compareByHarga(pet *a, pet *b)
{
    return a->hargaPet <= b->hargaPet;
}

bool compareByBerat(pet *a, pet *b)
{
    return a->beratPet <= b->beratPet;
}

bool compareByUmur(pet *a, pet *b)
{
    return a->umurPet <= b->umurPet;
}

void fibonacciSearchExact(pet *head, float keyHarga)
{
    int n = getLength(head);

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);
        pet *current = getNodeAt(head, i);

        if (current->hargaPet < keyHarga)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (current->hargaPet > keyHarga)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            cout << "\nPet dengan harga " << keyHarga << " ditemukan:" << endl;

            pet *foundPet = current;
            cout << "ID: " << foundPet->idPet
                 << ", Nama: " << foundPet->namaPet
                 << ", Jenis: " << foundPet->jenisPet
                 << ", Umur: " << foundPet->umurPet
                 << ", Berat: " << foundPet->beratPet
                 << ", Harga: " << foundPet->hargaPet << endl;

            int backwardIndex = i - 1;
            while (backwardIndex >= 0)
            {
                pet *previousPet = getNodeAt(head, backwardIndex);
                if (previousPet->hargaPet == keyHarga)
                {
                    cout << "ID: " << previousPet->idPet
                         << ", Nama: " << previousPet->namaPet
                         << ", Jenis: " << previousPet->jenisPet
                         << ", Umur: " << previousPet->umurPet
                         << ", Berat: " << previousPet->beratPet
                         << ", Harga: " << previousPet->hargaPet << endl;
                }
                else
                {
                    break;
                }
                backwardIndex--;
            }

            int forwardIndex = i + 1;
            while (forwardIndex < n)
            {
                pet *nextPet = getNodeAt(head, forwardIndex);
                if (nextPet->hargaPet == keyHarga)
                {
                    cout << "ID: " << nextPet->idPet
                         << ", Nama: " << nextPet->namaPet
                         << ", Jenis: " << nextPet->jenisPet
                         << ", Umur: " << nextPet->umurPet
                         << ", Berat: " << nextPet->beratPet
                         << ", Harga: " << nextPet->hargaPet << endl;
                }
                else
                {
                    break;
                }
                forwardIndex++;
            }

            return;
        }
    }

    if (fibMMm1 && getNodeAt(head, offset + 1)->hargaPet == keyHarga)
    {
        pet *lastPet = getNodeAt(head, offset + 1);
        cout << "\nPet dengan harga " << keyHarga << " ditemukan:" << endl;
        cout << "ID: " << lastPet->idPet
             << ", Nama: " << lastPet->namaPet
             << ", Jenis: " << lastPet->jenisPet
             << ", Umur: " << lastPet->umurPet
             << ", Berat: " << lastPet->beratPet
             << ", Harga: " << lastPet->hargaPet << endl;
    }
    else
    {
        cout << "\nPet dengan harga " << keyHarga << " tidak ditemukan." << endl;
    }
}

void jumpSearchByUmur(pet *head, int keyUmur)
{
    if (head == nullptr)
    {
        cout << "Linked List kosong." << endl;
        return;
    }

    // Hitung panjang linked list
    int n = getLength(head);
    int jump = sqrt(n); // Ukuran langkah
    int prev = 0;

    pet *current = head;
    int i = 0;
    unordered_set<int> foundIDs; // Set untuk menyimpan ID yang sudah ditemukan

    while (current != nullptr && current->umurPet < keyUmur)
    {
        prev = i;
        for (int j = 0; j < jump && current != nullptr; j++)
        {
            current = current->next;
            i++;
        }
    }

    if (prev < n && getNodeAt(head, prev)->umurPet == keyUmur)
    {
        pet *foundPet = getNodeAt(head, prev);
        if (foundIDs.find(foundPet->idPet) == foundIDs.end())
        {
            cout << "Pet dengan umur " << keyUmur << " ditemukan:" << endl;
            foundIDs.insert(foundPet->idPet);
            cout << "ID: " << foundPet->idPet
                 << ", Nama: " << foundPet->namaPet
                 << ", Jenis: " << foundPet->jenisPet
                 << ", Umur: " << foundPet->umurPet
                 << ", Berat: " << foundPet->beratPet
                 << ", Harga: " << foundPet->hargaPet << endl;
            cout << "====================================" << endl;
        }
    }

    if (current != nullptr && current->umurPet == keyUmur)
    {
        while (current != nullptr && current->umurPet == keyUmur)
        {
            if (foundIDs.find(current->idPet) == foundIDs.end())
            {
                cout << "Pet dengan umur " << keyUmur << " ditemukan:" << endl;
                foundIDs.insert(current->idPet);
                cout << "ID: " << current->idPet
                     << ", Nama: " << current->namaPet
                     << ", Jenis: " << current->jenisPet
                     << ", Umur: " << current->umurPet
                     << ", Berat: " << current->beratPet
                     << ", Harga: " << current->hargaPet << endl;
                cout << "====================================" << endl;
            }
            current = current->next;
        }
    }
    else
    {
        cout << "Pet dengan umur " << keyUmur << " tidak ditemukan." << endl;
    }
}

void preprocessBadChar(string pattern, vector<int> &badChar)
{
    int m = pattern.size();
    for (int i = 0; i < 256; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        badChar[(int)pattern[i]] = i;
    }
}

void boyerMooreSearch(pet *head, string pattern)
{
    vector<int> badChar(256);
    preprocessBadChar(pattern, badChar);

    pet *current = head;
    int id = 0;

    while (current != nullptr)
    {
        string name = current->namaPet;
        int n = name.size();
        int m = pattern.size();

        int s = 0;
        while (s <= (n - m))
        {
            int j = m - 1;

            while (j >= 0 && pattern[j] == name[s + j])
            {
                j--;
            }

            if (j < 0)
            {
                cout << "Pet dengan nama \"" << pattern << "\" ditemukan:" << endl;
                cout << "ID: " << current->idPet
                     << ", Nama: " << current->namaPet
                     << ", Jenis: " << current->jenisPet
                     << ", Umur: " << current->umurPet
                     << ", Berat: " << current->beratPet
                     << ", Harga: " << current->hargaPet << endl;

                s += (s + m < n) ? m - badChar[name[s + m]] : 1;
            }
            else
            {
                s += max(1, j - badChar[name[s + j]]);
            }
        }

        current = current->next;
        id++;
    }
}