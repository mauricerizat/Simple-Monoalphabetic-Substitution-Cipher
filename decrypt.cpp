/*
MONOALPHABETIC SUBSTITUTION CIPHER
*/

#include "header.h"

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
	ifstream readFile("data/" + cipherFile);
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
	writeFile.open ("data/" + plainFile);
	writeFile << plain << endl;
	writeFile.close();
	
	cout << "\nPlaintext successfully written to file \"" << plainFile << "\"" << endl;
}
