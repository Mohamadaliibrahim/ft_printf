#include <iostream>
using namespace std;
main()
{
int n,a,b,c,d,x,y,z,j;
cout<<"Write four digets number= ";
cin>>n;
a=n/1000;
z=n%1000;
b=z/100;
j=n%100;
c=j/10;
d=n/10;
d=n%10;

x=a+b;
y=c+d;
if (x==y)
{
	cout<<"the numbers "<<a<<b<<c<<d<<" are lucky numbers since "<<a<<"+"<<b<<"="<<c<<"+"<<d<<"="<<x;
}
else if (x!=y)
{
	cout<<"The numbers "<<a<<b<<c<<d<<" are not a lucky numbers since "<<a<<"+"<<b<<"!="<<c<<"+"<<d;
}





}
