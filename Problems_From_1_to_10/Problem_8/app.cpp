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
            arr_numbers[i][j] = GetRandomNumber(1, 10);
        }

    }


}


void PrintMatrix(int arr_numbers[3][3], short cols, short rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            //cout <<setfill('0')<< setw(2)<< arr_numbers[i][j]<< "\t";
            // printf(" %0*d ",arr_numbers[i][j]);
            printf(" %0*d   ", 2, arr_numbers[i][j]);
        }
        cout << endl;
    }
}

void MultiplyMatrix(int matrix_1[3][3],int matrix_2[3][3],int
arr_mult_result[3][3],int cols,int rows){
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            arr_mult_result[i][j] = matrix_1[i][j] * matrix_2[i][j]   ;
            
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int ArrWithRandomNumber_1[3][3],
    ArrWithRandomNumber_2[3][3];
    //The result of multiplying each element by its corresponding element in both 'ArrWithRandomNumber_1' and 'ArrWithRandomNumber_2'
    int matrix_with_multiplying_result[3][3];


    // Full Array "ArrWithRandomNumber_1" With Random Number From 1 To 10;
    FullArrayWithRandomNumbers(ArrWithRandomNumber_1, 3, 3);
    // Full Array "ArrWithRandomNumber_2" With Random Number From 1 To 10;
    FullArrayWithRandomNumbers(ArrWithRandomNumber_2, 3, 3);

    cout << "\nMatrix 1 :"<<endl;
    PrintMatrix(ArrWithRandomNumber_1, 3, 3);
    cout << "\nMatrix 2 :"<<endl;
    PrintMatrix(ArrWithRandomNumber_2, 3, 3);

    
    MultiplyMatrix(ArrWithRandomNumber_1,ArrWithRandomNumber_2,matrix_with_multiplying_result,3,3);
    cout << "\nThe Following is a Multiplying Result :"<<endl;
    PrintMatrix(matrix_with_multiplying_result,3,3);
    return 0;
};