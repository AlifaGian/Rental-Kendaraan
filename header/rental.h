#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
#include <string>
using namespace std;

#define NIL NULL

typedef struct ElmParent *adrParent;
typedef struct ElmChild *adrChild;

struct Kendaraan {
    string platNomor;
    string namaKendaraan;
    int tahun;
    int hargaSewa;
    bool tersedia;
};

struct ElmChild {
    Kendaraan info;
    adrChild next;
};

struct Kategori {
    string idKategori;
    string namaKategori;
};

struct ElmParent {
    Kategori info;
    adrParent next;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
};

void createList(ListParent &L);
adrParent createParent(string idKategori, string namaKategori);
void insertParent(ListParent &L, adrParent P);
adrParent findParent(ListParent L, string idKategori);
void deleteParent(ListParent &L, string idKategori);
void printParent(ListParent L);

#endif