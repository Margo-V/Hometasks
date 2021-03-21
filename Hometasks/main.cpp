#include <iostream>

using namespace std;

#define tab "\t"

void createArr(int arr[], const int size);
void printArr(int arr[], const int size);

void main() {
	setlocale(LC_ALL, "ru");
	int s =0;
	cout << "Введите количество элементов массива: " << endl;
	cin >> s;

	int* arr = new int[s] {};

	createArr(arr, s);
	printArr(arr, s);

	int count_even = 0;
	int count_odd = 0;

	for (int i = 0; i < s; i++) {
		if (i % 2 == 0) {
			count_even++;
		}
		else {
			count_odd++;
		}
	}

	cout << "Количество четных элементов: " << count_even << endl;
	cout << "Количество нечетных элементов: " << count_odd << endl;

	int* arr_even = new int[count_even] {};
	int* arr_odd = new int[count_odd] {};


	for (int i = 0,j =0, k=0; i < s; i++) {
		if (i % 2 == 0) {
			arr_even[j++] = arr[i];
		}
		else {
			arr_odd[k++] = arr[i];
		}
	}

	cout << "\n\nЧетные элементы: " << endl;
	printArr(arr_even, count_even);
	cout << "\n\nНечетные элементы: " << endl;
	printArr(arr_odd, count_odd);

	delete[] arr;
}

void createArr(int arr[], const int size) 
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand()%100;
	}
}

void printArr(int arr[], const int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << tab;
	}

}