#include "CipherTest.h"
#include "SimpleCipher.h"
#include "../helper/TestHelper.h"
#include <map>
#include <iostream>

string testEncryptionKey()
{
	string results;
	map<char, char> actual = getEncryptionKey();
	results += checkEquals(actual.size(), 52, "n/a", "The encryption key should have 52 entries");

	int THRESHOLD = 3; // The number that is OK to be the same since it is randomly selected
	int same = 0;
    for (const pair<char, char>& entry : actual)
	{
		if (entry.first == entry.second)
		{
			same = same + 1;
		}
	}
	results += checkFalse(same > THRESHOLD, "n/a", "Your map should have fewer than " + to_string(THRESHOLD) + " unciphered letters but you had " + to_string(same));


	return results;
}

string testDecryptionKey()
{
	string results;
	map<char, char> key = getEncryptionKey();
	map<char, char> actual = getDecryptionKey();
	results += checkEquals(actual.size(), 52, "n/a", "The decryption key should have 52 entries");
	results += checkEquals(actual.size(), key.size(), "n/a", "The two key should have the same number of entries");

    for (const pair<char, char>& entry : actual)
	{
    	results += checkEquals(string(1, entry.first), string(1, key[entry.second]), string(1, entry.second), "The two keys do not match");
    	if (results.size() > 0)
    	{
    		break;
    	}
	}
	return results;
}

string testEncryptDecrypt()
{
	string results;
	string phrases[] = {"Hello Maps", "Map=Dictionary=Symbol Table",
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

	for (string phrase : phrases)
	{
		string actual = encrypt(phrase);
		results += checkFalse(actual == phrase, phrase, "The original phrase is unchanged");
		results += checkEquals(decrypt(actual), phrase, actual, "The decrypted text did not return to the original phrase - ");
	}

	return results;
}

string runCipherTest(string subtest)
{
	string results;
	setup();

	if (subtest == "all")
	{
		results += testEncryptionKey();
		results += testDecryptionKey();
		results += testEncryptDecrypt();
	} else if (subtest == "key") {results += testEncryptionKey();}
	else {results += "Invalid Subtest";}

    return results;
}
