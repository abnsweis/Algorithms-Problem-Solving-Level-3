#include <iostream>
#include <string>
using namespace std;

string ReadString(string msg){
	cout <<  msg ;
	string str = "";
	getline(cin,str);
	
	return str;
}


string FirstLetterToUppercase(string str){
	
	bool isFirstLetter = true;
	
	for (int i = 0; i < str.length(); i++) {
		
		if(str[i] != ' ' && isFirstLetter ){
			str[i] = toupper(str[i]);	
		}
		
		isFirstLetter = str[i] == ' ' ? true : false;
		
	}
	return str;
}


int main(){
	cout << FirstLetterToUppercase(ReadString("Please Enter Your String?:"));
	
	cout << endl;
	return 0;
};