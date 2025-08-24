#include <iostream>
#include <queue>
using namespace std;

class Add
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int operator () (int a) {
        return --a;
    }

    int operator + (int a ) {
        return a + 5;
    }
};

main()
{
    priority_queue<int> pq;
    Add a;               // instantite
    cout << a.add(3, 4) << endl; // call a member function
    cout << a(7) << endl;
    cout << a + 7  << endl; // call operator overloading
}