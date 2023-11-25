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


int CheckFrequencyOfNumberInMatrix(int matrix[3][3],int cols,int rows,int
search_number ){
	
	int FrequencyNumber=0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if(matrix[i][j]== search_number){
				FrequencyNumber++;
			}
			
		}
	}
	
	return FrequencyNumber;
}


int main() {
    srand((unsigned)time(NULL));
    int matrix_1[3][3];
	int search_number = ReadNumberPositive("\nEnter the number to count in matrix?:");
	FullArrayWithRandomNumbers(matrix_1,3,3);
	PrintMatrix(matrix_1,3,3);
	
	
	
	cout << "frequency Number "<<search_number<<" in matrix of "<<
	CheckFrequencyOfNumberInMatrix(matrix_1,3,3,search_number) <<" times" << endl;
	 
    return 0;
};
