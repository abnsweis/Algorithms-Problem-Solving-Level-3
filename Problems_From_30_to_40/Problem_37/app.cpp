#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString(){
	string str="";
	cout << "Please Enter Your String : ";
	getline(cin,str);
	
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



int main(){
	vector <string> vString ;
	vString = split(ReadString()," ");
	
	cout << "Tokens :"<< vString.size() << endl;
	for (string &i : vString) {
		cout << i << endl;
	}
	
	return 0;
};