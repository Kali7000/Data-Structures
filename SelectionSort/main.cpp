#include <cstdlib> 
#include <bits/stdc++.h>
using namespace std;

void selSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        
        int small = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[small])
                small = j;
        }
        if (small != i)
            swap(arr[small], arr[i]);
    }
}


int* randomArr(int n){
    
    int* arr = new int[n];
    srand(time(0));
    int min = 0, max = 1000; 

    for (int i = 0; i < n; i++){
        int randNum = (rand() % (max - min + 1))+ min;
        arr[i] = randNum;
        //cout << randNum<<" ";
    }
    return arr;
}


void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cout<<"Type the length of the array: " ;
    cin >> n;
    int* arr = randomArr(n);
//    for (int i = 0; i < 100; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
    
    cout << "Unsorted array: \n";
    printArr(arr, n);
    cout << "\n \n";
    selSort(arr, n);
    cout << "Sorted array: \n";
    printArr(arr, n);
    return 0;
}

