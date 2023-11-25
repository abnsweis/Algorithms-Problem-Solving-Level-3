#include <iostream>
#include <string>

using namespace std;


int GetRandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void FullArrayWithRandomNumbers(int arr_numbers[3][3], short cols, short rows) {

	for (int i = 0; i < cols; i++) {

		for (int j = 0; j < rows; j++) {
			arr_numbers[i][j] = GetRandomNumber(1, 10);
		}

	}
}




bool isScalarMatrix(int matrix_1[3][3], int cols, int rows) {

	int num = matrix_1[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			
			if(i == j && matrix_1[i][j] != num){
				return false;	
			}
			
			else if(i != j && matrix_1[i][j] != 0){
				return false;
			}
		}
	}

	return true;
}


void PrintMatrix(int arr_numbers[3][3], short cols, short rows) {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << arr_numbers[i][j]<< "\t";

			// printf("%0*d\t", 2, arr_numbers[i][j]);
		}
		cout << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));
	int matrix_1[3][3] = {{
		9,
		0,
		0
	},
		{
			0,
			9,
			0
		},
		{
			0,
			0,
			9
		}};


	cout << "\nMatrix 1 :"<<endl;
	PrintMatrix(matrix_1, 3, 3);

	if(isScalarMatrix(matrix_1, 3, 3)) {
		cout << "\nYes : matrix is Scalar" << endl;
	}else {
		
	cout << "\nNo: matrix is not Scalar" << endl;
	}
	return 0;
};