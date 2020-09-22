/*
MONOALPHABETIC SUBSTITUTION CIPHER
*/

#include <iostream>
#include <string>
#include <fstream>
#include<ios>      
#include<limits>  

using namespace std;

string keygen (string);
void encrypt (string);
void decrypt (string);

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

//Function to generate Key
string keygen (string k)
{
	string key = ""; //Stores Key
	
	//Add Keyword to Key
	for (int i = 0; i < k.length(); ++i)
	{		
		if (k[i] > 90)
		{
			k[i] -= 32; //Capitalize all lowercase
		}
		
		if (k[i] < 65 || k[i] > 90) //Check if alphabet
			return "111"; //Return code for Keyword containing non-alphabetical character(s)
		
		if (key.find(k[i]) == string::npos) //Check for duplicates
			key += k[i];						
	}
	
	//Add remaining alphabets to key
	for (int i = 65; i <= 90; ++i)
	{		
		if (key.find((char)i) == string::npos) //Check for duplicates
			key += (char)i;
	}	

	return key;
}

//Function to Encrypt Plaintext
void encrypt (string key)
{
	cout << "\n--------------------------------------------------------------" << endl;
	cout << "ENCRYPTION" << endl;
	
	//Recieving plaintext
	cout << "\nPlaintext file required" << endl;
	string plain = ""; //Stores plaintext
	string plainFile = ""; //Stores plaintext file name
	cout << "Enter Plaintext file name (Include extension if present): ";
	cin >> plainFile;
	
	//Reading from plaintext file
	ifstream readFile(plainFile);
	if (!(readFile.is_open())) //Plaintext file cannot be opened or does not exist
	{
		cout << "\nFile named \"" << plainFile;
		cout << "\" cannot be opened or does not exist.";
		cout << " Please try again with a valid file name." << endl;
		return;
	}
	else //Plaintext file exists
	{	
		cout << "\nReading from plaintext file..." << endl;
		try 
		{
			string line;
			while (getline(readFile, line))
				plain += (line + "\n");
			
			plain = plain.substr(0, plain.size()-1);
		
		readFile.close();
		} 
		catch (exception& e) //Handles errors that occurs during file reading
		{
			cout << "An error occured while reading file. Please try again." << endl;
			return;
		}
		
	}
	
	//Actual Encryption process
	string cipher = ""; //Stores ciphertext
	
	for (int i = 0; i< plain.length(); ++i) //Running through each character of plaintext
	{		
		if (plain[i] >= 65 && plain[i] <= 90) 
			cipher += key[plain[i] - 65]; //Encrypt uppercase letters	
		else if (plain[i] >= 97 && plain[i] <= 122)
			cipher += key[plain[i] - 97] + 32; //Encrypt lowercase letters
		else
			cipher += plain[i]; //Non-alphabetic characters
	}
	
	//Success!
	cout << "\nText successfully encrypted.\n\nCiphertext:\n" << endl;
	cout << cipher << endl;

	
	//Recieving file name for output
	string cipherFile = ""; //Stores output ciphertext file name
	cout << "\nEnter file name to store Ciphertext (Include extension if required): ";
	cin >> cipherFile;
	
	//File writing
	cout << "\nWriting to ciphertext file..." << endl;
	ofstream writeFile;
	writeFile.open (cipherFile);
	writeFile << cipher << endl;
	writeFile.close();
	
	cout << "\nCiphertext successfully written to file \"" << cipherFile << "\"" << endl;
}

//Function to Decrypt Ciphertext
void decrypt (string key)
{
	cout << "\n--------------------------------------------------------------" << endl;
	cout << "DECRYPTION" << endl;
	
	//Recieving ciphertext
	cout << "\nCiphertext file required" << endl;
	string cipher = ""; //Stores ciphertext
	string cipherFile = ""; //Stores ciphertext file name
	cout << "Enter Ciphertext file name (Include extension if present): ";
	cin >> cipherFile;
	
	//Reading from ciphertext file
	ifstream readFile(cipherFile);
	if (!(readFile.is_open())) //Ciphertext file cannot be opened or does not exist
	{
		cout << "\nFile named \"" << cipherFile;
		cout << "\" cannot be opened or does not exist.";
		cout << " Please try again with a valid file name." << endl;
		return;
	}
	else //Ciphertext file exists
	{	
		cout << "\nReading from ciphertext file..." << endl;
		try 
		{
			string line;
			while (getline(readFile, line))
				cipher += (line + "\n");
			
			cipher = cipher.substr(0, cipher.size()-1);
		
		readFile.close();
		} 
		catch (exception& e) //Handles errors that occurs during file reading
		{
			cout << "An error occured while reading file. Please try again." << endl;
			return;
		}
		
	}
	
	//Actual Decryption process
	string plain = ""; //Stores plaintext
	
	for (int i = 0; i < cipher.length(); ++i)
	{
		if (cipher[i] >= 65 && cipher[i] <= 90)
			plain += key.find(cipher[i]) + 65; //Encrypt uppercase letters
		else if (cipher[i] >= 97 && cipher[i] <= 122)
			plain += key.find(cipher[i]-32) + 97; //Encrypt lowercase letters
		else
			plain += cipher[i]; //Non-alphabetic characters
	}
	
	//Success!
	cout << "\nText successfully decrypted.\n\nPlaintext:\n" << endl;
	cout << plain << endl;

	
	//Recieving file name for output
	string plainFile = ""; //Stores output plaintext file name
	cout << "\nEnter file name to store Plaintext (Include extension if required): ";
	cin >> plainFile;
	
	//File writing
	cout << "\nWriting to ciphertext file..." << endl;
	ofstream writeFile;
	writeFile.open (plainFile);
	writeFile << plain << endl;
	writeFile.close();
	
	cout << "\nPlaintext successfully written to file \"" << plainFile << "\"" << endl;
}

/*
//Function to Decrypt Ciphertext
string decrypt (string cipher, string key) 
{
	string plain = ""; //Stores plaintext
	
	for (int i = 0; i < cipher.length(); ++i)
	{
		if (cipher[i] >= 65 && cipher[i] <= 90)
			plain += key.find(cipher[i]) + 65; //Encrypt uppercase letters
		else if (cipher[i] >= 97 && cipher[i] <= 122)
			plain += key.find(cipher[i]-32) + 97; //Encrypt lowercase letters
		else
			plain += cipher[i]; //Non-alphabetic characters
	}
	
	return plain;
}

*/











