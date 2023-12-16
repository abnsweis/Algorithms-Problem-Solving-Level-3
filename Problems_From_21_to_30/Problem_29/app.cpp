#include <iostream>
#include <string>

using namespace std;

string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}

enum enWhatToCount  { Capital = 0 , Smail = 1 };


short WhatCountLetters (string str , enWhatToCount WhatLetters){
	
	int counter =0;
	
	
	for (int i = 0; i < str.length(); i++) {
		
		if(WhatLetters == enWhatToCount::Capital && isupper(str[i])){
			counter++;
		}
		if(WhatLetters == enWhatToCount::Smail&& islower(str[i])){
			counter++;
		}
		
	}
	
	
	return counter;
	
	
}



short GetCapitalLettersCountInString(string str){

	short LettersCount=0;

	for (int i = 0; i < str.length(); i++) {
		if(isupper(str[i])){
			LettersCount++;	
		}
	}
	
	return LettersCount;	
}

short GetLowerLettersCountInString(string str){

	short LettersCount=0;
	
	
	for (int i = 0; i < str.length(); i++) {
		
		if(islower(str[i])){
			LettersCount++;	
		}
		
	}
	
	return LettersCount;	
}



int main(){

	string Str = ReadString();
	
	cout << "String Length :" << Str.length() << endl;
	cout << "Capital Letters Count :" <<
	WhatCountLetters(Str,enWhatToCount::Capital)<< endl;
	cout << "Lower Letters Count :" << WhatCountLetters(Str,enWhatToCount::Smail) << endl;
	
	return 0;
};