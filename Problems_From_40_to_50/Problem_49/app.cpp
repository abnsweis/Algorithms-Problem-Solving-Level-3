#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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



vector <string> split(string str, string delimiter) {

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


stClient ConvertLineDataTostClient(string lineData,string delimiter="#//#"){
	
	
	vector <string> ClientDataLine = split(lineData,delimiter);
	
	stClient client;
	
	
	client.AccountNumber = ClientDataLine[0];
	client.PINCode = ClientDataLine[1];
	client.FullName = ClientDataLine[2];
	client.Phone= ClientDataLine[3];
	client.AccountBalance= stod(ClientDataLine[4]);
	
	
	
	return client;
	
	
}

vector <stClient> GetRecordSFromFile(string FileName){
	
	fstream File;
	vector <stClient> vClients;
	File.open(FileName,ios::in);
	
	
	if(File.is_open()){
		string 	RecordLine = "";
		
		while(getline(File,RecordLine)){
			vClients.push_back(ConvertLineDataTostClient(RecordLine));
		}
		
		
		File.close();
	}
	return vClients;
}



void PrintClientRecord(stClient client){
	
	cout <<"AccountNumber  :"<< client.AccountNumber << endl ;
	cout <<"PIN Code       :"<< client.PINCode << endl;
	cout <<"Full Name      :"<<  client.FullName << endl ;
	cout <<"Phone Number   :"<< client.Phone << endl ;
	cout <<"Account Balance:"<< client.AccountBalance << endl;
}




string ReadAccountNumber(){
	
	string AccountNumber;
	cout << "Plrase Enter Account Number :" ;
	getline(cin,AccountNumber);
	
	
	return AccountNumber;
	
}


bool FindClientByAcountNumber(string AccountNumber,stClient &clientData){
	
	vector <stClient> Records = GetRecordSFromFile(ClientsFileName);
	
	for (stClient  &client: Records) {
		
		if(client.AccountNumber == AccountNumber){
			clientData = client;
			return true;
		}
	
	}
	
	
	return false;
	
}



int main(){
	
	stClient client;
	string AccountNumber = ReadAccountNumber();
	
	if(FindClientByAcountNumber(AccountNumber,client)){
		PrintClientRecord(client);
	}else{
		cout << "Client With Account Number ("<< AccountNumber <<") Not Found :-(" << endl;
	}
	
	return 0;
};