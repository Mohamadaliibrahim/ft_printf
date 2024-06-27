#include <iostream>
using namespace std;
int main ()
{

float A,B,C,U,U1,U2,U3,S,n,i;
U1=-1;
U2=1;
U3=2;
A=-1;
B=1;
C=2;
S=0;
cout<<"Enter the value of n: n= ";
cin>>n;
for (i=2;i<=n-3;i++)
{U=2*A-5*B+C+2;
C=B;
B=A;
A=U;
S=S+U;}
cout<<"S= "<<S;
if (n>3)
cout<<"\nThe value of U: U = "<<U;
else
{if (n==1)
cout<<"The value of U is equal to -1";
if (n==2)
cout<<"The value of U is equal to 1";
if (n==3)
cout<<"The value of U is equal to 2";
}
}

