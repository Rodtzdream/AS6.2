#include <iostream>
#include <ctime>

using namespace std;

struct INF
{
	int key;
	char info;
};

void Print(INF arr[], int N)
{
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << arr[i].key << " ";
	cout << endl;
	for (int i = 0; i < N; i++)
		cout << arr[i].info << " ";

	cout << endl;
}

void QuickSort(INF arr[], int first, int last)
{
	int middle = arr[(first + last) / 2].key;

	int i = first;
	int j = last;

	do
	{
		while (arr[i].key < middle)
			i++;
		while (arr[j].key > middle)
			j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else
			break;
	} while (i <= j);

	if (i < last)
		QuickSort(arr, i, last);
	if (j > first)
		QuickSort(arr, first, j);

}

int main()
{
	srand(time(0));
	const int N = 10;
	INF arr[N];
	cout << "Array:";
	for (int i = 0; i < N; i++)
	{
		arr[i].key = rand() % 10 + 1;
		arr[i].info = rand() % 25 + 97;
	}
	Print(arr, N);

	QuickSort(arr, 0, N - 1);

	cout << "\nSorted:";
	Print(arr, N);

	return 0;
}