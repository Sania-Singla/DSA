#include <iostream>
using namespace std;

void swap(char &a, char &b) {
    char temp;
    temp = b;
    b = a;
    a = temp;
}

// iterative
// void reverse(string &s) {
//     for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
//         swap(s[i],s[j]);
//     }
// }

// recursive
void reverse(string &s, int i) {
    int j = s.length()-i-1;
    if(i>=j) return ;
    else {
        swap(s[i],s[j]);
        i++;
        return reverse(s, i);
    }
}

int main () {
    string s = "sania";
    reverse(s, 0);
    cout << "reverse = " << s << endl;
}