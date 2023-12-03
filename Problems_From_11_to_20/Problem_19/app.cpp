#include <iostream>
#include <string>

using namespace std;


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

int MinNumberInMatrix(int matrix_1[3][3],int rows,int cols){
	
	int MininumNumber=matrix_1[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(matrix_1[i][j] < MininumNumber){
				MininumNumber = matrix_1[i][j];
			}
		}	
	}
	return MininumNumber;
}
int MaxNumberInMatrix(int matrix_1[3][3],int rows,int cols){
	
	int MaximumNumber=0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(matrix_1[i][j] > MaximumNumber){
				MaximumNumber = matrix_1[i][j];
			}
		}	
	}
	return MaximumNumber;
}

int main() {
    srand((unsigned)time(NULL));
    int matrix_1[3][3]={{2,2,3},{3,7,3},{8,3,5}};
    // int matrix_2[3][3]={{10,1,9},{3,7,3},{8,3,6}};
	
	cout << "Matrix 1" << endl;
	PrintMatrix(matrix_1,3,3);
	
	cout << "Minimum Number In Matrex is :"<<MinNumberInMatrix(matrix_1,3,3) << endl;
	cout << "Maximum Number In Matrex is :"<<MaxNumberInMatrix(matrix_1,3,3) << endl;
	
	return 0;
};
