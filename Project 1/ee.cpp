
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
	getline(cin,AccountNumber);
	
	
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
bool DeleteClientByAccountNumber(string AccountNumber,string FileName,vector <stClient> &vClients){
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
void DeleteClients(){
	string AccountNumber ;
	vector <stClient> vClients= LoadDataFromFileToVector(FileName);
	char DeleteMore = 'Y';
	do{
		system("cl");
		
		cout << "========================================" << endl;
		cout << "          Delete Client Screen          " << endl;
		cout << "========================================" << endl;

		cout << "Please Enter Client Account Number to Delete:" ;
		cin >> AccountNumber;
		
		DeleteClientByAccountNumber(AccountNumber,FileName,vClients);
		
		cout << "\nDo You want to delete more clients?:" ;
		cin >> DeleteMore;
		
		
		
		
	}while(toupper(DeleteMore)== 'Y');
	cout<<"Press Enter to go back to main menu...." ;
	cin.ignore().get();
	ShowMainMenueScreen();
	
}

// ************************************
A100#//#1234#//#Ibrahim Al Sweis#//#+905375699970#//#10000.000000
A200#//#1234#//#Asmail Al Sweis#//#+9053835938#//#5000.000000
A300#//#50467#//#Omer Abdo#//#+96377729993#//#4510.000000
A400#//#34962#//#Asil Ahmad#//#+183939383#//#5000.000000
A700#//#50602#//#Asmail Al Omer #//#+90394959294#//#50000.000000
66#//#6#//##//#6#//#6.000000
