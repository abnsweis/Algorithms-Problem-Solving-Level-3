#include <iostream>
#include <string>

using namespace std;




void PrintMatrix(int arr_numbers[3][3], short cols, short rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout <<arr_numbers[i][j] << "\t";
        }
        cout << endl;
    }
}


int CountNumberInMatrix(int matrix[3][3],int cols,int rows,int
search_number ){
	
	int NumberCount=0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(matrix[i][j]== search_number){
				NumberCount++;
			}
			
		}
	}
	
	return NumberCount;
}

bool IsSparseMatrix(int matrix_1[3][3],short cols,int rows){
	short countZeroz= CountNumberInMatrix(matrix_1,cols,rows,0);
	
	return (countZeroz > (cols * rows - countZeroz));
	
}
int main() {
    srand((unsigned)time(NULL));
    // int matrix_1[3][3] = {{0,0,3},{0,0,0},{0,1,0}};
    int matrix_1[3][3] = {{5,10,3},{2,4,0},{0,0,0}};
	cout << "Matrix 1" << endl;
	PrintMatrix(matrix_1,3,3);
	
	if(IsSparseMatrix(matrix_1,3,3)){
		cout << "Yes : Matrix is Sparse " << endl;
	}else{
		cout << "No : Matrix is Not Sparse " << endl;
	}
    return 0;
};
