#include <iostream>
#include <string>
using namespace std;

string ReadString(string msg){
	cout <<  msg ;
	string str = "";
	getline(cin,str);
	
	return str;
}

void GetFirstLetteraOfAllWordsInText(string text){
	
	bool isFirstLetter=true;
	for (short i = 0; i < text.length(); i++) {
		if(text[i] != ' ' && isFirstLetter){
			cout << text[i] << endl;	
		}
		
		isFirstLetter = (text[i] == ' ' ? true : false );
	}

}

int main(){
	
	GetFirstLetteraOfAllWordsInText(ReadString("Please Enter Your String?:"));
	return 0;
};