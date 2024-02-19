#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClient {
	string AccountNumber ;
	string PINCode;
	string FullName ;
	string Phone;
	double AccountBalance;
};


stClient ReadClientData(){
	stClient client;
	
	cout << "Please Enter Data" << endl;
	
	cout << "Enter Account Number : " ;
	cin >> client.AccountNumber;
	
	cout << "Enter Account PIN Code :" ;
	cin >> client.PINCode;
	
	cin.ignore(std::numeric_limits<char>::max(),'\n');
	cout << "Enter Account Full Name :" ;
	getline(cin,client.FullName);
	
	cout << "Enter Phone Number :";
	cin >> client.Phone;
	
	cout << "Enter Account Balance :";
	cin >> client.AccountBalance;
	
	return client;
	
}

string ConvertRecordToOneLine(stClient client,string sperator = "#//#"){
	
	string stClientData ="";
	
	stClientData += client.AccountNumber + sperator;
	stClientData += client.PINCode + sperator;
	stClientData += client.FullName + sperator;
	stClientData += client.Phone + sperator;
	stClientData += to_string(client.AccountBalance) ;
	
	return  stClientData;
	
}

int main(){
	
	stClient client1;
	
	client1 = ReadClientData();
	
	string DataOneLine = ConvertRecordToOneLine(client1);
	
	cout << DataOneLine << endl;
	
	return 0;
};