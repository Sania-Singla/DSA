#include<iostream>
using namespace std;

int power(int x,int i) {
    int p=1;
    for(int j=0;j<i;j++){
        p*=x;
    }
    return p;
}

int evaluate(int a[], int n, int i, int x)   //'i' is for current index tracking 
{
    //recursive way 
    if(i > n) return 0;  
    else return (a[n-i]*power(x,n-i) + evaluate(a,n,i+1,x));
}

int main()
{
   int a[5]= {17,82,5,2,24} ;
   int x;
   cout<<"enter x = ";
   cin>>x ;
   cout<<"The sum is = "<<evaluate(a,5,1,x);

   return 0;
}