#include <iostream>
#include <string>

using namespace std;

char ReadCharacter(){
	char character =' ';
	cout << "Please Enter Character : ";
	cin >>character;
	
	return character;
}





int main(){
	
	char ch = ReadCharacter();
	
	cout << "Character Before Invert " << endl;
	cout << ch << endl;
	
	ch = InvertCharCase(ch);
	
	cout << "Character After Invert " << endl;
	cout << ch << endl;
	
	
	return 0;
};