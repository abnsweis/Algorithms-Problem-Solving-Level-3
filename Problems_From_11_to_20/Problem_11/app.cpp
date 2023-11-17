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



int GetMatrixSum(int matrix[3][3],int cols,int rows ){

    int matrix_sum = 0 ;
    
    for (int i = 0;i< rows  ; i++) {
    	for (int j = 0; j < cols ; j++) {
	    	matrix_sum += matrix[i][j];
    	}
    }
    return matrix_sum;
    
    
}


bool AreEqualMatrices(int matrix_1[3][3],int matrix_2[3][3],int cols,int rows){
	
	return (GetMatrixSum(matrix_1,cols,rows) == GetMatrixSum(matrix_2,cols,rows));
		 
	
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
    int matrix_1[3][3],matrix_2[3][3];
    
    
    FullArrayWithRandomNumbers(matrix_1,3,3);
    FullArrayWithRandomNumbers(matrix_2,3,3);
    
    cout << "\nMatrix 1 :"<<endl ;
    PrintMatrix(matrix_1,3,3);
    cout << "\nMatrix 2 :"<<endl ;
    PrintMatrix(matrix_2,3,3);
    
    
    if(AreEqualMatrices(matrix_1,matrix_2,3,3)){
    	cout << "Yes : Matrixces are Equal" << endl;
    }else{
    	cout << "No : Matrixces are NOT Equal" << endl;
    }
    return 0;
};