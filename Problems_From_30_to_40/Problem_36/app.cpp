#include <iostream>
#include <string>
using namespace std;
string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}


int CountEachWordsInString(string str ){
	
	short counter = 0;
	string delimiter = " ";
	short pos = 0;
	string word = "";
	while((pos = str.find(delimiter)) != std::string::npos){
		
		word = str.substr(0,pos);
		
		if(word != ""){
			counter++;
		}
		str.erase(0,pos + delimiter.length());
		
	}
	
	if(word != ""){
		counter++;
		
	}
	return counter;
}

using namespace std;
int main(){
	
	
	string s1 = ReadString();
	cout << CountEachWordsInString(s1) << endl;
	return 0;
};