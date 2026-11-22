#include "rental.h"

void createList(ListParent &L) {
    L.first = nullptr;
}

ElmParent* createParent(string idKategori, string namaKategori) {
    ElmParent* P = new ElmParent;
    P->info.idKategori = idKategori;
    P->info.namaKategori = namaKategori;
    P->next = nullptr;
    P->nextChild = nullptr;
    return P;
}

void insertParent(ListParent &L, ElmParent* P) {
    if (findParent(L, P->info.idKategori) != nullptr) {
        cout << "[!] Gagal: ID Kategori '" << P->info.idKategori << "' sudah ada.\n";
        cout << " ";
        delete P;
        return;
    }

    if (L.first == nullptr) {
        L.first = P;
    } else {
        ElmParent* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

ElmParent* findParent(ListParent L, string idKategori) {
    ElmParent* P = L.first;
    while (P != nullptr) {
        if (P->info.idKategori == idKategori) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteParent(ListParent &L, string idKategori) {
    if (L.first == nullptr) {
        cout << "[!] List kategori masih kosong.\n";
        cout << " ";
        return;
    }

    ElmParent* P = L.first;
    ElmParent* prev = nullptr;

    while (P != nullptr && P->info.idKategori != idKategori) {
        prev = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Kategori dengan ID '" << idKategori << "' tidak ditemukan.\n";
        cout << " ";
        return;
    }

    if (prev == nullptr) {
        L.first = P->next;
    } else {
        prev->next = P->next;
    }

    cout << "Kategori '" << P->info.namaKategori << "' berhasil dihapus\n";
    cout << " ";
    delete P;
}

void printParent(ListParent L) {
    if (L.first == nullptr) {
        cout << "Belum ada kategori kendaraan\n";
        cout << " ";
        return;
    }

    cout << "\n=== DAFTAR KATEGORI KENDARAAN ===\n";
    ElmParent* P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << i++ << ". [" << P->info.idKategori << "] " << P->info.namaKategori << "\n";
        cout << " ";
        P = P->next;
    }
}