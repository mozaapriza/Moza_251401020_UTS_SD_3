#include <iostream>
using namespace std;

struct Node {
    int angka;
    Node* left;
    Node* right;
};

Node* createNode(int nilai) {
    Node* baru = new Node();
    baru->angka = nilai;
    baru->left = nullptr;
    baru->right = nullptr;
    return baru;
}

Node* insert(Node* root, int nilai) {
    if (root == nullptr) {
        return createNode(nilai);
    }
    if (nilai < root->angka) {
        root->left = insert(root->left, nilai);
    } else if (nilai > root->angka) {
        root->right = insert(root->right, nilai);
    }
    return root;
}

bool search(Node* root, int target) {
    if (root == nullptr) return false;
    if (root->angka == target) return true;
    
    if (target < root->angka) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->angka << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, inputAngka, cariAngka;

    cout << "Masukkan jumlah angka: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "angka ke-" << i + 1 << ": ";
        cin >> inputAngka;
        root = insert(root, inputAngka);
    }

    cout << "\nIn-Order   : "; inorder(root);
    cout << endl;

    cout << "\nMasukkan angka yang ingin dicari: ";
    cin >> cariAngka;
    if (search(root, cariAngka)) {
        cout << "angka " << cariAngka << " ditemukan " << endl;
    } else {
        cout << "angka " << cariAngka << " tidak ditemukan " << endl;
    }

    return 0;
}

