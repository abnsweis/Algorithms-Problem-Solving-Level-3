#include <iostream>

#include "../../Mylib.h"

using namespace std;

string RevereString(string S1) {
	string S2 = "";
	vector < string > vString;


	vString = Mylib::split(S1, " ");

	vector < string > ::iterator iter = vString.end();

	while(iter != vString.begin()) {

		iter--;

		S2 += *iter + " ";


	}

	return Mylib::trimright(S2);
}


int main() {

	string S1 = Mylib::ReadString();
	string reversS1 = RevereString(S1);

	cout << reversS1 << endl;

	return 0;
};