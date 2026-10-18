#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//definisi struct mahasiswa
struct Mahasiswa {
    string nama;
    int nilai;
};
//compalator descending
bool compareNilai(Mahasiswa a, Mahasiswa b) {
    return a.nilai > b.nilai; //dari tinggi ke rendah
}
int main(){
    //data mahasiswa
    vector<Mahasiswa> data;
    data.push_back(Mahasiswa{"Nanda", 90});
    data.push_back(Mahasiswa{"Bagus", 85});
    data.push_back(Mahasiswa{"Robert", 80});

sort(data.begin(), data.end(), compareNilai);

    for (size_t i = 0; i < data.size(); ++i){
        const Mahasiswa& m = data[i];
        cout << m.nama << ": " << m.nilai << endl;
    }
    return 0;
}