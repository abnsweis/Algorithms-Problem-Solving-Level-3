#include <iostream>
#include <string>
using namespace std;
namespace Mylib{

	string LowerAllString(string str){
	
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	
	return str;
} 
	string UpperAllString(string str){
	
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	
	return str;
} 
	

	vector <string> split(string str,string delimiter){
	
	vector <string> vString;
	
	short pos=0;
	string word = "";
	
	
	while((pos = str.find(delimiter)) != std::string::npos){
		
		word = str.substr(0,pos);
		
		if(word != ""){
			vString.push_back(word);
		}
		
		str = str.erase(0,pos + delimiter.length());
		
	}
	
	if(word != ""){
		vString.push_back(str);
	}
	
	
	return vString;
}
	
	
}
