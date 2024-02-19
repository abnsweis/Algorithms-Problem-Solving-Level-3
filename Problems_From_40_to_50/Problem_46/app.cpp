#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct stClient {
	string AccountNumber ;
	string PINCode;
	string FullName ;
	string Phone;
	double AccountBalance;
};


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


stClient ConvertLineDataToStClient(string lineData,string delimiter){
	
	
	vector <string> ClientDataLine = split(lineData,delimiter);
	
	stClient client;
	
	
	client.AccountNumber = ClientDataLine[0];
	client.PINCode = ClientDataLine[1];
	client.FullName = ClientDataLine[2];
	client.Phone= ClientDataLine[3];
	client.AccountBalance= stod(ClientDataLine[4]);
	
	
	
	return client;
	
	
}


void PrintClientDataToScreen(stClient clientData){
	
	cout << "Account Number :" << clientData.AccountNumber << endl;
	cout <<  setw(15)<<"PIN Code"  <<":" << clientData.PINCode << endl;
	cout << "Full Name" << setw(15)<< ":" <<clientData.FullName << endl;
	cout << "Phone" << setw(15)<< ":" <<clientData.Phone << endl;
	cout << "Account Balance" << setw(15)<< ":" <<clientData.AccountBalance << endl;
	
}


int main(){
	
	string lineData = "A50226#//#1423#//#Ibrahim Al Sweis#//#+15155148585#//#100000.000000";
	
	
	stClient c = ConvertLineDataTostClient(lineData,"#//#");
	
	PrintClientDataToScreen(c);
	
	return 0;
};