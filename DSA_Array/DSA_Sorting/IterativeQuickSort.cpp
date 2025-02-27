#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void print(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << "\t";
    }
    cout << endl;
}

int partition(vector<int> &arr, int low, int high)
{

    int i = low, j = high, pivot = arr[low];
    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

// best or avg case S(logn) & worst case S(2) => S(1);
// S(n) = S(n/2) + 2; (Master's method => logn)
void iterativeQS(vector<int> &arr, int low, int high)
{
    stack<int> s;
    while (true)
    {
        while (low < high)
        {
            int p = partition(arr, low, high);
            int len1 = p - low, len2 = high - p;

            if (len1 >= len2)
            {
                s.push(p - 1);
                s.push(low);
                low = p + 1;
            }
            else
            {
                s.push(high);
                s.push(p + 1);
                high = p - 1;
            }
        }

        if (!s.empty())
        {
            // low baad mein push kiya tha so on top
            low = s.top();
            s.pop();
            high = s.top();
            s.pop();
        }
        else
        {
            return;
        }
    }
}

int main()
{
    vector<int> arr = {6, 5, 4, 3, 2, 1, 1};
    iterativeQS(arr, 0, arr.size() - 1);
    print(arr);
}