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

double MAG(map<string, int> &map)
{
    int sum = 0;
    for (const pair<string, int> &entry : map)
    {
        sum += entry.second * entry.second;
    }
    return sqrt(sum);
}

double DP(map<string, int> &map1, map<string, int> &map2)
{
    int sum = 0;
    for (const pair<string, int> &entry : map1)
    {
        if (map2.count(entry.first))
        {
            sum += entry.second * map2.at(entry.first);
        }
    }
    return sum;
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
    vector<string> vocab;
    
    map<string, int> vector1, vector2;

    string word;

    while (read1 >> word)
    {
        word = toLower(word);

        if (!SEARCH(stopWords, word))
        {
            vector1[word]++;

            if (!SEARCH(vocab, word))
            {
                vocab.push_back(word);
            }
        }
    }

    while (read2 >> word)
    {
        word = toLower(word);

        if (!SEARCH(stopWords, word))
        {
            vector2[word]++;

            if (!SEARCH(vocab, word))
            {
                vocab.push_back(word);
            }
        }
    }

    // read1.clear();
    // read2.clear();
    // read1.seekg(0, ios::beg);
    // read2.seekg(0, ios::beg);

    // for (int i = 0; i < vocab.size(); i++)
    // {
    //     vector1[vocab[i]] = 0;
    //     vector2[vocab[i]] = 0;
    // }

    // while (read1 >> word)
    // {
    //     if (SEARCH(vocab, word))
    //     {
    //         vector1[word]++;
    //     }
    // }

    // while (read2 >> word)
    // {
    //     if (SEARCH(vocab, word))
    //     {
    //         vector2[word]++;
    //     }
    // }

    double magnitude1 = MAG(vector1);
    double magnitude2 = MAG(vector2);
    double dotProduct = DP(vector1, vector2);

    double cosine = (magnitude1 * magnitude2 == 0) ? 0 : dotProduct / (magnitude1 * magnitude2);

    if (cosine == 0)
    {
        cout << "Completely dis-similar, cosine value: " << cosine << endl;
    }
    // else if (cosine == 1) // won't work because of double == int (can't even use non-strict equality)
    // {
    //     cout << "completely similar, cosine value: " << cosine << endl;
    // }
    else
    {
        cout << "Similar with cosine value of: " << cosine << endl;
    }

    return 0;
}