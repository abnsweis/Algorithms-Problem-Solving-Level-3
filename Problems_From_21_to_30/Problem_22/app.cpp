#include <iostream>
using namespace std;


void PrintFibonacciUsingRecurssion(short number , short prev1 , short prev2){
	short FibNumber = 0;
	if(number > 0){
		FibNumber = prev1 + prev2;
		cout << FibNumber << "  ";
		
		prev1 = prev2;
		prev2 = FibNumber;
		
		number--;
		PrintFibonacciUsingRecurssion(number,prev1,prev2);
	}
	
}


int main(){
	PrintFibonacciUsingRecurssion(10,1,0);
	return 0;
};