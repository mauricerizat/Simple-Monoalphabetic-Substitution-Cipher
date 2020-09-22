/*
MONOALPHABETIC SUBSTITUTION CIPHER
*/

#include "header.h"

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
	ifstream readFile("data/" + plainFile);
	if (!(readFile.is_open())) //Plaintext file cannot be opened or does not exist
	{
		cout << "\nFile named \"" << plainFile;
		cout << "\" cannot be opened or does not exist.";
		cout << "\nPlease try again with a valid file name." << endl;
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
	writeFile.open ("data/" + cipherFile);
	writeFile << cipher << endl;
	writeFile.close();
	
	cout << "\nCiphertext successfully written to file \"" << cipherFile << "\"" << endl;
}
