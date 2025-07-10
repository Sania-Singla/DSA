#include <iostream>
#include <string>

using namespace std;

string cypher(string s, int x)
{
    string cs;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i + 1] == '*')
        {
            cs += to_string((int)s[i] - 96 + x);
        }
        else if (s[i] == '*')
        {
            continue;
        }
        else
        {
            cs += to_string((int)s[i] - 96);
        }
    }
    return cs;
}

int main()
{
    string s = "a*cz*bc";
    int x = 10;
    cout << cypher(s, x);
    return 0;
}