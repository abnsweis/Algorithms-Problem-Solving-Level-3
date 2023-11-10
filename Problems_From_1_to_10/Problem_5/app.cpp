#include <iostream>
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

void PrintMatrexArray(int arr_numbers[3][3], short cols, short rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << arr_numbers[i][j]<< "\t";
        }
        cout << endl;
    }
}


int SumCol(int array_numbers[3][3], int col_number, int rows) {

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += array_numbers[i][col_number];
    }

    return sum;
}


void SumColsInArray(int arr_numbers[3][3], int arr_cols_sum[3], int cols, int rows){
    
    for (int i = 0; i < rows; i++) {
        
        arr_cols_sum[i] = SumCol(arr_numbers,i,rows);
    }
    
} 

void PrintEachColSum(int arr_cols_sum[3], int rows) {

    for (short i = 0; i < rows; i++) {
        cout << "Col "<< i + 1<< " Sum = " << arr_cols_sum[i] << endl;
    }

}
int main() {

    srand((unsigned)time(NULL));
    int array_numbers[3][3];
    int arr_SumColsArray[3];


    FullArrayWithRandomNumbers(array_numbers, 3, 3);
    cout << "the following is a 3*3 random matrix \n";
  
    PrintMatrexArray(array_numbers, 3, 3);
  
    cout << "\nThe the following are the sum of each col in the matrix:\n";
    SumColsInArray(array_numbers,arr_SumColsArray,3,3);
    PrintEachColSum(arr_SumColsArray,3); 


    return 0;
};