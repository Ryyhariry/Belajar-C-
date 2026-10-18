#include <iostream>
using namespace std;

// array antrian
int maksimalAntrianArray = 5, front = 0, back = 0;
// ruang antrian array
string antrianATM[5];
// isfull / cek data antrian penuh atau tidak
bool isFullArray(){
    if (back == maksimalAntrianArray){
        return true;
    }else{
        return false;
    }
}
// isEmpty
bool isEmptyArray(){
    if (back == 0){
        return true;
    }else{
        return false;
    }
}
// enqueue / penambahan data antrian
void enqueueArray(string data){
    if (isFullArray()){
        cout << "Antrian penuh !!" << endl;
    }else{
        //cek apakah datanya kosong atau tidak
        if (isEmptyArray()){
            //kalau antrian kosong
            antrianATM[0] = data;
            front++;
            back++;
        }else{
            // kalo gak kosong
            antrianATM[back] = data;
            back++;
        }
    }
}
// dequeue / penghapusan data depan
void dequeueArray(){
    if (isEmptyArray()){
        cout << "Antrian kosong!!" << endl;
    }else{
        for (int i = 0; i < back; i++){
            antrianATM[i] = antrianATM[i+1];
        }
        back--;
    }
}
// countArray / menghitung banyak data yang ngantri
int countArray(){
    if (isEmptyArray()){
        return 0;
    }else if(isFullArray()){
        return maksimalAntrianArray;
    }else{
        return back;
    }
}		
// destroy / clear
void destroyArray(){
    if(isEmptyArray()){
        cout << "Antrian kosong!!" << endl;
    }else{
        for (int i = 0; i < maksimalAntrianArray; i++){
            if(back>1){
                antrianATM[back - 1]="";
                back--;
            }else if (back == 1){
                antrianATM[back == 1] = "";
                    back = 0;
                    front = 0;
                
            }
        }
    }
}
// Display / view
void viewArray(){
    cout << "Jumlah data yang ngantri : " << countArray() << "data." << endl;
    cout << "Data Antrian ATM" << endl;
    if(isEmptyArray()){
        cout << "Antrian kosong!!" << endl;
    }else{
        for(int i = 0; i < maksimalAntrianArray; i++){
            //cek apakah ruangan kosong atau tidak
            if(antrianATM[i] !=""){
                //kalau ruangan tidak kosong
                cout << i+1 << ". " << antrianATM[i] << endl;
            }else{
                //kalau kosong
                cout << i+1 << ". (kosong)" << endl;
            }
        }
    }
    cout << "\n" << endl;
}
int main (){
    enqueueArray("Rio");
    enqueueArray("Nia");
    enqueueArray("Zaki");
    // viewArray();
    dequeueArray();
    viewArray();
}