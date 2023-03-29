#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

void shellSort(int* arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int n, i;
    cin >> n;
    srand(time(0));
    int* arr = new int[n];
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100000000 + 1000000;
    auto begin = chrono::high_resolution_clock::now();
    shellSort(arr, n);
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto milisec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    /*for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;*/
    cout << "Milisecunde: " << milisec << endl;
}