#include <iostream>
#include <string>

using namespace std;



string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}



string TrimLeft(string str){
	
	
	for (int i = 0; i < str.length(); i++) {
		
		if(str[i] != ' ' ){
			str.erase(0,i);
		}
		
	}
	return str;
}


string TrimRight(string str){
	cout << str.length() << endl;
	for (int i = str.length() - 1  ; i > 0; i--) {
		
		if(str[i] != ' '){
			cout << i << endl;
			return str.erase(i+1,str.length());
		}
		
	}
	return str;
}


string trim(string str){
	return TrimRight(TrimLeft(str));
}

int main(){
	string s1 = ReadString();

	s1=TrimRight(s1);
	cout << s1 << "*";
	cout << s1.length() << endl;
	
	return 0;
};


