#include <iostream>
#include <iterator>
#include <list>
using namespace std;


//fungsi menampilkan list
void tampilkanList(list<int> g){
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
    cout << '\t' << *it;
    cout << '\n';
}

//driver code
int main()
{
    list <int> list1, list2;

    for (int i = 0; i < 10; ++i) {
        list1.push_back(i);
        list2.push_front(i);
    }
    cout << "\n manampilkan list 1 : ";
    tampilkanList(list1);

    cout << "\n menampilkan list 2 : ";
    tampilkanList(list2);

    cout << "\n elemen paling depan list 1 : " << list1.front();
    cout << "\n elemen paling belakang list 2 : " << list2.back();

    cout << "\n buang elemen terdepan dari list 1 : ";
    list1.pop_front();
    tampilkanList(list1);

    cout << "\n buang elemen ternelakang dari list 2 : ";
    list2.pop_back();
    tampilkanList(list2);

    cout << "menambahkan data data terdepan list 1 : ";
    list1.push_front(7);
    tampilkanList(list1);

    cout << "menambahkan data data belakang list 1 : ";
    list1.push_back(87);
    tampilkanList(list1);

    cout << "mengurutkan data list 1 : ";
    list1.sort();
    tampilkanList(list1);

    cout << "mengembalikan urutan data list 1 : ";
    list1.reverse();
    tampilkanList(list1);

    list1.clear();
    cout << "data list 1 : ", tampilkanList(list1);

    return 0;
}