#include <map>
#include <string>
#include <vector>
using namespace std;

vector<char> setup();

map<char, char> getEncryptionKey();
map<char, char> getDecryptionKey();

string encrypt(string message);
string decrypt(string ciphered);
