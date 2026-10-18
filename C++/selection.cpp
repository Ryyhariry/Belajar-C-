#include <iostream>
using namespace std;

int main(){
    int data[] = {30, 10, 50, 20, 40};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Data Sebelum Diurutkan: ";
    for(int i = 0; i < n; i++)
    cout << data[i] << " ";
    cout <<endl;

    //algoritma selection sort
    for (int i = 0; i < n -1; i++){
        int minindex = i;
        for (int j = i + 1; j < n; j++){
            if (data [j] < data [minindex]){
                minindex = j;
            }
        }
        int temp = data[i];
        data [i] = data[minindex];
        data[minindex] =temp;
    }
    cout << "Data Setelah Diurutkan : ";
    for (int i = 0; i < n; i++)
    cout << data[i] <<" ";
    cout << endl;
}