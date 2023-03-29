#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>

using namespace std;

void quicksort(int v[], int low, int high)
{
    if (high > low)
    {

        int pivot = v[high], i, j;
        j = low;
        i = low - 1;
        while (j < high)
        {
            if (v[j] < pivot)
            {
                i++;
                swap(v[i], v[j]);
            }
            j++;
        }
        swap(v[high], v[i + 1]);

        quicksort(v, low, i);
        quicksort(v, i + 2, high);
    }

}

int main()
{
    int n;
    cin >> n;
    srand(time(0));
    int* v = new int[n];
    for (int i = 0; i < n; i++)
        v[i] = rand() % 100000000 + 10000000;
    auto begin = chrono::high_resolution_clock::now();
    quicksort(v, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto milisec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
   /* for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << endl;*/
    cout << "Milisecunde: " << milisec << endl;
    return 0;

}