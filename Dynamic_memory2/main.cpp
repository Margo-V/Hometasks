#include <iostream>

using namespace std;

#define tab "\t"
//#define PUSH_POP_ROWS

#ifdef PUSH_POP_ROWS
void PrintArray(int** arr, const int m, const int n);
void ShowArray(int** arr, int& m);
void push_row_back(int**& arr, int& m, int count_cow);
void push_row_front(int**& arr, int& m, int count_row);
void insert_row(int**& arr, int& m, int count_row, int index);
void pop_row_back(int**& arr, int& m, int count_row);
void pop_row_front(int**& arr, int& m, int count_row);
void erase_row(int**& arr, int& m, int count_row, int index);
#endif // PUSH_POP_ROWS

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);
void push_col_back(int** arr, const int m, int& n);
void push_col_front(int** arr, const int m, int& n);
void insert_col(int** arr, const int m, int& n, int index);
void pop_col_back(int** arr, const int m, int& n);
void pop_col_front(int** arr, const int m, int& n);
void erase_col(int** arr, const int m, int& n, int index);
/*
void pop_col_back(...);
void pop_col_front(...);
void erase_col(...);*/

void clear(int**& arr, int& m);




void main()
{
	setlocale(LC_ALL, "ru");

	bool answ = true;
	int choice = 0;

	#ifdef PUSH_POP_ROWS
		cout << "Введите количество строк:" << tab; cin >> m;
		cout << "Введите количество столбцов:" << tab; cin >> n;

		int** arr = new int* [m];

		for (int i = 0; i < m; i++) {
			arr[i] = new int[n] {};
		}

		cout << tab << "Исходный массив:\n\n";
		PrintArray(arr, m, n);
		ShowArray(arr, m);

		while (answ == true) {
			cout << "Какую функцию хотите выбрать(укажите цифру):\n"
				<< "1 - Добавление строки В КОНЕЦ массива \n"
				<< "2 - Добавление строки В НАЧАЛО массива\n"
				<< "3 - Добавление пустой строки ПО УКАЗАННОМУ ИНДЕКСУ\n"
				<< "4 - Удаление ПОСЛЕДНЕЙ строки из массива\n"
				<< "5 - Удаление НУЛЕВОЙ строки из массива\n"
				<< "6 - Удаление строки ПО УКАЗАННОМУ ИНДЕКСУ\n"
				<< "7 - Выход\n\n";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "\nДобавление строки в КОНЕЦ массива:" << endl;
				cout << "Введите количество вставляемых строк" << tab; cin >> count_row;
				push_row_back(arr, m, count_row);
				ShowArray(arr, m);
				break;
			case 2:
				cout << "\nДобавление строки в НАЧАЛО массива:" << endl;
				cout << "Введите количество вставляемых строк" << tab; cin >> count_row;
				push_row_front(arr, m, count_row);
				ShowArray(arr, m);
				break;
			case 3:
				cout << "\nДобавление пустой строки ПО УКАЗАННОМУ ИНДЕКСУ" << endl;
				cout << "Введите индекс:" << tab; cin >> index;
				cout << "Введите количество вставляемых строк" << tab; cin >> count_row;
				insert_row(arr, m, count_row, index);
				ShowArray(arr, m);
				break;
			case 4:
				cout << "\nУдаление ПОСЛЕДНЕЙ строки из массива" << endl;
				cout << "Введите количество удаляемых строк" << tab; cin >> count_row;
				pop_row_back(arr, m, count_row);
				ShowArray(arr, m);
				break;
			case 5:
				cout << "\nУдаление НУЛЕВОЙ строки из массива" << endl;
				cout << "Введите количество удаляемых строк:" << tab; cin >> count_row;
				pop_row_front(arr, m, count_row);
				ShowArray(arr, m);
				break;
			case 6:
				cout << "\nУдаление строки ПО УКАЗАННОМУ ИНДЕКСУ" << endl;
				cout << "Введите индекс:" << tab; cin >> index;
				cout << "Введите количество удаляемых строк" << tab; cin >> count_row;
				erase_row(arr, m, count_row, index);
				ShowArray(arr, m);
				break;
			case 7:
				answ = false;
			default:
				cout << "Нет такого значения, попробуйте еще раз ;)\n\n";
			}
		}
	#endif // PUSH_POP_ROWS

	int m = 0; // количество строк
	int n = 0; //количество элементов строки(столбцы)
	int index = 0;

	cout << "Введите количество строк: ";
	cin >> m;
	cout << "Введите количество элементов строки: ";
	cin >> n;
	//1) Создаем массив указателей и сохраняем его адрес в указ на указ
	int** arr = new int* [m];
	//2) Выделяем память под строки 2-мерного массива:
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n] {};
	}

	cout << "Память выделена: " << endl;

	FillRand(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в конец массива:" << endl;
	push_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца в начало массива:" << endl;
	push_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "Добавление столбца по индексу" << endl;
	cout << "Введите индекс: " << tab; 
	cin >> index;
	insert_col(arr, m, n, index);
	Print(arr, m, n);

	cout << "Удаление столбца в конце массива:" << endl;
	pop_col_back(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление столбца в начале массива:" << endl;
	pop_col_front(arr, m, n);
	Print(arr, m, n);

	cout << "Удаление столбца в из массива по индексу:" << endl;
	cout << "Введите индекс: " << tab;
	cin >> index;
	erase_col(arr, m, n, index);
	Print(arr, m, n);

	clear(arr, m);
}


#ifdef PUSH_POP_ROWS
void PrintArray(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void ShowArray(int** arr, int& m)
{
	for (int i = 0; i < m; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

#endif // PUSH_POP_ROWS

#ifdef PUSH_POP_ROWS
void push_row_back(int**& arr, int& m, int count_row)
{
	int** buffer = new int* [m + count_row]{};

	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	clear(arr, m);
	arr = buffer;
	m += count_row;
}
void push_row_front(int**& arr, int& m, int count_row)
{
	int** buffer = new int* [m + count_row]{};

	for (int i = 0; i < m; i++)
	{
		if (i < count_row)
		{
			buffer[i] = 0;
		}
		else
		{
			buffer[i + count_row] = arr[i];
		}

	}

	clear(arr, m);
	arr = buffer;
	m += count_row;
}
void insert_row(int**& arr, int& m, int count_row, int index)
{
	int** buffer = new int* [m + count_row];

	for (int i = 0; i < m; i++)
	{
		buffer[(i < index ? i : i + count_row)] = arr[i];
	}

	clear(arr, m);
	arr = buffer;
	m += count_row;
}
void pop_row_back(int**& arr, int& m, int count_row)
{
	int** buffer = new int* [m - count_row];

	for (int i = 0; i < m - count_row; i++) {
		buffer[i] = arr[i];
	}

	clear(arr, m);
	arr = buffer;
	m -= count_row;

}
void pop_row_front(int**& arr, int& m, int count_row)
{
	int** buffer = new int* [m - count_row];

	for (int i = count_row, k = 0; i < m, k < m - count_row; k++, i++) {
		buffer[k] = arr[i];
	}

	clear(arr, m);
	arr = buffer;
	m -= count_row;
}
void erase_row(int**& arr, int& m, int count_row, int index)
{
	int** buffer = new int* [m - count_row];

	for (int i = 0; i < index; i++) {
		buffer[i] = arr[i];
	}

	for (int i = index + count_row, k = index; i < m, k < m - count_row; k++, i++) {
		buffer[k] = arr[i];
	}

	clear(arr, m);
	arr = buffer;
	m -= count_row;
}

#endif // PUSH_POP_ROWS

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}
void push_col_back(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++) {
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++) {
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
void push_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++) {
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++) {
			buffer[j +1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
void insert_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++){
		int* buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++) {
			buffer[j < index ? j : j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
void pop_col_back(int** arr, const int m, int& n)
{
	for(int i = 0; i > m; i++) {
		int* buffer = new int[--n]{};
		for (int j = 0; j < n; j++) {
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	
}
void pop_col_front(int** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++) {
		int* buffer = new int[n-1] {};
		for (int j = 0; j < n; j++) {
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
void erase_col(int** arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++) {
		int* buffer = new int[n - 1];
		for (int j = 0; j < n; j++) {
			buffer[j] = arr[i][j < index ? j : j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
void clear(int **&arr,  int &m)
{
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;	
}		
