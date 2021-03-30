#include <iostream>

using namespace std;

#define tab "\t"

void fillArray(int arr[], const int n );
void printArray(int arr[], const int n);
void push_back(int *&arr, int &n, int value);
void push_front(int *&arr, int &n, int value);
void insert(int *&arr, int &n, int value, int index);
void pop_back(int *&arr, int &n);
void pop_front(int *&arr, int &n);
void erase(int *&arr, int &n, int index);


void main() {
	setlocale(LC_ALL, "ru");
	int s = 0; // размер массива
	int value = 0; //значение элемента 
	int index = 0; //индекс масива
	bool answ = true;
	int count_func = 0;

	cout << "Введите размер массива: " << endl;
	cin >> s;

	int* arr = new int[s] {};
	cout << tab << "\nИсходный массив: " << endl;
	fillArray(arr, s);
	printArray(arr, s);

	while (answ == true) {
		cout << "\n\nКакую функцию Вы хотели бы выбрать? (Выберите предложенную цифру)" << endl;
		cout << "1 - Добавление НУЛЕВОГО элемента в начало массива\n"
			<< "2 - Добавление ПОСЛЕДНЕГО элемента в конец массива\n"
			<< "3 - Вставка значения в массив по заданному ИНДЕКСУ\n"
			<< "4 - Удаление НУЛЕВОГО элемента из массиве\n"
			<< "5 - Удаление ПОСЛЕДНЕГО элемента из массива\n"
			<< "6 - Удаление элемента из массива по заданному ИНДЕКСУ\n"
			<< "7 - Выход\n\n";
		cin >> count_func;
		switch (count_func) {
		case 1:
			cout << "\n\nВведите добавляемый нулевой элемент: " << endl;
			cin >> value;
			push_front(arr, s, value);
			cout << "\n\nМассив после добавления нулевого элемента : " << endl;
			printArray(arr, s);
			break;
		case 2:
			cout << "\n\nВведите добавляемый последний элемент: " << endl;
			cin >> value;
			push_back(arr, s, value);
			cout << "\n\nМассив после добавления последнего элемента: " << endl;
			printArray(arr, s);
			break;
		case 3:		
			cout << "Введите индекс: " << endl;
			cin >> index;
			cout << "\n\nВведите добавляемый элемент: " << endl;
			cin >> value;	
			cout << "\n\nМассив после добавления элемента по указанному индексу: " << endl;
			insert(arr, s, value, index);
			printArray(arr, s);
			break;
		case 4:
			cout << "\n\nМассив после удаления нулевого элемента: " << endl;
			pop_front(arr, s);
			printArray(arr, s);
			break;
		case 5:
			cout << "\n\nМассив после удаления последнего элемента: " << endl;
			pop_back(arr, s);
			printArray(arr, s);
			break;
		case 6:
			cout << "\nВведите индекс: " << endl;
			cin >> index;
			erase(arr, s, index);
			printArray(arr, s);
			break;
		case 7:
			answ = false;
		default:
			cout << "Нет такого значения, попробуйте еще раз! ;)" << endl;
		}
		
	}

	delete[]arr;
}

void fillArray(int arr[], const int n)
{
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
}

void printArray(int arr[], const int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
}

void push_back(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}

	buffer[n] = value;
	delete[] arr;
	arr = buffer;	
	n++;
}

void push_front(int *&arr,  int &n, int value) 
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++) {
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void insert(int*& arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1]{};

	for (int i = 0; i < n; i++) {
		buffer[i < index ? i : i + 1] = arr[i];
	}
	buffer[index] = value;
	delete[] arr;
	arr = buffer;
	n++;
}
void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};

	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i];
	}

	delete[] arr;
	arr = buffer;	
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = arr[i +1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void erase(int*& arr, int& n,int index)
{
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++) {
		buffer[i] = (i < index ? arr[i] : arr[i + 1]);
	}

	delete[] arr;
	arr = buffer;
	n--;
}
