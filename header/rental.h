#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string platNomor;
    string namaKendaraan;
    int tahun;
    int hargaSewa;
    bool tersedia;
};

struct ElmChild {
    Kendaraan info;
    ElmChild* next;
};

// Parent
struct Kategori {
    string idKategori;
    string namaKategori;
};

struct ElmParent {
    Kategori info;
    ElmParent* next;
    ElmChild* nextChild;
};

struct ListParent {
    ElmParent* first;
};

void createList(ListParent &L);
ElmParent* createParent(string idKategori, string namaKategori);
void insertParent(ListParent &L, ElmParent* P);
ElmParent* findParent(ListParent L, string idKategori);
void deleteParent(ListParent &L, string idKategori);
void printParent(ListParent L);

#endif