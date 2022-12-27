/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 1 Project
* Inventory Management (Picker)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
void loadArrays(string[], int[], float[], int&);
void calculateValues(int[], float[], float[], int);
void displayTable(string[], int[], float[], float[], int&);

int main()
{

	const int SIZE = 20;
	string product[SIZE];
	int quantity[SIZE];
	float cost[SIZE];
	float value[SIZE];

	int refCounter = 0;

	fstream text;
	text.open("inventory.txt", ios::in | ios::out);

	loadArrays(product, quantity, cost, refCounter);

	calculateValues(quantity, cost, value, refCounter);

	displayTable(product, quantity, cost, value, refCounter);




	text.close();

	system("pause");
	return 0;
}

void loadArrays(string product[], int quantity[], float cost[], int& counter)
{
	fstream text;
	text.open("inventory.txt", ios::in);
	while (!text.eof())
	{
		text >> product[counter];
		text >> quantity[counter];
		text >> cost[counter];
		counter++;
	}

	text.close();
}

void displayTable(string product[], int quantity[], float cost[], float value[], int& counter)
{
	fstream text;
	text.open("inventory.txt", ios::in | ios::out);

	cout << "Product Code     " << "Qty on Hand     " << "Cost Each     " << "Total Value     " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout.width(12); cout << left << product[i];
		cout.width(16); cout << right << quantity[i];
		cout.width(14); cout << right << cost[i];
		cout.width(16); cout << right << value[i];
		if (value[i] > 9000) {
			cout.width(16); cout << left << " !!!" << endl;
		}
		else {
			cout.width(16); cout << left << "    " << endl;
		}

	}
	cout << endl;
	int num = 0;
	int largest = 0;
	for (int p = 0; p < counter; p++)
	{
		if (num < value[p]) {
			num = value[p];
			largest = p;
		}
	}
	cout << "The product with the highest inventory value is " << product[largest] << "." << endl;
	float totalValue = 0, totalQuantity = 0;
	for (int i = 0; i < counter; i++)
	{
		totalValue += value[i];
		totalQuantity += quantity[i];
	}
	cout << fixed << setprecision(2) << "The average cost of an inventory item is $" << totalValue / totalQuantity << "." << endl;

	text.close();
}

void calculateValues(int quantity[], float cost[], float value[], int counter)
{
	int i = 1;

	for (int i = 0; i < counter; i++)
	{
		value[i] = cost[i] * quantity[i];
	}

}