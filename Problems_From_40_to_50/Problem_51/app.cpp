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
	bool MarkForDelete = false;
};

// split String
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


// Read Client Account Number From screen
string ReadAccountNumber(string msg){
	
	string AccountNumber;
	cout << msg ;
	getline(cin,AccountNumber);
	
	
	return AccountNumber;
	
}

// convert client data from line to structure  
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

// convert client data from structure to one string  line 
string ConvertRecordToOneLine(stClient client,string sperator = "#//#"){
	
	string stClientData ="";
	
	stClientData += client.AccountNumber + sperator;
	stClientData += client.PINCode + sperator;
	stClientData += client.FullName + sperator;
	stClientData += client.Phone + sperator;
	stClientData += to_string(client.AccountBalance) ;
	
	return  stClientData;
	
}

// import clients data from file and saved to vector of 'stClients'
vector <stClient> LoadDataFromFileToVector(string FileName){
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

//find client by account number and return true if found and return false if not found
bool FindClientByAcountNumber(string AccountNumber,vector <stClient> vClients,stClient &clientD){
	
	
	for (stClient  &client: vClients) {
		
		if(client.AccountNumber == AccountNumber){
			clientD = client;
			return true;
		}
	
	}
	
	
	return false;
	
}



// Print client information
void PrintClientRecord(stClient client){
	
	cout <<"AccountNumber  :"<< client.AccountNumber << endl ;
	cout <<"PIN Code       :"<< client.PINCode << endl;
	cout <<"Full Name      :"<<  client.FullName << endl ;
	cout <<"Phone Number   :"<< client.Phone << endl ;
	cout <<"Account Balance:"<< client.AccountBalance << endl;
}

// Svae clinets to File
vector <stClient> SaveCleintsDataToFile(string FileName,vector <stClient>
vClients){
	
	fstream File ;
	string Line;
	File.open(FileName,ios::out);
	
	if(File.is_open()){
		
		for (stClient C : vClients) {
			
			if(C.MarkForDelete == false){
				Line = ConvertRecordToOneLine(C);
				File << Line << "\n";
			}
			
			
		}
		
	}
	
	return vClients;
} 



stClient changeRecordData(string AccountNumber){
	
	stClient client;
	
	client.AccountNumber = AccountNumber;
	// Updata PIN Code
	cout << "Please Enter PIN Code :" ;
	// getline(cin,client.PINCode);
	getline(cin>> ws,client.PINCode);
	// Updata Full Name
	cout << "Please Enter Full Name :" ;
	getline(cin , client.FullName);
	
	// Updata Phone Number
	cout << "Please Enter Phone Number :" ;
	getline(cin , client.Phone);
	
	// Updata Account Balance
	cout << "Please Enter Account Balancec :" ;
	cin >> client.AccountBalance;
	
	return client;	
}





bool UpdataClientByAccountNumber(string AccountNumber,string
FileName,vector<stClient>&vClients){
	char Answer = 'n';
	stClient client;
	
	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		
		PrintClientRecord(client);
		cout << "Are you sure you want to update this client?:(y/N)";
		cin >> Answer;
		if(tolower(Answer) == 'y'){
			
			
			for (stClient &C : vClients) {
				if(C.AccountNumber == client.AccountNumber){
					C = changeRecordData(AccountNumber);
					
					cout << "Client Updated Successfully :-)" << endl;
					
					break;
				 }
			}
			
			SaveCleintsDataToFile(ClientsFileName,vClients);
			
			
		
		}
			
		
	}else{
		
		cout << "Client With Account Number ("<<AccountNumber<<")is Not Found!:-(" << endl;
		return false;
	}
	
	
	return false;
}

int main(){
	system("cl");
	string AccountNumberForUpdata = ReadAccountNumber("Plrase Enter Account Number For Update :");
	
	
	vector <stClient> vClients= LoadDataFromFileToVector(ClientsFileName);
	
	UpdataClientByAccountNumber(AccountNumberForUpdata,ClientsFileName,vClients);
	
	return 0;
};