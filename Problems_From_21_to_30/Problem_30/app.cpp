#include <iostream>
#include <string>
using namespace std;


char ReadCharacter(){
	char character =' ';
	cout << "Please Enter Character : ";
	cin >>character;
	
	return character;
}

string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}


short CharacterCountInString(string str ,char character){
	
	short characterCount=0;
	
	for (int i = 0; i < str.length(); i++) {
		
		if(str[i] == character ){
			characterCount++;	
		}
	}
	
	return characterCount;
}


int main(){
	
	string STR = ReadString();
	char character_input = ReadCharacter();
	
	
	
	cout << "Character (" << character_input ;
	cout << ") Count In string is : " <<
	CharacterCountInString(STR,character_input)<< endl;
	
	return 0;
};