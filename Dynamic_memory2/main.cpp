#include <iostream>

using namespace std;

#define tab "\t"


void PrintArray(int** arr, const int m, const int n);
void ShowArray(int** arr, int& m,int& n);
void push_row_back(int**& arr, int& m, int& n,int count_cow);
void push_row_front(int**& arr, int& m, int& n, int count_row);
void insert_row(int**& arr, int& m, int& n, int count_row, int index);
void pop_row_back(int**& arr, int& m, int& n, int count_row);
void pop_row_front(int**& arr, int& m, int& n, int count_row);
void erase_row(int**& arr, int& m, int& n, int count_row, int index);



void clear(int**& arr, int& m);


void main()
{
	setlocale(LC_ALL, "ru");
	int m = 0, n = 0, count_row = 0;
	int index = 0;
	bool answ = true;
	int choice = 0;

	cout << "������� ���������� �����:" << tab; cin >>  m ;
	cout << "������� ���������� ��������:" << tab; cin >> n;

	int** arr = new int* [m];

	for (int i = 0; i < m; i++) {
		arr[i] = new int[n] {};
	}

	cout << tab << "�������� ������:\n\n";
	PrintArray(arr, m, n);
	ShowArray(arr, m, n);

	while (answ == true) {
		cout << "����� ������� ������ �������(������� �����):\n"
			<< "1 - ���������� ������ � ����� ������� \n"
			<< "2 - ���������� ������ � ������ �������\n"
			<< "3 - ���������� ������ ������ �� ���������� �������\n"
			<< "4 - �������� ��������� ������ �� �������\n"
			<< "5 - �������� ������� ������ �� �������\n"
			<< "6 - �������� ������ �� ���������� �������\n"
			<< "7 - �����\n\n";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "\n���������� ������ � ����� �������:" << endl;
				cout << "������� ���������� ����������� �����" << tab; cin >> count_row;
				push_row_back(arr, m, n, count_row);
				ShowArray(arr, m, n);
				break;
			case 2:
				cout << "\n���������� ������ � ������ �������:" << endl;
				cout << "������� ���������� ����������� �����" << tab; cin >> count_row;
				push_row_front(arr, m, n, count_row);
				ShowArray(arr, m, n);
				break;
			case 3:
				cout << "\n���������� ������ ������ �� ���������� �������" << endl;
				cout << "������� ������:" << tab; cin >> index;
				cout << "������� ���������� ����������� �����" << tab; cin >> count_row;
				insert_row(arr, m, n, count_row, index);
				ShowArray(arr, m, n);
				break;
			case 4:
				cout << "\n�������� ��������� ������ �� �������" << endl;
				cout << "������� ���������� ��������� �����" << tab; cin >> count_row;
				pop_row_back(arr, m, n, count_row);
				ShowArray(arr, m, n);
				break;
			case 5:
				cout << "\n�������� ������� ������ �� �������" << endl;
				cout << "������� ���������� ��������� �����:" << tab; cin >> count_row;
				pop_row_front(arr, m, n, count_row);
				ShowArray(arr, m, n);
				break;
			case 6:
				cout << "\n�������� ������ �� ���������� �������" << endl;
				cout << "������� ������:" << tab; cin >> index;
				cout << "������� ���������� ��������� �����" << tab; cin >> count_row;
				erase_row(arr, m, n, count_row, index);
				ShowArray(arr, m, n);
				break;
			case 7:
				answ = false;
			default:
				cout << "��� ������ ��������, ���������� ��� ��� ;)\n\n";
		}
	}

	clear(arr, m);
}


void PrintArray(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}
void ShowArray(int** arr,  int& m, int &n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
void push_row_back(int**& arr, int& m, int& n, int count_row)
{
	int** buffer = new int* [m + count_row];
	for (int i = 0; i < m + count_row; i++) {
		buffer[i] = new int[n] {};
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			buffer[i][j] = arr[i][j];
		}
	}

	clear(arr, m);
	arr = buffer;
	m += count_row;
}
void push_row_front(int**& arr, int& m, int& n, int count_row)
{
	
	int** buffer = new int* [m + count_row];
	for (int i = 0; i < m +count_row; i++) {
		buffer[i] = new int[n] {};
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			buffer[i + count_row][j] = arr[i][j];
		}
	}

	clear(arr, m);
	arr = buffer;
	m += count_row;
}
void insert_row(int**& arr, int& m, int& n, int count_row, int index)
{
	int** buffer = new int*[m + count_row];
	for (int i = 0; i < m + count_row; i++) {
		buffer[i] = new int[m] {};
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			buffer[(i < index ? i : i + count_row)][j] = arr[i][j];
		}
	}
	clear(arr, m);
	arr = buffer;
	m += count_row;
}
void pop_row_back(int**& arr, int& m, int& n, int count_row)
{
	int** buffer =new int*[m - count_row];
	for (int i = 0; i < m - count_row; i++) {
		buffer[i] = new int[n] {};
	}
	

	for (int i = 0; i < m - count_row; i++) {
		for (int j = 0; j < n; j++) {
			buffer[i][j] = arr[i][j];
		}
	}

	clear(arr, m);
	arr = buffer;
	m -= count_row;

}
void pop_row_front(int**& arr, int& m, int& n, int count_row)
{
	int** buffer = new int* [m - count_row];
	for (int i = 0; i < m - count_row; i++) {
		buffer[i] = new int[n] {};
	}

	for (int i = count_row, k=0; i < m, k < m-count_row; k++, i++) {
		for (int j = 0; j < n; j++) {
			buffer[k][j] = arr[i][j];
		}
	}

	clear(arr, m);
	arr = buffer;
	m -= count_row;
}
void erase_row(int**& arr, int& m, int& n, int count_row, int index)
{
	int** buffer = new int* [m -count_row];
	for (int i = 0; i < m- count_row; i++) {
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < index; i++) {
		for (int j = 0; j < n; j++) {
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = index + count_row, k = index; i < m, k <m - count_row; k++, i++) {
		for (int j = 0; j < n; j++) {
			buffer[k][j] = arr[i][j];
		}
	}

	clear(arr, m);
	arr = buffer;
	m -= count_row;
}
void clear(int **&arr,  int &m)
{
	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;	
}