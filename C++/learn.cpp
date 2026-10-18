#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Masukkan angka yang ingin dicari: ";
    cin >> key;
    int result = binarySearch(arr, size, key);
    if (result != -1)
        cout << "Elemen ditemukan pada indeks ke-" << result << endl;
    else
        cout << "Elemen tidak ditemukan." << endl;

    return 0;
}