#include <iostream>
#include <string>
#include <vector>

using namespace std;


string RemoverAllPunctuationsFromString(string S1){
	
	
	string S2 = "";
	
	for (int i = 0; i < S1.length(); i++) {
			
		if(!ispunct(S1[i])){
			S2 += S1[i] ;
				
		}
	}
		
		
		
			
	
	
	
	return S2;
}


int main(){
	
	string str = "miro;    ;sweis";
	cout << str.length() << endl;
	str = RemoverAllPunctuationsFromString(str);
	cout << str.length() << endl;
	
	cout << str<< endl;
	
	return 0;
};