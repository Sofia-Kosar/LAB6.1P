#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Sum(int* a, const int size, int i, int S)
{
	if (!(a[i] % 2 == 0 || i % 13 == 0))
		S += a[i];
	if (i < size - 1)   
		return Sum(a, size, i + 1, S);
	else
		return S;
}
int Number(int* a, const int size, int index)
{
	if (index >= size) {
		return 0;
	}

	int count = Number(a, size, index + 1);

	if (!(a[index] % 2 == 0 || index % 13 == 0)) {
		count++;
	}

	return count;
}
void Replace(int* a, const int size, int index)
{
	if (index >= size) {
		return;
	}

	if (!(a[index] % 2 == 0 || index % 13 == 0)) {
		a[index] = 0;
	}

	Replace(a, size, index + 1);
}
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 21;
	int a[n];
	int Low = 15;
	int High = 85;
	Create(a, n, Low, High, 0);
	cout << "Unmodified ";
	Print(a, n, 0);
	int sum = Sum(a, n, 0, 0);
	int count = Number(a, n , 0);
	Replace(a, n, 0);
	cout << "Modified ";
	Print(a, n, 0);
	cout << "Number of elements " << count << endl;
	cout << "Sum of elements " << sum << endl;
    return 0;
}
