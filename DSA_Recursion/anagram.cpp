// anagrams strings have same length and same set of alphabets in same frequency but in diff order

#include<iostream>
using namespace std;

bool anagrams(string s1, string s2) {
    if(s1.length() != s2.length()) return false;

    int freq1[26] = {0};   // array with all values to be 0
    int freq2[26] = {0};

    for(int i=0; i<s1.length(); i++) {
        freq1[tolower(s1[i]) - 'a']++;    // will update the frequency at that index
        freq2[tolower(s2[i]) - 'a']++;
    }

    for(int i=0; i<26; i++) {
        if(freq1[i] != freq2[i]) return false;
    }

    return true;
}

int main() {
    string s1 = "Decimal";
    string s2 = "mediCal";
    if(anagrams(s1, s2)) cout << "anagram" << endl;
    else cout << "not anagram" << endl;
}