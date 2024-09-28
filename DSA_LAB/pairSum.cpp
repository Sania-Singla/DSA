#include<iostream>
using namespace std;

void pairSumElements(int a[], int n, int s)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==s) cout<<a[i]<<" & "<<a[j]<<endl;
        }
    }
}

int main()
{
    int a[10] = {11,1083,269,27,397,7,5,74,18,1};
    int s;
    cout<<"enter the sum = ";
    cin>>s;
    pairSumElements(a,10,s);
    
    return 0;
}