#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

void merge(int* arr, int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;
    int* array_temp_left = new int[n1];
    int* array_temp_right = new int[n2];

    for (int i = 0; i < n1; i++)
        array_temp_left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        array_temp_right[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (array_temp_left[i] <= array_temp_right[j]) {
            arr[k] = array_temp_left[i];
            i++;
        }
        else {
            arr[k] = array_temp_right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = array_temp_left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = array_temp_right[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int low, int high) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int n, i, low, high;
    cin >> n;
    srand(time(0));
    int* arr = new int[n];
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100000000 + 1000000;

    low = 0;
    high = n - 1;
    auto begin = chrono::high_resolution_clock::now();
    mergeSort(arr, low, high);
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto milisec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

  
    cout << "Milisecunde: " << milisec << endl;
}
