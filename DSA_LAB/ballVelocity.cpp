#include<iostream>
using namespace std;

int ballVelocityDrops(int v)
{
    int drops= 0; //no. of times ball touched the ground
    while(v)
    {
       v /= 2 ; //velocity decreases to half every time
       drops++ ; //counting the drops until v=0
    }
    return drops;
}

int main()
{
   int v;
   cout<<"enter the initial velocity = ";
   cin>>v;
   int drops = ballVelocityDrops(v) ;
   cout<<"drops = "<<drops;

   return 0;
}