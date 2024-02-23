#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const string FileName = "clients.txt";

void ShowMainMenueScreen();

// Emum Of Choices
enum enMainMenuOptions
{eShowAllClients=1,eAddNewClients=2,eDeleteClients=3,eUpdateClient=4,eFindClient=5,eExit=6};

// client information
struct stClient {
	string AccountNumber ;
	string PINCode;
	string FullName ;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

// Print Client Record 
void PrintClientRecord(stClient client){
	
	cout <<"| "<<left<< setw(15)  << client.AccountNumber ;
	cout <<"| "<< setw(10)  << client.PINCode ;
	cout <<"| "<< setw(20)  << client.FullName ;
	cout <<"| "<< setw(15)  << client.Phone ;
	cout <<"| "<< setw(10)  << client.AccountBalance << "|";
	cout  << endl;
}

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


// Show All Client 
void ShowAllClientsScreen(){
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;
	cout << setw(50) << "Clients List (" << vClients.size()<<")";
	cout << "\n==============================================";     
	cout << "===================================" << endl;     
	cout << "| " << left << setw(15) << "Accout Number";     
	cout << "| " << left << setw(10) << "Pin Code";     
	cout << "| " << left << setw(20) << "Client Name";     
	cout << "| " << left << setw(15) << "Phone";     
	cout << "| " << left << setw(10) << "Balance" << "|";     
	cout << "\n==============================================";     
	cout << "===================================" << endl;  

	
	for (stClient  &client : vClients) {
		PrintClientRecord(client);
	}
	cout << "==============================================";     
	cout << "===================================" << endl;  
	
	
}

bool ClientExistByAccountNumber(string AccountNumber){
	vector <stClient> vClients = LoadDataFromFileToVector(FileName) ;
	
	for (stClient &C : vClients) {
		if(C.AccountNumber == AccountNumber){
			return true;	
		}	
	}
	return false;
}

// Read Data  Client 
stClient ReadNewClient(){
	stClient client;

	cout << "Enter Account Number : " ;
	getline(cin >> ws, client.AccountNumber);
	
	while(ClientExistByAccountNumber(client.AccountNumber)){
		cout << "The account number is already in use.\nPlease enter another number :" ;
		getline(cin >> ws, client.AccountNumber);
		
	}
	
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

// Save a new client in file 
void SaveDataLineToFile(string FileName, string dataLine ){
	
	fstream clientsData ;
	
	
	clientsData.open(FileName,ios::out |ios::app);//Append Mode
	
	if(clientsData.is_open()){
		clientsData << dataLine << endl;	
	}
	
	clientsData.close();
}

// Add New Client

void AddNewClient(){
	
	stClient NewClient ;
	NewClient = ReadNewClient();
	
	SaveDataLineToFile(FileName,ConvertRecordToOneLine(NewClient));
	
	
}


// Add New Client's
void AddNewClients(){
	char AddMoreClients = 'N';


	do{
		AddNewClient();
		cout << "Client Added Successfuly, Do Want To Add More Clients ?:";
		cin >> AddMoreClients;
		
	}while(toupper(AddMoreClients) == 'Y');
	
}

// Show Add New Clients  Screen
void ShowAddNewClientsScreen(){
	
	cout << "========================================" << endl;
	cout << "         Add Clients Screen           " << endl;
	cout << "========================================" << endl;
	
	AddNewClients();
	
}

// Svae clinets to File
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


//Add a Mark to the account that matches the desired account name 
bool MarkClientForDeleteByAccountNumber(string AccountNumber , vector <stClient>
&clients){
	
	for (stClient  &client : clients) {
		
		if(client.AccountNumber == AccountNumber){
				client.MarkForDelete = true;
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

void PrintClientCard(stClient client){
	
	cout <<"AccountNumber  :"<< client.AccountNumber << endl ;
	cout <<"PIN Code       :"<< client.PINCode << endl;
	cout <<"Full Name      :"<<  client.FullName << endl ;
	cout <<"Phone Number   :"<< client.Phone << endl ;
	cout <<"Account Balance:"<< client.AccountBalance << endl;
}

// Delete Client by Account number and return true if successfly deleted  or  false is not deleted 
bool DeleteClientByAccountNumber(string AccountNumber,vector <stClient> &vClients){
	cout << AccountNumber << endl;
	stClient client ;
	char Answer = 'n';
	
	
	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		PrintClientCard(client);	
		
		cout << "\nAre you sure you want delete this client? y/n : " ;
		cin >> Answer;
		
		
		if(toupper(Answer) == 'Y'){
			
			MarkClientForDeleteByAccountNumber(AccountNumber,vClients);
			
			SaveCleintsDataToFile(FileName,vClients);
			
			vClients = LoadDataFromFileToVector(FileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		} 

	}
	else{
			cout << "\nClient with Account Number (" << AccountNumber<< ") is NotFound!"<<endl;
			return false;
		}
	return  false;
	
}




// ************************************
void ShowDeleteClientsScreen(){
	cout << "========================================" << endl;
	cout << "          Delete Clients Screen          " << endl;
	cout << "========================================" << endl;
	
	vector <stClient> vClients= LoadDataFromFileToVector(FileName);
	
	
	string AccountNumber = ReadAccountNumber("Please Enter Client Account Number to Delete:");
	
	DeleteClientByAccountNumber(AccountNumber,vClients);


}


stClient ChangeClientRecord(string AccountNumber){
	
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

bool UpdataClientByAccountNumber(string AccountNumber,vector<stClient>&vClients){
	char Answer = 'n';
	stClient client;
	
	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		
		PrintClientCard(client);
		cout << "Are you sure you want to update this client?:(y/N)";
		cin >> Answer;
		if(tolower(Answer) == 'y'){
			
			
			for (stClient &C : vClients) {
				if(C.AccountNumber == client.AccountNumber){
					C = ChangeClientRecord(AccountNumber);
					
					cout << "Client Updated Successfully :-)" << endl;
					
					break;
				 }
			}
			
			SaveCleintsDataToFile(FileName,vClients);
			
			
		
		}
			
		
	}else{
		
		cout << "Client With Account Number ("<<AccountNumber<<")is Not Found!:-(" << endl;
		return false;
	}
	
	
	return false;
}


void ShowUpDateClientScreen(){
	
	cout << "========================================" << endl;
	cout << "          Update Client Screen          " << endl;
	cout << "========================================" << endl;
	
	vector <stClient> vClients= LoadDataFromFileToVector(FileName);
	string AccountNumber = ReadAccountNumber("Please Enter Client Account Number to Update :");
	UpdataClientByAccountNumber(AccountNumber,vClients);
	

}

// ************************************






void ShowFindClientScreen(){
	cout << "========================================" << endl;
	cout << "          Find Client Screen          " << endl;
	cout << "========================================" << endl;	
	
	vector <stClient> vClients= LoadDataFromFileToVector(FileName);
	string AccountNumber = ReadAccountNumber("Please Enter Client Account Number  :");
	stClient client;
	

	if(FindClientByAcountNumber(AccountNumber,vClients,client)){
		PrintClientCard(client);
	}else{
		cout << "Client With Account Number [ "<< AccountNumber << " ] is unavailable :-(" << endl;
	}
	
}

void ShowEndScreen(){
	cout << "Program is End....." << endl;
}

void GoBackToMainMenu(){
	cout<<"Press Enter to go back to main menu...." ;
	cin.ignore().get();
	ShowMainMenueScreen();
}

short ReadMainMenueOpation(){

	short choice;
	cout << "Choose What Do You want to Do? [1 to 6]:" ;
	cin >> choice;
	
	return choice;
	
}

 





void PerFormMainMenuOpation(enMainMenuOptions Opation ){
	
	
	switch(Opation){
		case enMainMenuOptions::eShowAllClients:
			system("cl");
			ShowAllClientsScreen();
			GoBackToMainMenu();
			break;
		
		case enMainMenuOptions::eAddNewClients:
			system("cl");
			ShowAddNewClientsScreen();
			GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eDeleteClients:
			system("cl");
			ShowDeleteClientsScreen();
			GoBackToMainMenu();
			break;
		case enMainMenuOptions::eUpdateClient:
			system("cl");
			ShowUpDateClientScreen();
			GoBackToMainMenu();
			break;
		case enMainMenuOptions::eFindClient:
			system("cl");
			ShowFindClientScreen();
			GoBackToMainMenu();
			break;
		case enMainMenuOptions::eExit:
			ShowEndScreen();
			break;
			
	}
	
	
}



// This Function To Shiw Banner Main Menue 
void ShowMainMenueScreen(){
	system("cl");
	cout << "========================================" << endl;
	cout << "          Main Menue Screen             " << endl;
	cout << "========================================" << endl;
	cout << "   [1] Show Client List." << endl;
	cout << "   [2] Add  Client." << endl;
	cout << "   [3] Delete Client." << endl;
	cout << "   [4] Update Client Info." << endl;
	cout << "   [5] Find Client." << endl;
	cout << "   [6] Exit!." << endl;
	cout << "========================================" << endl;
	PerFormMainMenuOpation((enMainMenuOptions)ReadMainMenueOpation());
}








int main(){
	ShowMainMenueScreen();
	return 0;
};