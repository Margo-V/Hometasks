#include <iostream>

using namespace std;

#define tab "\t"


void changePlaces() 
{
	const int s = 10;
	int arr[s];
	for (int i = 0; i < s; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << tab;
	}
	cout << "\n\n";
	int temp;
	//int* pa, tmt;
	//pa = &arr[0];
	
	int* pa = arr;
	cout << arr << endl;
	cout << pa << endl;
	cout << pa+4 << tab<< *(pa +1 ) << endl;

	
}

void main()
{
	setlocale(LC_ALL, "ru");

	changePlaces();


}