#include "SimpleCipher.h"
#include <vector>
#include <iostream>
#include<map>

map<char, char> key;
map<char, char> decryptKey;

vector<char> setup()
{
	vector<char> alpha;
	for (char c = 'a'; c <= 'z'; c++)
	{
		alpha.push_back(c);
	}
	for (char c = 'A'; c <= 'Z'; c++)
	{
		alpha.push_back(c);
	}
	return alpha;

}

map<char, char> getEncryptionKey()
{
	vector<char> temp= setup();
	int size = temp.size();

	for (int i=0; i<size; i++)
	{
		int temp2=temp[(i+10) % size] ;
		key[temp[i]] = temp2;
	}
	return key;
}

map<char, char> getDecryptionKey()
{
	vector<char> temp= setup();
	int size = temp.size();

	for (int i= 0; i<size; i++)
	{
		decryptKey[temp[(i+10) % size]]= temp[i];
	}
	return decryptKey;
}

string encrypt(string message)
{
	map<char, char> key= getEncryptionKey();
	string save;
	int size = message.size();

	for (int i= 0; i < static_cast<int>(size); i++)
	{
		char alph = message[i];
		if((alph >= 97 && alph <= 122) || (alph <= 90 && alph >= 65))
		{
			save= save + key[message[i]];
		}
		else
		{
			save= save + message[i];
		}
	}
	return save;
}

string decrypt(string ciphered)
{
	map<char, char> decryptKey= getDecryptionKey();
	string save;
	int size= ciphered.size();

	for (int i= 0; i < static_cast<int>(size); i++)
	{
		char alph = ciphered[i];
		if((alph >= 97 && alph <= 122) || (alph <= 90 && alph >= 65))
		{
			save = save + decryptKey[ciphered[i]];
		}
		else
		{
			save= save + ciphered[i];
		}
	}
	return save;
}
