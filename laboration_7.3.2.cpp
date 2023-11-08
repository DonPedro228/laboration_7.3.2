#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Input(int** a, int i, int j, const int rowCount, const int colCount);
void Print(int** a, int i, int j, const int rowCount, const int colCount);
void Rotate_Right(int** a, int i, int j, const int rowCount, const int colCount, int x);
void Rotate_Down(int** a, int i, int j, const int rowCount, const int colCount, int x);
void User_Choice(int** a, int i, int j, const int rowCount, const int colCount, int user_choice, int x);

int main()
{
	int rowCount, colCount;
	int x;
	cout << " X = "; cin >> x;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, 0, 0, rowCount, colCount);
	Print(a, 0, 0, rowCount, colCount);
	int user_choice;
	cout << "Choice method of rotate (1 for Rotate_Right, 2 for Rotate_Down): ";
	cin >> user_choice;
	User_Choice(a, 0, 0, rowCount, colCount, user_choice, x);
	
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Input(int** a, int i, int j, const int rowCount, const int colCount)
{
	if (i == rowCount) {
		return;  
	}

	if (j == colCount) {
		Input(a, i + 1, 0, rowCount, colCount);
		return;
	}

	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];


	Input(a, i, j + 1, rowCount, colCount);
}


void Print(int** a, int i, int j, const int rowCount, const int colCount)
{
	if (i == rowCount) {
		return;  
	}

	if (j == colCount) {
		cout << endl;
		Print(a, i + 1, 0, rowCount, colCount);
		return;
	}

	cout << setw(4) << a[i][j];

	Print(a, i, j + 1, rowCount, colCount);
}


void Rotate_Right(int** a, int i, int j, const int rowCount, const int colCount, int x) {
	if (i == rowCount) {
		return; 
	}

	if (j < x) {
		int temp = a[i][colCount - 1];
		for (int l = colCount - 1; l > 0; l--) {
			a[i][l] = a[i][l - 1];
		}
		a[i][0] = temp;

		Rotate_Right(a, i, j + 1, rowCount, colCount, x);
	}
	else {
		Rotate_Right(a, i + 1, 0, rowCount, colCount, x);
	}
}


void Rotate_Down(int** a, int i, int j, const int rowCount, const int colCount, int x) {
	if (j == colCount) {
		return;
	}

	if (i < x) {
		int temp = a[rowCount - 1][j];
		for (int l = rowCount - 1; l > 0; l--) {
			a[l][j] = a[l - 1][j];
		}
		a[0][j] = temp;

		Rotate_Down(a, i + 1, j, rowCount, colCount, x);
	}
	else {
		Rotate_Down(a, 0, j + 1, rowCount, colCount, x);
	}
}

void User_Choice(int** a, int i, int j, const int rowCount, const int colCount, int user_choice, int x) {

	if (user_choice == 1) {
		Rotate_Right(a, 0, 0, rowCount, colCount, x);
	}
	else if (user_choice == 2) {
		Rotate_Down(a, 0, 0, rowCount, colCount, x);
	}
	else {
		cout << "Invalid choice. Please choose 1 or 2." << endl;
		User_Choice(a, i, j, rowCount, colCount, user_choice, x); 
	}
	Print(a, 0, 0, rowCount, colCount);

}


