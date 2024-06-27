#include <iostream>
using namespace std;
main()
{
int a,b,c,x,y,z,w;
cout<<"Write first number= ";
cin>>a;
cout<<"Write second number= ";
cin>>b;
cout<<"Write third number= ";
cin>>c;

if (a<b&&b<c)
{
	cout<<"value A <= value B <= value C"<<endl<<a<<"<="<<b<<"<="<<c;
}
else if (a>b&&b>c)
{
	x=c;
	c=a;
	a=x;
		cout<<"value A <= value B <= value C"<<endl<<a<<"<="<<b<<"<="<<c;
}
else if ( a>b&&c>b&&a>c )
{
	x=a;
	z=c;
	a=b;
	b=x;
	c=b;
	b=z;
		cout<<"value A <= value B <= value C"<<endl<<a<<"<="<<b<<"<="<<c;
	
}
else if ( a>b&&c>b&&a<c )
{
	x=a;
	a=b;
	b=x;
		cout<<"value A <= value B <= value C"<<endl<<a<<"<="<<b<<"<="<<c;
	
}
else if ( a<b&&c<b&&a>c )
{
	x=c;
	c=b;
	b=x;
	z=a;
	a=b;
	b=z;
	
		cout<<"value A <= value B <= value C"<<endl<<a<<"<="<<b<<"<="<<c;
	
}

else if (a==b&&b==c)
{
	cout<<"The three numbers have the same value A = B = C "<<endl<<a<<"="<<b<<"="<<c;
}











}
