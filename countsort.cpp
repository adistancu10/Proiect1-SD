#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

int main()
{
	int i, j, n, max, h;
	cin >> n;
	srand(time(0));
	int* arr = new int[n];
	for (i = 0; i < n; i++)
		arr[i] = rand() % 100000000 + 1000000;
	max = -1;
	auto begin = chrono::high_resolution_clock::now();
	for (i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	int* fr = new int[max + 1];
	for (j = 0; j <= max; j++)
		fr[j] = 0;
	for (i = 0; i < n; i++)
		fr[arr[i]]++;
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto milisec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

	cout << "Milisecunde: " << milisec << endl;
	return 0;
}