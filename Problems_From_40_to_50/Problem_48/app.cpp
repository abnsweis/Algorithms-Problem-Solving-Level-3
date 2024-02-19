#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

const string ClientsFileName = "../Problem_47/clients.txt";

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
	
	cout <<"| "<<left<< setw(15)  << client.AccountNumber ;
	cout <<"| "<< setw(10)  << client.PINCode ;
	cout <<"| "<< setw(35)  << client.FullName ;
	cout <<"| "<< setw(12)  << client.Phone ;
	cout <<"| "<< setw(12)  << client.AccountBalance << "|";
	cout  << endl;
}





void PrintAllClientsInScreen(vector<stClient> clientsList){
	
	system("cl");
	cout << setw(50) << "Clients List (" << clientsList.size()<<")";
	cout << "\n==============================================";     
	cout << "================================================" << endl;     
	cout << "| " << left << setw(15) << "Accout Number";     
	cout << "| " << left << setw(10) << "Pin Code";     
	cout << "| " << left << setw(35) << "Client Name";     
	cout << "| " << left << setw(12) << "Phone";     
	cout << "| " << left << setw(12) << "Balance" << "|";     
	cout << "\n==============================================";     
	cout << "================================================" << endl;  
	
	for (stClient client : clientsList) {
		PrintClientRecord(client);
	}
	cout << "==============================================";     
	cout << "================================================" << endl;  
	
	
	
	
	
}

int main(){
	PrintAllClientsInScreen(GetRecordSFromFile(ClientsFileName));
	return 0;
};