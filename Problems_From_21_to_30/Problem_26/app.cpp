#include <iostream>
#include "../../Mylib.h"

using namespace std;

string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
	return str;
}





int main(){
	string str = ReadString();
	str  = Mylib::LowerAllString(str);
	
	cout << str << endl;
	cout << Mylib::UpperAllString(str) << endl;
	
	
	return 0;
	
};