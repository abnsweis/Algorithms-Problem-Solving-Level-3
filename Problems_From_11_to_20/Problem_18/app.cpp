#include <iostream>
#include <string>

using namespace std;


int GetRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void FullArrayWithRandomNumbers(int arr_numbers[3][3], short cols, short rows) {

    for (int i = 0; i < cols; i++) {

        for (int j = 0; j < rows; j++) {
            arr_numbers[i][j] = GetRandomNumber(10, 20);
        }

    }
}

void PrintMatrix(int arr_numbers[3][3], short cols, short rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            //cout <<setfill('0')<< setw(2)<< arr_numbers[i][j]<< "\t";
            // printf(" %0*d ",arr_numbers[i][j]);
            printf("%0*d\t", 2, arr_numbers[i][j]);
        }
        cout << endl;
    }
}

bool isNumberInMatrix(int matrix[3][3],short cols,short rows,int number){
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(matrix[i][j] == number){
				return true;	
			}
		}
	}
	return false;
}


void PrintIntersectedNumbers(int matrix_1[3][3],int matrix_2[3][3],int cols,int rows){
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(isNumberInMatrix(matrix_1,cols,rows,matrix_1[i][j]),isNumberInMatrix(matrix_2,cols,rows,matrix_2[i][j])){
				cout << matrix_1[i][j]  << " ";	
			}
		}
	}
	
}


int main() {
    srand((unsigned)time(NULL));
    int matrix_1[3][3]={{1,1,3},{3,7,3},{8,3,5}};
    int matrix_2[3][3]={{10,1,9},{3,7,3},{8,3,6}};
	//FullArrayWithRandomNumbers(matrix_1,3,3);
	cout << "Matrix 1" << endl;
	PrintMatrix(matrix_1,3,3);
	cout << "Matrix 2" << endl;	
	PrintMatrix(matrix_2,3,3);
	
	PrintIntersectedNumbers(matrix_1,matrix_2,3,3);
    return 0;
};
