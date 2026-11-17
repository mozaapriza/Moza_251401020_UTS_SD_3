#include <iostream>
#include <string>
using namespace std;

struct Node {
    int noAntrean;
    string namaPelanggan;
    Node* next;
};

Node* front = nullptr; 
Node* rear = nullptr;  

void enqueue(int nomor, string nama) {
    Node* baru = new Node();
    baru->noAntrean = nomor;
    baru->namaPelanggan = nama;
    baru->next = nullptr;

    if (front == nullptr) {
        front = baru;
        rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Pelanggan [" << nomor << " - " << nama << "] masuk ke antrean.\n";
}

void dequeue() {
    if (front == nullptr) {
        cout << "Antrean kosong, tidak ada pelanggan.\n";
        return;
    }

    Node* hapus = front; 
    cout << "Melayani pelanggan: No. " << front->noAntrean << " (" << front->namaPelanggan << ")\n";
    
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete hapus; 
}

void tampilkanAntrean() {
    if (front == nullptr) {
        cout << "Daftar tunggu kosong.\n";
        return;
    }

    cout << "Daftar antrean pelanggan: \n";
    Node* temp = front;
    while (temp != nullptr) {
        cout << "No. " << temp->noAntrean << " | Nama: " << temp->namaPelanggan << endl;
        temp = temp->next;
    }
    cout << "------------------------------\n";

}

int main() {
    int n, nomor;
    string nama;

    cout << "Masukkan jumlah pelanggan yang mengantre: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nPelanggan ke-" << i + 1 << endl;
        cout << "Nomor Antrean : ";
        cin >> nomor;
        cin.ignore(); 
        cout << "Nama Pelanggan   : ";
        getline(cin, nama); 
        enqueue(nomor, nama);
    }

    tampilkanAntrean();

    cout << "\n memanggil 1 pelanggan pertama:\n";
    dequeue();

    tampilkanAntrean();

    return 0;
}