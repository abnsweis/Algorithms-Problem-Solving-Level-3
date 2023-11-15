#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int GetRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void FullArrayWithRandomNumbers(int arr_numbers[3][3], short cols, short rows) {

    for (int i = 0; i < cols; i++) {

        for (int j = 0; j < rows; j++) {
            arr_numbers[i][j] = GetRandomNumber(1, 100);
        }

    }
}



int GetMatrixSum(int matrix[3][3],int cols,int rows ){

    int matrix_sum = 0 ;
    
    for (int i = 0;i< rows  ; i++) {
    	for (int j = 0; j < cols ; j++) {
	    	matrix_sum += matrix[i][j];
    	}
    }
    return matrix_sum;
    
    
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

int main() {
    srand((unsigned)time(NULL));
    int arr_numbers[3][3];
    
    
    FullArrayWithRandomNumbers(arr_numbers,3,3);
    
    cout << "\nMatrix 1 :"<<endl ;
    PrintMatrix(arr_numbers,3,3);
    cout << "Sum of Matrix 1 is :" << GetMatrixSum(arr_numbers,3,3) <<endl;
    return 0;
};