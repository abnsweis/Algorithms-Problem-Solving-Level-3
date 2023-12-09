#include <iostream>
#include <string>

using namespace std;

string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}


string FirstLetterToLowercase(string str){
	
	bool isFirstLetter=true;
	
	for (int i = 0; i < str.length(); i++) {
		
		if(str[i] != ' ' && isFirstLetter){
			str[i] = tolower(str[i]);
		}
		
		isFirstLetter = str[i] == ' ' ? true : false;
		
	}
	
	return str;
}


int main(){
	
	cout << FirstLetterToLowercase(ReadString()) << endl;
	
	return 0;
	
};