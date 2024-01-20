#include <iostream>
#include <string>

using namespace std;
string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}



void PrintEachWordInString(string str){

	string delimiter = " ";
	short pos = 0;
	string Sword =  "";
	
	while((pos = str.find(delimiter)) != std::string::npos){
		
		Sword = str.substr(0,pos);
		if(Sword != "" ){
			cout << Sword << endl;	
		}
		
		str.erase(0,pos + delimiter.length());
	}
	
	if(Sword == ""){
		cout << str << endl;
	}
	
	
}

int main(){
	string S1 = ReadString();
	
	PrintEachWordInString(S1) ;
	return 0;
};