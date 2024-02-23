#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const string FileName = "clients.txt";


//////////////////////////////////////////

// client information
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


// Convert Record To on line
string ConvertRecordToOneLine(stClient client,string sperator = "#//#"){
	
	string stClientData ="";
	
	stClientData += client.AccountNumber + sperator;
	stClientData += client.PINCode + sperator;
	stClientData += client.FullName + sperator;
	stClientData += client.Phone + sperator;
	stClientData += to_string(client.AccountBalance) ;
	
	return  stClientData;
	
}


vector <stClient> SaveCleintsDataToFile(string FileName,vector <stClient>
vClients){
	
	fstream File ;
	string Line;
	File.open(FileName,ios::out);
	
	if(File.is_open()){
		
		for (stClient &C : vClients) {
			
			if(C.MarkForDelete == false){
				Line = ConvertRecordToOneLine(C);
				File << Line << "\n";
			}
			
			
		}
		
	}
	
	return vClients;
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

// Client is exist
bool ClientExistByAccountNumber(string AccountNumber){
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;
	
	for (stClient &C : vClients) {
		if(C.AccountNumber == AccountNumber){
			return true;	
		}	
	}
	return false;
}

// Read Client Account Number From screen
string ReadAccountNumber(string msg){
	
	string AccountNumber;
	cout << msg ;
	cin >> AccountNumber;
	
	
	return AccountNumber;
	
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




// Print Client Card
void PrintClientCard(stClient client){
	cout << "\n==========================" << endl;
	cout <<"AccountNumber  : "<< client.AccountNumber << endl ;
	cout <<"PIN Code       : "<< client.PINCode << endl;
	cout <<"Full Name      : "<<  client.FullName << endl ;
	cout <<"Phone Number   : "<< client.Phone << endl ;
	cout <<"Account Balance: $"<< client.AccountBalance << endl;
	cout << "==========================\n" << endl;
}



//////////////////////////////////////////
// Print Client Balance 
void PrintClientBalance(stClient client){
	
	cout <<"| "<<left<< setw(15)  << client.AccountNumber ;
	cout <<"| "<< setw(20)  << client.FullName ;
	cout <<"| $"<< setw(10)  << client.AccountBalance << "|";
	cout  << endl;
}



void ShowTransacionsMainMenueScreen();

enum enTransacionsOpations{deposit=1,withdrow=2,totalBalanses=3,mainMenue};

short ReadTransactionsOpation(){

	short choice;
	cout << "Choose What Do You want to Do? [1 to 4]:" ;
	cin >> choice;
	
	return choice;
	
};

// Go To Transacions Screen
void GoToTransactionsScreen(){
	
	cout<<"Press Enter to go back to Transacions main menu...." ;
	cin.ignore().get();
	ShowTransacionsMainMenueScreen();
	
};





void Deposit(string AccountNumber,int Amount){
	
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;

	char ProcessConfirmation = 'y';
	cout << "Are you sure you want perform is transaction?(y/N):";
	cin >> ProcessConfirmation;
	if(tolower(ProcessConfirmation) == 'y'){
		for (stClient &C : vClients) {
			if(C.AccountNumber == AccountNumber){
				
				C.AccountBalance += Amount; 
				SaveCleintsDataToFile(FileName,vClients);
				cout << "New Balance is $"<< C.AccountBalance << endl;
				break;
				
			}
		}
	}
	
	
	
	
	
}


// Deposit Screen
void ShowDepositScreen(){
	cout << "======================================" << endl;
	cout << "            Deposit Screen           " << endl;
	cout << "======================================" << endl;
	
	string AccountNumber = ReadAccountNumber("Please Enter Account Number :");
	int amount = 0; 
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;
	stClient client;

	while(!FindClientByAcountNumber(AccountNumber,vClients,client)){
		cout << "\nClient With Account Number [ "<< AccountNumber << " ] is NotFound :-(" << endl;
		AccountNumber = ReadAccountNumber("Please Enter Another Account Number :");
	}
	
	PrintClientCard(client);
	
	cout << "Please Enter Deposit Amount :";
	cin >> amount;
	Deposit(AccountNumber,amount);
} 

// Withdrow Screen
void ShowWithdrowScreen(){
	cout << "======================================" << endl;
	cout << "            Withdrow Screen           " << endl;
	cout << "======================================" << endl;
	string AccountNumber = ReadAccountNumber("Please Enter Account Number :");
		int amount = 0; 
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;
	stClient client;

	while(!FindClientByAcountNumber(AccountNumber,vClients,client)){
		cout << "\nClient With Account Number [ "<< AccountNumber << " ] is NotFound :-(" << endl;
		AccountNumber = ReadAccountNumber("Please Enter Another Account Number :");
	}
	
	PrintClientCard(client);
	cout << "Please Enter Withdrow Amount :";
	cin >> amount;
	
	while(client.AccountBalance < amount){
		cout << "amount exceeds the balance,you can withdrow to up $" <<
		client.AccountBalance<<endl;
		cout << "Please Enter Withdrow Amount :";
		cin >> amount;
	}
	Deposit(AccountNumber,amount*-1);
}


// Show All Client 
void ShowTotalBalancesScreen(){
	system("cl");
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;
	cout << "\n====================================================="<<endl;      
	cout << setw(30) << "Balances List (" << vClients.size()<<") Clients " ;
	cout << "\n====================================================="<<endl;      
	cout << "| " << left << setw(15) << "Accout Number";   
	cout << "| " << left << setw(20) << "Client Name";     
	cout << "| " << left << setw(10) << "Balance" << " |";     
	cout << "\n====================================================="<<endl;     

	
	for (stClient  &client : vClients) {
		PrintClientBalance(client);
	}
	cout << "====================================================="<<endl;
	
	
	
}


void PerformOptionsTransaction(enTransacionsOpations opation){
	
	switch(opation){
		
		case enTransacionsOpations::deposit:
			system("cl");
			ShowDepositScreen();
			GoToTransactionsScreen();
			break;
			
		case enTransacionsOpations::withdrow:
			system("cl");
			ShowWithdrowScreen();
			GoToTransactionsScreen();
			break;
		
		case enTransacionsOpations::totalBalanses:
			system("cl");
			ShowTotalBalancesScreen();
			GoToTransactionsScreen();
			break;
		
	}
	
}
void ShowTransacionsMainMenueScreen(){
	system("cl");
	cout << "======================================" << endl;
	cout << "        Transacions Main Menue        " << endl;
	cout << "======================================" << endl;
	cout << "[1] Deposit " << endl;
	cout << "[2] Withdrow" << endl;
	cout << "[2] Total Balanses" << endl;
	cout << "[2] Main Menue" << endl;
	
	 PerformOptionsTransaction((enTransacionsOpations)ReadTransactionsOpation());  
	
}

using namespace std;
int main(){
	ShowTransacionsMainMenueScreen();
	
	
	return 0;
};