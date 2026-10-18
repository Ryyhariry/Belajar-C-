#include <algorithm>
#include <iostream>
using namespace std;

int arr[] = {4, 2, 5, 7, 3};
int main(){
    int n = sizeof(arr) / sizeof(arr[0]);
    //mengurutkan dalam ascending
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}