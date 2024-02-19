#include <iostream>
#include <string>
#include <vector>

using namespace std;


string ReadString() {
	string str = "";
	cout << "Please Enter Your String : ";
	getline(cin, str);

	return str;
}

string join(vector < string > vWwords_p, string delimiter) {

	string NewStr = "";

	for (string &word: vWwords_p) {
		NewStr += word + delimiter;
	}

	return NewStr.substr(0, NewStr.length() - delimiter.length());
}

vector < string > split(string str, string delimiter) {

	vector < string > vString;

	short pos = 0;
	string word = "";

	while((pos = str.find(delimiter)) != std::string::npos) {

		word = str.substr(0, pos);

		if(word != "") {
			vString.push_back(word);
		}

		str = str.erase(0, pos + delimiter.length());

	}

	if(word != "") {
		vString.push_back(str);
	}


	return vString;
}

string UpperAllString(string str) {

	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}

	return str;
}

string CoustomReplace(string S1, string WordToReplace, string NewWord, bool match_case = true) {

	vector < string > StringWords = split(S1, " ");



	for (string &string_word: StringWords) {
		if(match_case) {

			if(string_word == WordToReplace) {
				string_word = NewWord;
			}
		}else {
			if(UpperAllString(string_word) == UpperAllString(WordToReplace)) {
				string_word = NewWord;
			}
		}

	}
	return join(StringWords, " ");

}




int main() {

	string S1 = "Welcome To Syria , syria is a nise country";

	cout << CoustomReplace(S1, "Syria", "SYR")<<endl;
	return 0;
};