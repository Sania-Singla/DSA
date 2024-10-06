#include<iostream>
using namespace std;

bool isPallidrome(string s, int i, int j) {
    if(i>j) return true;
    else {
        if(s[i]!=s[j]) return false; 
        return isPallidrome(s, ++i, --j);
    }
}

int main() {
    string s = "ahhaahha";
    if(isPallidrome(s,0,s.length()-1)) cout << "pallidrome" << endl;
    else cout << "not a pallidrome" << endl;
}