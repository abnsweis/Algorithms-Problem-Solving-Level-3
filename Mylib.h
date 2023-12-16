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
	
	
	
}
