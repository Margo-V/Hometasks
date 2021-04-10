#include "recursionFunctions.h"

#define tab "\t"
//#define ROW

template <typename T>
T recursionRow(T a, T b);
string stars(string star, int count);
int sumOfNum(int num1, int num2);
int minSumInArr(int arr[], const int s);

int recursionFunctions()
{
	
#ifdef ROW
	float num = 0;
	float row = 0;
	cout << "Возведение в степень методом рекурсии: " << endl;
	cout << "Введите число: " << endl;
	cin >> num;
	cout << "В какую степень хотите возвести? " << endl;
	cin >> row;
	cout << recursionRow(num, row);
#endif // ROW

#ifdef ROW
	string star = "*";
	int count = 0;

	cout << "Какое количество звезд вы зотите вывести? " << endl;
	cin >> count;
	stars(star, count);
#endif // ROW

	/*int num1 = 0;
	int num2 = 0;
	cout << "Введите первое число: " << tab; cin >> num1;
	cout << "Введите второе число: " << tab; cin >> num2;

	cout << sumOfNum(num1, num2);*/

	const int s = 10;
	int arr[s];
	for (int i = 0; i < s; i++) {
		arr[i] = rand();
		cout << arr[i] << tab;
	}


	return 0;
}

int minSumInArr(int arr[], const int s)
{	
	int i = 0;
	int sum = arr[i];
	int min_sum = 0;
	
	for (; i < i + 3; )
	{
		min_sum
		if (min_sum < sum) {

		}
		arr[i]
	}

}

int sumOfNum(int num1, int num2)
{
	if (num1 <= num2) {
		return num1 + num2 + sumOfNum(++num1, --num2);
	}
	/*else if (num1 > num2) {
		return sumOfNum(num1, ++num2) + num2;
	}*/
}

template <typename T>
T recursionRow(T a, T b) {

	if (b > 1){
		return a * recursionRow( a, --b);
	}
	/*else if (b < -1) {
		return (1 / (a * recursionRow(a, ++b)));
	}*/
	else if (b == 0) {
		return a = 1;
	}
	else {
		return a;
	}
}

string stars(string star, int count)
{
	cout << star;
	if (count > 1) {
		return star + stars(star, --count);
	}
	return star;
}