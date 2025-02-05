#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cctype>
#include <string>

using namespace std;

bool SEARCH(vector<string> &arr, string s)
{
    return find(arr.begin(), arr.end(), s) != arr.end();
}

string toLower(const string &s)
{
    string lower;
    for (char c : s)
    {
        lower += tolower(c);
    }
    return lower;
}

int main()
{
    string filePath1, filePath2;
    cout << "Enter file path 1: " << endl;
    cin >> filePath1;
    cout << "Enter file path 2: " << endl;
    cin >> filePath2;

    ifstream read1(filePath1), read2(filePath2);

    if (!read1 || !read2)
    {
        cerr << "Error reading files." << endl;
        return 1;
    }

    vector<string> stopWords = {"in", "out", "is", "am", "are", "an", "the", "onto", "a"};
    int unionSize = 0, intersectionSize = 0;
    map<string, int> vector1, vector2;

    string word;

    while (read1 >> word)
    {
        word = toLower(word);

        if (!SEARCH(stopWords, word))
        {
            vector1[word]++;
        }
    }

    while (read2 >> word)
    {
        word = toLower(word);

        if (!SEARCH(stopWords, word))
        {
            vector2[word]++;
        }
    }

    for (const pair<string, int> &entry : vector1)
    {
        unionSize += vector1[entry.first];
        if (vector2.count(entry.first))
        {
            int minFreq = min(entry.second, vector2.at(entry.first));
            intersectionSize += minFreq;
        }
    }

    for (const pair<string, int> &entry : vector2)
    {
        if (!vector1.count(entry.first))
        {
            unionSize += vector2[entry.first];
        }
    }

    double JC = unionSize == 0 ? 0 : static_cast<double>(intersectionSize) / unionSize;

    if (JC == 0)
    {
        cout << "Completely dis-similar, JC value: " << JC << endl;
    }
    else
    {
        cout << "Similar with JC value of: " << JC << endl;
    }

    return 0;
}