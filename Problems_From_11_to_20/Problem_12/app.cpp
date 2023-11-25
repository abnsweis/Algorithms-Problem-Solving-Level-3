#include <iostream>
#include <string>

using namespace std;


int GetRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void FullArrayWithRandomNumbers(int arr_numbers[3][3], short cols, short rows) {

    for (int i = 0; i < cols; i++) {

        for (int j = 0; j < rows; j++) {
            arr_numbers[i][j] = GetRandomNumber(1, 3);
        }

    }
}




bool AreTopicalMatrices(int matrix_1[3][3],int matrix_2[3][3],int cols,int rows){
	
	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			
			if(matrix_1[i][j]!=matrix_2[i][j]){
				return false;
			}
			
		}
	}	 
	
	return true;
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
    cout << "\nMatrix 1 :"<<endl ;
    PrintMatrix(matrix_1,3,3);
    
    FullArrayWithRandomNumbers(matrix_2,3,3);
    cout << "\nMatrix 2 :"<<endl ;
    PrintMatrix(matrix_2,3,3);
    
    
    if(AreTopicalMatrices(matrix_1,matrix_2,3,3)){
    	cout << "Yes : Matrixces are Topical  :-)" << endl;
    }else{
    	cout << "No : Matrixces are NOT Topical :-(" << endl;
    }
    return 0;
};
