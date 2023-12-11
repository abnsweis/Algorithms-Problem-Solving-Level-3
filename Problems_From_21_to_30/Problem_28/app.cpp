#include <iostream>
#include <string>
using namespace std;


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
// string InvertString(string str){
	
// 	for (int i = 0; i < str.length(); i++) {
		
		
// 		str[i] = str[i] == toupper(str[i]) ? tolower(str[i]) : toupper(str[i]);
// 	}
	
// 	return str;
// }
string InvertString(string str){
	
	for (int i = 0; i < str.length(); i++) {
		
		
		str[i] = InvertCharCase(str[i]);
	}
	
	return str;
}


int main(){
	
	cout << InvertString(ReadString()) << endl;
	return 0;
};