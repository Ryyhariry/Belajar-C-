#include <iostream>
#include <string>
using namespace std;

// Kelas Buku: Representasi objek buku
class Buku {
public:
    int id;
    string judul;
    string penulis;

    // Konstruktor default
    Buku() {
        id = 0;
        judul = "";
        penulis = "";
    }

    // Konstruktor dengan parameter
    Buku(int id, string judul, string penulis) {
        this->id = id;
        this->judul = judul;
        this->penulis = penulis;
    }
};

// Kelas DaftarBuku: Menyimpan koleksi buku
class DaftarBuku {
private:
    int jumlahBuku;
    Buku koleksi[100]; // Maksimal 100 buku

public:
    // Konstruktor default
    DaftarBuku() {
        jumlahBuku = 0;
    }

    // Menambah buku ke daftar
    void tambahBuku(Buku buku) {
        if (jumlahBuku < 100) {
            koleksi[jumlahBuku] = buku;
            jumlahBuku++;
            cout << "Buku '" << buku.judul << "' berhasil ditambahkan!" << endl;
        } else {
            cout << "Daftar buku penuh, tidak dapat menambah lebih banyak buku!" << endl;
        }
    }

    // Menghapus buku berdasarkan ID
    void hapusBuku(int id) {
        bool found = false;
        for (int i = 0; i < jumlahBuku; i++) {
            if (koleksi[i].id == id) {
                found = true;
                for (int j = i; j < jumlahBuku - 1; j++) {
                    koleksi[j] = koleksi[j + 1];
                }
                jumlahBuku--;
                cout << "Buku dengan ID " << id << " berhasil dihapus!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Buku dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }

    // Menampilkan seluruh buku
    void tampilkanBuku() {
        if (jumlahBuku == 0) {
            cout << "Tidak ada buku dalam perpustakaan!" << endl;
        } else {
            cout << "Daftar Buku di Perpustakaan:" << endl;
            for (int i = 0; i < jumlahBuku; i++) {
                cout << "ID: " << koleksi[i].id
                     << ", Judul: " << koleksi[i].judul
                     << ", Penulis: " << koleksi[i].penulis
                     << endl;
            }
        }
    }

    // Mencari buku berdasarkan ID
    void cariBuku(int id) {
        bool found = false;
        for (int i = 0; i < jumlahBuku; i++) {
            if (koleksi[i].id == id) {
                cout << "Buku ditemukan!" << endl;
                cout << "ID: " << koleksi[i].id
                     << ", Judul: " << koleksi[i].judul
                     << ", Penulis: " << koleksi[i].penulis
                     << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Buku dengan ID " << id << " tidak ditemukan!" << endl;
        }
    }
};

// Fungsi utama
int main() {
    DaftarBuku perpustakaan;
    int pilihan, id;
    string judul, penulis;

    do {
        cout << "\nAplikasi Manajemen Buku Perpustakaan" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Tampilkan Semua Buku" << endl;
        cout << "4. Cari Buku Berdasarkan ID" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan ID Buku: ";
            cin >> id;
            cin.ignore(); // Mengabaikan newline
            cout << "Masukkan Judul Buku: ";
            getline(cin, judul);
            cout << "Masukkan Nama Penulis: ";
            getline(cin, penulis);
            perpustakaan.tambahBuku(Buku(id, judul, penulis));
            break;

        case 2:
            cout << "Masukkan ID Buku yang akan dihapus: ";
            cin >> id;
            perpustakaan.hapusBuku(id);
            break;

        case 3:
            perpustakaan.tampilkanBuku();
            break;

        case 4:
            cout << "Masukkan ID Buku yang dicari: ";
            cin >> id;
            perpustakaan.cariBuku(id);
            break;

        case 5:
            cout << "Keluar dari aplikasi." << endl;
            break;

        default:
            cout << "Opsi tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}