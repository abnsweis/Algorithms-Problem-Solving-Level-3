#include <iostream>
#include <string>
using namespace std;


string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}


bool isVowel(char ch1){
	
	ch1 = tolower(ch1);
	return ( (ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1
	== 'u')   );
}

short CountVowel(string str ){

	short CountLettersVowel =0;

	for (int i = 0; i < str.length(); i++) {
		if(isVowel(str[i])){
			CountLettersVowel++;
		}
	}
	return CountLettersVowel;
	
}



int main(){
	
	string string_input = ReadString();
	
	cout << "Count Vowel Letters is "<< CountVowel(string_input) << endl;
	
	
	return 0;
};