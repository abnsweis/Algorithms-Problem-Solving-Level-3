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

char InvertCharCase(char character){
	
	return character == toupper(character) ? tolower(character) :
	toupper(character);
	
}

short CharacterCountInString(string str ,char character,bool MatchCase = true){
	
	short characterCount=0;
	
	for (int i = 0; i < str.length(); i++) {
		
		if(MatchCase){
			if(str[i] == character ){
			characterCount++;	
			}	
		}
		else{
			if(tolower(str[i]) == tolower(character) ){
			characterCount++;	
			}
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
	
	cout << "Character " << character_input  << " or "<< InvertCharCase(character_input) << " Count In string is : " <<
	CharacterCountInString(STR,character_input,false)<< endl;
	
	return 0;
};