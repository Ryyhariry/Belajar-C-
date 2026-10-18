#include <iostream>
#include <stack>
#include <string>
#include <limits> // Untuk numeric_limits

using namespace std;

// Fungsi untuk menampilkan menu dan mendapatkan pilihan pengguna
int displayMenu() {
    int choice;
    cout << "\n====================================\n";
    cout << "   PROGRAM MANAJEMEN BUKU (STACK)  \n";
    cout << "====================================\n";
    cout << "1. PUSH (Tambah Buku)\n";
    cout << "2. POP (Hapus Buku Terakhir Masuk)\n";
    cout << "3. TOP (Tampilkan Buku Teratas)\n";
    cout << "4. DISPLAY (Tampilkan Seluruh Isi Stack)\n"; // Mengganti DISPLAY menjadi tampilan semua elemen
    cout << "0. Keluar\n";
    cout << "Masukkan Pilihan Anda: ";
    cin >> choice;
    return choice;
}

// Fungsi untuk menampilkan seluruh isi stack (dengan membuat copy)
void displayStack(stack<string> s) {
    if (s.empty()) {
        cout << "\n Stack Kosong. Tidak ada buku untuk ditampilkan.\n";
        return;
    }

    cout << "\n Isi Stack Buku (dari ATAS ke BAWAH):\n";
    cout << "------------------------------------\n";
    // Iterasi dan Pop elemen dari stack copy
    int count = 1;
    while (!s.empty()) {
        if (count == 1) {
            cout << "**[TOP]** " << s.top() << "  (Buku Terakhir Masuk)\n";
        } else {
            cout << "  [" << count << "] " << s.top() << "\n";
        }
        s.pop();
        count++;
    }
    cout << "------------------------------------\n";
}

int main() {
    stack<string> bookStack;
    int choice;
    string bookTitle;

    do {
        choice = displayMenu();

        // Mengabaikan input yang tersisa (termasuk newline) sebelum getline
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Ulangi loop
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
            case 1: // PUSH
                cout << "\n-- PUSH (Tambah Buku) --\n";
                cout << "Masukkan Judul Buku: ";
                getline(cin, bookTitle);
                bookStack.push(bookTitle);
                cout << " Buku '" << bookTitle << "' berhasil ditambahkan (PUSH).\n";
                break;

            case 2: // POP
                cout << "\n-- POP (Hapus Buku) --\n";
                if (bookStack.empty()) {
                    cout << " Stack Kosong. Tidak ada buku untuk dihapus.\n";
                } else {
                    bookTitle = bookStack.top();
                    bookStack.pop();
                    cout << " Buku '" << bookTitle << "' berhasil dihapus (POP) dari ATAS stack.\n";
                }
                break;

            case 3: // TOP
                cout << "\n-- TOP (Lihat Buku Teratas) --\n";
                if (bookStack.empty()) {
                    cout << " Stack Kosong. Tidak ada buku teratas.\n";
                } else {
                    cout << " Buku Teratas Saat Ini Adalah: **" << bookStack.top() << "**\n";
                }
                break;

            case 4: // DISPLAY
                displayStack(bookStack);
                break;

            case 0: // Keluar
                cout << "\nTerima kasih! Program selesai.\n";
                break;

            default:
                cout << "\n Pilihan tidak valid. Silakan masukkan angka dari 0 sampai 4.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}