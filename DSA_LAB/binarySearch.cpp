#include<iostream>
using namespace std;

bool binarySearch(int a[], int n, int x)
{
    //iterative way
    int low=0;
    int high=n-1;
    if(low == high) {   //will ran only once in the beginning
        if(a[low]==x) return true;
        else return false;
    } 
    while(low<high)  //or !=
    {
        int mid=(low+high)/2;
        if(a[mid]==x) return true;
        else if(a[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return false;
}

int main()
{
    //although same procedure for both types of arrays
    int even[6] = {104,201,310,802,1071,8918};   //array must be sorted;
    int odd[5] = {3,14,100,686,1700};
    int resEven = binarySearch(even,6,1071);
    int resOdd = binarySearch(odd,5,686);
    if(resEven) cout<<"'1071' exists";
    else cout<<"'1071' doesn't exists";
    cout<<endl;
    if(resOdd) cout<<"'686' exists";
    else cout<<"'686' doesn't exists";

    return 0;
}