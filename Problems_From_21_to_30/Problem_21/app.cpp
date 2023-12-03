#include <iostream>
using namespace std;


// Fibonacci series

void PrintFibonacciSeriesNumber(int number) {

	short prev1 = 1;
	short prev2 = 0;
	short FebNumber = 1;
	

	for (int i = 0; i < number; i++) {
		FebNumber = prev1 + prev2;
		cout << FebNumber << "  ";
		prev1 = prev2;
		prev2 = FebNumber ;

	}

}

int main() {
	PrintFibonacciSeriesNumber(10);
	return 0;
};