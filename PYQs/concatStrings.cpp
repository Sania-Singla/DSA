#include<iostream>
using namespace std;

string insert(string original, string insertWord) {
    string result = "";
    int i=0;
    
    while(original[i] != ' ' && original[i] != '\0') {
        result += original[i++];
    }

    if(original[i] == ' ') {
        result += ' ';
        result += insertWord;
    }

    while(original[i] != '\0') {
        result += original[i++];
    }

    return result;
}

int main() {
    string original = "Punjab Chandigarh, UIET";
    string insertWord = "University";
    string result = insert(original, insertWord);
    cout << result << endl;
}