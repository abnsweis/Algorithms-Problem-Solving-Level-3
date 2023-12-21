#include <iostream>
#include <string>
using namespace std;


char ReadCharacter(){
	char character =' ';
	cout << "Please Enter Character : ";
	cin >>character;
	
	return character;
}


bool isVowel(char ch1){
	
	ch1 = tolower(ch1);
	return ( (ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1
	== 'u')   );
}

int main(){
	
	char character_input = ReadCharacter();
	
	if(isVowel(character_input)){
		cout << "Yes : \'" << character_input <<"\' is Vowel Character." << endl;	
	}else{
		cout << "No : \'" << character_input <<"\' is Not  Vowel Character." << endl;	
	}
	
	return 0;
};