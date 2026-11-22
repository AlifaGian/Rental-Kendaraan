#include "rental.h"
#include <limits>

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ListParent L;
    createList(L);

    insertParent(L, createParent("K01", "Mobil MPV"));
    insertParent(L, createParent("K02", "Motor Matic"));
    insertParent(L, createParent("K03", "Mobil SUV"));

    int pilihan;
    do {
        cout << " \n";
        cout << " ========== RENTAL KENDARAAN ========== \n";
        cout << "1. Tampilkan Kategori\n";
        cout << "2. Tambah Kategori \n";
        cout << "3. Cari Kategori \n";
        cout << "4. Hapus Kategori \n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";

        if (!(cin >> pilihan)) {
            cout << "Input harus berupa angka.\n";
            clearInput();
            continue;
        }
        clearInput();

        string idKat, namaKat;

        switch (pilihan) {
            case 1:
                printParent(L);
                break;

            case 2:
                cout << "Masukkan ID Kategori (cth: K04) : ";
                getline(cin, idKat);
                cout << "Masukkan Nama Kategori          : ";
                getline(cin, namaKat);
                insertParent(L, createParent(idKat, namaKat));
                break;

            case 3: {
                cout << "Masukkan ID Kategori yang dicari: ";
                getline(cin, idKat);
                ElmParent* P = findParent(L, idKat);
                if (P != nullptr) {
                    cout << "Ditemukan: [" << P->info.idKategori << "] " << P->info.namaKategori << "\n";
                    cout << " ";
                } else {
                    cout << "Kategori tidak ditemukan.\n";
                    cout << " ";
                }
                break;
            }

            case 4:
                cout << "Masukkan ID Kategori yang akan dihapus: ";
                getline(cin, idKat);
                deleteParent(L, idKat);
                break;

            case 0:
                cout << "Program selesai.\n";
                cout << " ";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                cout << " ";
        }
    } while (pilihan != 0);

    return 0;
}