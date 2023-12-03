#include <iostream>
#include <string>

using namespace std;


int ReadNumberPositive(string massage){ 
    int number;
    do{
        cout << massage ; 
        cin >> number ;
    }while(number < 0);
    
    return number;
}

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

int main() {
    srand((unsigned)time(NULL));
    int matrix_1[3][3];
	int search_number = ReadNumberPositive("\nEnter the number to search in matrix?:");
	FullArrayWithRandomNumbers(matrix_1,3,3);
	PrintMatrix(matrix_1,3,3);
	
	if(isNumberInMatrix(matrix_1,3,3,search_number)){
		cout << "Yes : Number "<<search_number<<" Exist in Matrix" << endl;
	}else{
		cout << "No : Number "<<search_number<<" Not Exist in Matrix" << endl;
		
	}
	
    return 0;
};
