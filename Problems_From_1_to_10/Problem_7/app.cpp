#include <iostream>
#include <string>
using namespace std;


void FillArrayWithOrderdNumbers(int array_numbers[3][3],int cols,int rows){
    short counter=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            counter++;
            array_numbers[i][j]=counter;
        }
    }
    
} 


void TransposeMatrix(int arr_numbers[3][3],int transpose_arr[3][3],int cols,int rows){
    
    for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < cols; j++) {
            
            transpose_arr[j][i] = arr_numbers[i][j];
        }
    }
    
}

void PrintMatrex(int arr_numbers[3][3], short cols, short rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << arr_numbers[i][j]<< "\t";
        }
        cout << endl;
    }
}


int main(){
    int array_of_ordered_numbers[3][3],transpose_arr[3][3];
    
    
    
    FillArrayWithOrderdNumbers(array_of_ordered_numbers,3,3);
    cout << "\nThe Following is a 3 * 3 Ordered Matrix :" << endl;
    PrintMatrex(array_of_ordered_numbers,3,3);
    
    TransposeMatrix(array_of_ordered_numbers,transpose_arr,3,3);
    cout << "\nThe Following is a 3 * 3 Transpose Matrix :" << endl;
    PrintMatrex(transpose_arr,3,3);
    return 0;
}; 