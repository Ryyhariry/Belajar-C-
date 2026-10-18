#include "player.h"
#include <iostream>
using namespace std;

int main(){


    player mysquad[5];

    for(int i=0;i<5;i++){
        string a; int b;
        cout << "Tambah data ke " << i+1 << endl;
        cout << "Nama Player : "; cin >> a;
        cout << "No punggung : "; cin >> b;
        mysquad[i].tambahData(a,b);
    }
    cout << "================================" << endl;
    cout << "nama \t nomer" << endl;
    for(int i=0; i<5; i++){
        cout << mysquad[i].getNama() << "\t" << mysquad [i].getNomer() << endl;
    }
}