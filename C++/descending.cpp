#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int arr[] = {6, 9, 2, 1, 3};
int main(){
    int n = sizeof(arr) / sizeof(arr[0]);
    //mengurutkan dalam descending
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
        cout << arr[i] << "";
    
    return 0;
}