#include <iostream>
#include<string>
#include<iomanip>


using namespace std;

int GetRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}



void FullArrayWithRandomNumbers(short arr_numbers[3][3], short cols, short rows) {

    for (int i = 0; i < cols; i++) {

        for (int j = 0; j < rows; j++) {
            arr_numbers[i][j] = GetRandomNumber(1, 100);
        }

    }


}


void PrintMatrexArray(short arr_numbers[3][3], short cols, short rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << arr_numbers[i][j]<< "\t";
        }
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    short arr_numbers[3][3];
    cout << endl << endl << endl << "The Foilowing is a 3 * 3 Ramdom Matrex :" << endl;
    FullArrayWithRandomNumbers(arr_numbers, 3, 3);
    PrintMatrexArray(arr_numbers, 3, 3);
    cout << endl;
    return 0;
}
