//finding the single missing no. in a natural no. sorted array 
//it will have bugs when multiple elements are missing 
#include<iostream>
using namespace std;

void missingElement(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int check1= a[i] & 1 ;  //if true => odd no. else even no.(because first bit decides weather even no. or odd)
        int check2= a[i+1] & 1 ;
        if(check1 == check2)
        {
            cout<< (a[i] + a[i+1])/2 ;
        }
    }
}

int main()
{
   int a[5] ={10,11,12,14,15};
   missingElement(a,5);

   return 0;
}