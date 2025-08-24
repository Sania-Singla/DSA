#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
    vector<int> v = {11, 9, 10, 8, 12, 13};
    priority_queue<int> pq(v.begin(), v.end());
        pq.push(15);

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}