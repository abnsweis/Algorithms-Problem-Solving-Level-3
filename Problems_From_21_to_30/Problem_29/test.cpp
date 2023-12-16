#include <iostream>
#include <string>


using namespace std;
int main(){
	
	short UpperLetterStart=65;
	short UpperLetterEnd=91;
	
	short LowerLetterStart=97;
	short LowerLetterEnd=123;
	
	cout << "Upper Letters" << endl;
	for (int i = UpperLetterStart; i < UpperLetterEnd; i++) {
		
		cout << char(i) << "    ";
	}
	cout << "\n\nLower Letters" << endl;
	for (int i = LowerLetterStart; i < LowerLetterEnd; i++) {
		
		cout << char(i) << "    ";
	}
	
	
	
	return 0;
};