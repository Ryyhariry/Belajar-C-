#include <iostream>
#include <string>

using namespace std;

class Buku {
private:
    int id;
    string judul;
    string penulis;

public:
    Buku() {
        id = 0;
        judul = "";
        penulis = "";
    }

    Buku(int id, string judul, string penulis) {
        this->id = id;
        this->judul = judul;
        this->penulis = penulis;
    }

    int getId() {
        return id;
    }

    void tampilkanInfo() {
        cout << "ID: " << id << ", Judul: " << judul << ", Penulis: " << penulis << endl;
    }
};

class DaftarBuku {
private:
    int jumlahBuku;
    Buku koleksi[100];

public:
    DaftarBuku() {
        jumlahBuku = 0;
    }

    void tambahBuku(Buku buku) {
        if (jumlahBuku < 100) {
            koleksi[jumlahBuku] = buku;
            jumlahBuku++;
            cout << "Buku berhasil ditambahkan." << endl;
        } else {
            cout << "Daftar buku sudah penuh." << endl;
        }
    }

    void hapusBuku(int id) {
        bool ditemukan = false;
        for (int i = 0; i < jumlahBuku; i++) {
            if (koleksi[i].getId() == id) {
                ditemukan = true;
                for (int j = i; j < jumlahBuku - 1; j++) {
                    koleksi[j] = koleksi[j + 1];
                }
                jumlahBuku--;
                cout << "Buku berhasil dihapus." << endl;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
        }
    }

    void tampilkanSemuaBuku() {
        if (jumlahBuku == 0) {
            cout << "Tidak ada buku dalam daftar." << endl;
        } else {
            for (int i = 0; i < jumlahBuku; i++) {
                koleksi[i].tampilkanInfo();
            }
        }
    }

    void cariBuku(int id) {
        bool ditemukan = false;
        for (int i = 0; i < jumlahBuku; i++) {
            if (koleksi[i].getId() == id) {
                cout << "Buku ditemukan: ";
                koleksi[i].tampilkanInfo();
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Buku dengan ID " << id << " tidak ditemukan." << endl;
        }
    }
};

int main() {
    DaftarBuku daftar;
    int pilihan;
    do {
        cout << "Aplikasi Buku Perpustakaan \n";
		cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Hapus Buku\n";
        cout << "3. Tampilkan Semua Buku\n";
        cout << "4. Cari Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            int id;
            string judul, penulis;
            cout << "Masukkan ID buku: ";
            cin >> id;
            cin.ignore();
            cout << "Masukkan judul buku: ";
            getline(cin, judul);
            cout << "Masukkan penulis buku: ";
            getline(cin, penulis);
            Buku buku(id, judul, penulis);
            daftar.tambahBuku(buku);
        } else if (pilihan == 2) {
            int id;
            cout << "Masukkan ID buku yang akan dihapus: ";
            cin >> id;
            daftar.hapusBuku(id);
        } else if (pilihan == 3) {
            daftar.tampilkanSemuaBuku();
        } else if (pilihan == 4) {
            int id;
            cout << "Masukkan ID buku yang dicari: ";
            cin >> id;
            daftar.cariBuku(id);
        }
    } while (pilihan != 5);

    cout << "Terima kasih telah menggunakan program ini." << endl;

    return 0;
}

