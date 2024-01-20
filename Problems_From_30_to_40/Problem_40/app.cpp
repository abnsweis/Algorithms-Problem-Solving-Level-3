#include <iostream>
#include <string>
#include <vector>
using namespace std;


string join(vector <string> vWwords_p,string delimiter){
	
	string NewStr = "";
	
	for (string &word : vWwords_p) {
		NewStr += word + delimiter;
	}
	
	return NewStr.substr(0,NewStr.length() - delimiter.length());
}

string join(string arrStr[],int arrlength , string delimiter){
	string NewStr = "";
	
	for (int i = 0; i < arrlength; i++) {
		NewStr += arrStr[i] + delimiter;
	}
	return NewStr.substr(0,NewStr.length() - delimiter.length());
}


int main(){
	vector <string> vWwords = {"ibrahim","Al","Sweis","Abo","Asmail"};
	
	string FullName = "";
	string arr[] =  {"ibrahim","Al","Sweis","Abo","Asmail","illiteracy"};
	
	FullName = join(vWwords,"///");
	
	
	cout << FullName << endl;
	
	return 0;
};