/*
MONOALPHABETIC SUBSTITUTION CIPHER
*/

#include "header.h"

//Main Function
int main ()
{
	cout << "\nWelcome to Monoalphabetic Substitution Cipher Program " << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "\nGeneration of Key: " << endl;
	
	//KEY GENERATION
	
	string key; //Stores Key
	bool keyDone = false; //Flag to check if key has been successfully generated
	
	do //Program will loop in case of wrong Keyword entry
	{
		string keyWord = ""; //Stores Keyword
		cout << "\nEnter Keyword: "; // Recieving Keyword from user
		getline(cin, keyWord);
		
		key = keygen (keyWord); //Converting Keyword to key
		
		if (key == "111") //Return code for Keyword containing non-alphabetical character(s)
		{
			cout << "Error: Keyword must only contain alphabet characters. Please Try Again" << endl;
			continue;
		}
		
		keyDone = true; //Key has been successfully generated

	}while(keyDone == false);
	
	cout << "\nKey successfully generated. Key is: " << key << endl;
	
	//Menu for selecting Encryption or Decryption
	string optionInput = ""; //Stores menu input
	int option; //Stores option
	bool exit = false; //Return to menu flag
	do
	{
		do
		{
			//Menu choices
			cout << "\n--------------------------------------------------------------" << endl;
			cout << "\nSelect operation to perform: \n" << endl;
			cout << "\t1. Encryption, \n\t2. Decryption, \n\t3. Exit " << endl;
			cout << "\nYour choice: ";
			cin >> optionInput;
			cin.clear(); //Choice input reads and checks only first character of input
			cin.sync();
			
			if(optionInput[0] > 48 && optionInput[0] <= 57)
			{
				option = stoi (optionInput);
				break;
			}
			else
				cout << "\nChoice input must be an Integer. Please try again." << endl;
			
			
		}while(true); //Repeat in case of non-numerical input
		
		//Choice effect
		switch (option)
		{
			case 1: //ENCRYPTION
				encrypt (key);
				break;
			
			case 2:	//DECRYPTION
				decrypt(key);
				break;
				
			case 3: exit = true; //Exit program
				break; 
			
			default: cout << "\nWrong input. Please try again" << endl;
		}
		
		if (exit == true)
			break;
					
		cout << "\n--------------------------------------------------------------" << endl;
		char yn;
		
		cout << "\nReturn to Menu? Y|N : "; //Choice to return to menu
		cin >> yn;
		
		if (yn == 'n' || yn == 'N')
			exit = true;
		
	}while (exit == false); //If repeat, program will return to menu
	
	cout << "\n--------------------------------------------------------------" << endl;
	cout << "Thank you for using the program" << endl;
}














