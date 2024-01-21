


#include <iostream>
#include <string>
#include <vector>
#include "../../Mylib.h"
using namespace std;
using namespace Mylib;;

string replceWord(string S1,string WordToReplce,string NewWord){
	
	short pos = S1.find(WordToReplce);
	
	
	while(pos != std::string::npos){
		
		S1 = S1.replace(pos,WordToReplce.length(),NewWord);
		pos = S1.find(WordToReplce);
		
	}
	
	return S1; 
}

int main(){
	string S1 ="Welcome To Syria , Syria is a nise country" ;
	
	cout << replceWord(S1,"Syria","SYR") << endl;
	
	
	
	return 0;
};