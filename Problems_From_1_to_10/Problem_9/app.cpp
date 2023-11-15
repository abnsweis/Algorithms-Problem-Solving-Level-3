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
            printf("%0*d\t", 2, arr_numbers[i][j]);
        }
        cout << endl;
    }
}

void PrintMiddleOfColsMatrix(int arr_numbers[3][3],int cols,int rows){
    short MiddleCols = cols / 2;
    for (int i = 0; i < rows; i++) {
        printf("%0*d\t",2,arr_numbers[i][MiddleCols]);
    }
    cout << endl;
    
}
void PrintMiddleOfRowsMatrix(int arr_numbers[3][3],int cols,int rows){
    short MiddleRows = rows / 2;
    for (int j = 0; j < rows; j++) {
        printf("%0*d\t",2,arr_numbers[MiddleRows][j]);
    }
    cout << endl;
    
}
int main() {
    srand((unsigned)time(NULL));
    int arr_numbers[3][3];
    
    
    FullArrayWithRandomNumbers(arr_numbers,3,3);
    
    
    
    PrintMatrix(arr_numbers,3,3);
    cout  << endl;
    cout << "Mddle Cols of Matrix 1 is : " << endl;
    PrintMiddleOfColsMatrix(arr_numbers,3,3);
    cout  << endl;
    cout << "Mddle Rows of Matrix 1 is : " << endl;
    PrintMiddleOfRowsMatrix(arr_numbers,3,3);
    
    
    return 0;
};