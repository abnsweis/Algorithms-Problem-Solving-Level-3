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


bool IsPalindromMatrix(int matrix_1[3][3],short rows,short cols){
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols / 2; j++) {
			if(matrix_1[i][j] != matrix_1[i][cols - 1 - j]){
				return false;
			}
		}
	}
	return true;
}

int main() {
    srand((unsigned)time(NULL));
    int matrix_1[3][3]={{2,3,2},{3,7,3},{5,3,5}};
    // int matrix_2[3][3]={{10,1,9},{3,7,3},{8,3,6}};
	
	cout << "Matrix 1" << endl;
	PrintMatrix(matrix_1,3,3);
	
	if(IsPalindromMatrix(matrix_1,3,3)){
		cout << "Yes : is Palindrom Matrix" << endl;	
	}else{
		cout << "No : Not is Palindrom Matrix" << endl;	
	}
	
	return 0;
};
