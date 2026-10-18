#include <iostream>
#include <stack> // Pustaka untuk menggunakan std::stack
#include <string>

int main() {
    // 1. Deklarasi Stack
    // Membuat sebuah stack bernama 'tumpukan' yang menyimpan data tipe integer
    std::stack<int> tumpukan;
    
    std::cout << "=== Operasi Stack Menggunakan STL ===" << std::endl;

    // 2. Operasi PUSH (Menambahkan Elemen)
    // Menambahkan elemen ke puncak (Top) stack
    tumpukan.push(10);
    tumpukan.push(20);
    tumpukan.push(30);
    std::cout << "Setelah Push 10, 20, 30. Ukuran stack: " << tumpukan.size() << std::endl;

    // 3. Operasi TOP (Melihat Elemen Puncak)
    // Melihat elemen teratas (Last In) tanpa menghapusnya
    std::cout << "Elemen teratas (Top): " << tumpukan.top() << std::endl; // Output: 30

    // 4. Operasi POP (Menghapus Elemen)
    // Menghapus elemen dari puncak (Last In, First Out - LIFO)
    tumpukan.pop(); 
    std::cout << "Setelah Pop. Ukuran stack sekarang: " << tumpukan.size() << std::endl;

    // Lihat elemen teratas setelah Pop
    std::cout << "Elemen teratas baru: " << tumpukan.top() << std::endl; // Output: 20

    // 5. Cek KOSONG (Empty)
    if (tumpukan.empty()) {
        std::cout << "Stack kosong." << std::endl;
    } else {
        std::cout << "Stack tidak kosong." << std::endl;
    }

    return 0;
}