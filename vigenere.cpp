//Amaris Efthimou
//CSCI 136
//Melissa Lynch
//Lab 6C
//Shifts each letter by a different value
#include <iostream>
using namespace std;
string encryptVigenere(string plaintext, string keyword);
int main()
{
    string plaintext;
    string keyword;
    cout << "Enter plaintext: " << endl;
    getline(cin, plaintext);
    cout << "Enter keyword:" << endl;
    cin >> keyword;
    cout << "Cyphertext: " << encryptVigenere(plaintext, keyword) << endl;
    return 0;
}
string encryptVigenere(string plaintext, string keyword){
    string ans = "";
    char c;
    int n;
    int num = 0;
    for (int i = 0; i < plaintext.length(); i++){
        c = plaintext[i];
        if(c >= 'A' && c <= 'Z') {
           n = keyword[num] - 'a';
           num = (num+1)%keyword.length();//upper case shift
           c = 'A' + (c-'A'+n+26)%26;
        }
        if(c >= 'a' && c <= 'z'){//shifts lowercase characters up the alphabet
        n = keyword[num] - 'a';//the n-th letter of the alphabet will shift by n − 1 to the right
        num = (num+1)%keyword.length();
        c = 'a' + (c -'a'+n+26)%26;
        }
        ans = ans + c;//add values
     }
    return ans;//return the string
}