#include<iostream>
using namespace std;

int power(int x,int i) {
    int p=1;
    for(int j=0;j<i;j++){
        p*=x;
    }
    return p;
}

int evaluate(int a[],int n, int x)
{
    int sum=0;
    //iterative way
    for(int i=0;i<n;i++)
    {   
        sum += a[i] * power(x,i);
    }  
    return sum; 
}

int main(){
    int a[5] = {1,2,3,4,5};
    int x;
    cout<<"enter the value of x = ";
    cin>>x;
    int sum = evaluate(a,5,x);
    cout<<"The sum is = "<<sum;
}