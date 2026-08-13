#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

string cleanWord(string word)
{
    string result = "";
    for(char c : word)
    {
        if(isalpha(c))
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    string sent;
    cout<<"Enter Sentence: ";
    getline(cin, sent);
    string word,max_word;
    int max_len = 0;
    stringstream ss(sent);

    while(ss >> word)
    {
        string cleand = cleanWord(word);
        if(cleand.length() > max_len)
        {
            max_len = cleand.length();
            max_word = cleand;
        }
    }

    cout<<"Max Char: "<<max_len<<endl;
    cout<<"word: "<<max_word;
    return 0;
}