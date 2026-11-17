#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int n;
    int nilai;
    int target;

    Node* head = nullptr;
    Node* tail = nullptr;
   
    cout<< "Masukkan jumlah data: ";
    cin>>n;

    for (int i=1; i<=n; i++){
        cout<<"Masukkan data ke-"<<i<<": ";
        cin>> nilai;

        Node* baru = new Node();
        baru->data = nilai;
        baru->next = nullptr;

        if (head == nullptr) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru; 
        }
    }

    cout<<"\nHasil Linked List:\n";
    Node* temp = head;
    while (temp!= nullptr ){
        cout<< temp ->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    cout<<"\nReverse Hasil Linked List:\n";
    temp = tail;
    while (temp!= nullptr ){
        cout<< temp ->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

    cout << "Cari bilangan: ";
    cin>> target;

    temp = head;
    int posisi = 1;
    bool ditemukan = false;

        while (temp != nullptr) {
            if (temp->data == target) {
                cout << "Data Ditemukan pada urutan ke-" << posisi << "!\n";
                ditemukan = true;
                break;
            }
            temp = temp->next;
            posisi++;
        }

        if (!ditemukan) {
            cout << "Data dengan bilangan" << target << " tidak ditemukan.\n";
        }
    }
    
