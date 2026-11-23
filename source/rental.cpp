#include "../header/rental.h"

void createList(ListParent &L) {
    L.first = NIL;
}

adrParent createParent(string idKategori, string namaKategori) {
    adrParent P = new ElmParent;
    P->info.idKategori = idKategori;
    P->info.namaKategori = namaKategori;
    P->next = NIL;
    P->firstChild = NIL;
    return P;
}

void insertParent(ListParent &L, adrParent P) {
    if (findParent(L, P->info.idKategori) != NIL) {
        cout << "[!] Gagal: ID Kategori '" << P->info.idKategori << "' sudah ada.\n";
        delete P;
        return;
    }

    if (L.first == NIL) {
        L.first = P;
    } else {
        adrParent Q = L.first;
        while (Q->next != NIL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrParent findParent(ListParent L, string idKategori) {
    adrParent P = L.first;
    while (P != NIL) {
        if (P->info.idKategori == idKategori) {
            return P;
        }
        P = P->next;
    }
    return NIL;
}

void deleteParent(ListParent &L, string idKategori) {
    if (L.first == NIL) {
        cout << "[!] List kategori masih kosong.\n";
        return;
    }

    adrParent P = L.first;
    adrParent prev = NIL;

    while (P != NIL && P->info.idKategori != idKategori) {
        prev = P;
        P = P->next;
    }

    if (P == NIL) {
        cout << "[!] Kategori dengan ID '" << idKategori << "' tidak ditemukan.\n";
        return;
    }

    if (prev == NIL) {
        L.first = P->next;
    } else {
        prev->next = P->next;
    }

    cout << "[v] Kategori '" << P->info.namaKategori << "' berhasil dihapus.\n";
    delete P;
}

void printParent(ListParent L) {
    if (L.first == NIL) {
        cout << "[!] Belum ada kategori kendaraan.\n";
        return;
    }

    cout << "\n=== DAFTAR KATEGORI KENDARAAN (PARENT) ===\n";
    adrParent P = L.first;
    int i = 1;
    while (P != NIL) {
        cout << i++ << ". [" << P->info.idKategori << "] " << P->info.namaKategori << "\n";
        P = P->next;
    }
}