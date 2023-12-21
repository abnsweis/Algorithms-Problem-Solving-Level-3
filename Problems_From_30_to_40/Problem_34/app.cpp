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

void PrintVowelLettersInString(string str){
	
	for (int i = 0; i < str.length(); i++) {
		if(isVowel(str[i])){
			cout << str[i] << " ";
		}
	}
	
}



int main(){
	
	string S1 = ReadString();
	
	cout << "Vowels in String are : ";
	PrintVowelLettersInString(S1) ;
	return 0;
};