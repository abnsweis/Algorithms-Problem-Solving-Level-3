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



int main(){
	vector <string> vWwords = {"ibrahim","Al","Sweis","Abo","Asmail"};
	
	string FullName = "";
	
	FullName = join(vWwords,",,,");
	
	
	cout << FullName << endl;
	
	return 0;
};