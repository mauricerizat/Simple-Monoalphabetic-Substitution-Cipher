/*
MONOALPHABETIC SUBSTITUTION CIPHER
*/

#include "header.h"

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
