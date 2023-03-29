#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

void CountSort(int* arr, int loc, int n)
{
	int c[10];
	int* arr_temp = new int[n];
	int j;

	for (j = 0; j < 10; j++)
		c[j] = 0;

	for (int i = 0; i < n; i++)
		c[(arr[i] / loc) % 10]++;

	for (j = 1; j < 10; j++)
		c[j] += c[j - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		arr_temp[c[(arr[i] / loc) % 10] - 1] = arr[i];
		c[(arr[i] / loc) % 10]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = arr_temp[i];
}

void RadixSort(int* arr, int maxim, int n)
{
	for (int loc = 1; maxim / loc > 0; loc = loc * 10)
		CountSort(arr, loc, n);
}

int main()
{
	int i, maxim = -1;
	int n;
	cin >> n;
	srand(time(0));
	int* arr = new int[n];
	for (i = 0; i < n; i++)
		arr[i] = rand() % 100000000 + 1000000;

	for (i = 0; i < n; i++)
		if (maxim < arr[i])
			maxim = arr[i];
	auto begin = chrono::high_resolution_clock::now();
	RadixSort(arr, maxim, n);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto milisec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).c();
	/*for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;*/
	cout << "Milisecunde: " << milisec << endl;
}