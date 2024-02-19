#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "clients.txt";



struct stClient {
	string AccountNumber ;
	string PINCode;
	string FullName ;
	string Phone;
	double AccountBalance;
};


stClient ReadNewClient(){
	stClient client;
	
	cout << "Enter Account Number : " ;
	getline(cin >> ws, client.AccountNumber);
	
	cout << "Enter Account PIN Code :" ;
	getline(cin,client.PINCode);
	
	cout << "Enter Account Full Name :" ;
	getline(cin,client.FullName);
	
	cout << "Enter Phone Number :";
	getline(cin,client.Phone);
	
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

void SaveDataLineToFile(string FileName, string dataLine ){
	
	fstream clientsData ;
	
	
	clientsData.open(FileName,ios::out |ios::app);//Append Mode
	
	if(clientsData.is_open()){
		clientsData << dataLine << endl;	
	}
	
	clientsData.close();
}

void AddNewClient(){
	
	stClient RecordData = ReadNewClient();
	
	SaveDataLineToFile(ClientsFileName,ConvertRecordToOneLine(RecordData));
	
}


void AddClients(){
	char AddMoreClients = 'N';
	do{
		system("cl");
		cout << "Add New Client " << endl;
		
		AddNewClient();
		cout << "Client Added Successfuly, Do Want To Add More Clients ?:";
		cin >> AddMoreClients;
		
	}while(toupper(AddMoreClients) == 'Y');
	
}


int main(){
	AddClients();
	return 0;
};