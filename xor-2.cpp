#include<iostream>
#include<vector>
using namespace std;

int main() {
    int x = 0;

    for(int i=1; i <= 4; i++) {
        x ^= i;
        cout << x << endl;
    }

    vector<int> v = {4,2,1,3};
    cout << endl;

    for(int num:v) {
        x ^= num;
        cout << x << endl;
    }
}