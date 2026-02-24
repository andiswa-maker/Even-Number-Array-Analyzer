// Program: Even Number Array Analyzer
// Description: Accepts 10 even numbers, validates input,
// sorts them in ascending order, calculates average,
// and finds the highest value.


#include <iostream>
#include <iomanip>
//#include <conio.h>

using namespace std;
bool checkValue(int value) // one value
{
	bool isEven = false;

	//validation
	if (value % 2 == 0)
	{
		isEven = true;
	}

	return isEven;
}
void populateArray(int num[], int size) // pupulating an array
{
	//Even numbers only
	int val;
	cout << "Provide " << size << " even numbers" << endl;
	//cout << "Provide 10 even numbers\n";
	for (int x = 0; x < size; x++)
	{
		cout << "Enter value " << x + 1 << " : ";
		cin >> val;
		//Validate Even
		while (!checkValue(val)) //odd numbers
		{
			cout << "Invalid. Only even numbers are allowed.\n";
			cout << "Enter value " << x + 1 << " : ";
			cin >> val;

		}
		num[x] = val;
	}
}
//Sort array in ascending
void sortAscending(int num[], int size)
{
	//bubbleSorting
	int temp;
	for (int x = 0; x < size; x++)
	{
		for (int y = 1; y < size; y++)
		{
			//validate
			if (num[y] < num[y - 1]) //sorting ascending
			{
				temp = num[y];
				num[y] = num[y - 1];
				num[y - 1] = temp;
			}
		}
	}
}
void displayValues(int num[], int size)
{
	cout << "All array values sorted in ascending order :"<< endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Value " << i + 1 << " : " << num[i] << endl;
	}
}
double calcAverage(int num[], int size)
{
	//average = sum of all quantities/number of quantities
	//avarage = 80 / 10 = 8
	int sum = 0;
	double avg = 0.0;

	for (int i = 0; i < size; i++)
	{
		sum += num[i]; //total sum of the 10 numbers/ certain size numbers
	}
	//double = double / double
	//double = double (int / int) //casting
	avg = double(sum )/ size;

	return avg;

}
//Finding the highest value using reference
void findHigh(int num[], int size, int& high)
{
	high = num[0]; //assume 1st index is the highest
	for (int x = 1; x < size; x++) //start at index 1
	{
		if (num[x] > high)
		{
			high = num[x];
		}
	}
}
const int SIZE = 10;
int main()
{
	int numbers[SIZE];
	double average = 0.0;
	int highest = 0;

	//populating Arrays
	populateArray(numbers, SIZE);

	//sort ascending
	sortAscending(numbers, SIZE);

	//display values
	displayValues(numbers, SIZE);

	//calculate the Avg

	//Calculate and display average
	average = calcAverage(numbers, SIZE);
	cout << "The average is : " <<fixed<<setprecision(1) << average << endl;
	//cout << "The average is : " << calcAverage(numbers, SIZE) << endl;  Option 2

	//call the function of finding the highest
	findHigh(numbers, SIZE, highest);
	cout << "The highest value is : " << highest << endl;


//	_getch();
	return 0;
}