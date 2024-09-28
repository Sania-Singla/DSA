#include<iostream>
using namespace std;

bool linearSearch(int a[], int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==x) return true;
    }
    return false;
}

int main()
{
    int a[10] = {11,1083,269,27,397,197,2793,74,18,1};
    int x;
    bool res1 = linearSearch(a,10,269);
    if(res1) cout<<"'269' exists";
    else cout<<"'269' doesn't exists";
    
    return 0;
}