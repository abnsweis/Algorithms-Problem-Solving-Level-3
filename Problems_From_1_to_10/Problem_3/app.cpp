#include <iostream>
#include<string>
#include<iomanip>

using namespace std;

int GetRandomNumber(int from, int to) {
  return rand() % (to - from + 1) + from;
}



void FullArrayWithRandomNumbers(int arr_numbers[3][3],short cols,short rows){
    
    for (int i = 0; i < cols; i++) {
        
        for (int j = 0; j < rows; j++) {
            arr_numbers[i][j] = GetRandomNumber(1,100);
        }
        
    }

    
}


void PrintMatrexArray(int arr_numbers[3][3],short cols,short rows){
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << arr_numbers[i][j]<< "\t";
        }
        cout << endl;
    }
}


int SumArray(int arr[3][3],short cols,short rowNumber){
    int sum = 0;
    for (int i = 0; i < cols ; i++) {
        sum = sum + arr[rowNumber][i];
    }
    return sum;
}

void ArrayOfSumRows(int arr_numbers[3][3],int arr_sum_rows[3],int rows,int cols){
    
    for (short i = 0; i < rows; i++) {
        arr_sum_rows[i] = SumArray(arr_numbers,cols,i);
    }

}

void PrintSumMatrixArrays(int arr_sum_rows[3],int rows){
    
    
    
    
    for (short i = 0; i < rows ; i++) {
        cout << "Row "<< i + 1<< " Sum = " << arr_sum_rows[i] << endl;
    }
    
}

int main(){
    srand((unsigned)time(NULL));

    int arr_numbers[3][3] ;
    int arr_sum_rows[3];
    
    FullArrayWithRandomNumbers(arr_numbers,3,3);
    cout << "\n\nThe following is a 3*3 random matrix \n";
    PrintMatrexArray(arr_numbers,3,3);
    
    ArrayOfSumRows(arr_numbers,arr_sum_rows,3,3);

    cout << "\nThe the following are the sum of each row in the matrix:" << endl;
    PrintSumMatrixArrays(arr_sum_rows,3);
    return 0;
}
