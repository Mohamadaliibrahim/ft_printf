#include <iostream>
#include <cmath>

using namespace std;
main()

{

int a,b,c;
float d,x,x1,x2,y;
cout<<"Write a: ";
cin>>a;
cout<<"Write b: ";
cin>>b;
cout<<"Write c: ";
cin>>c;
d=pow(b, 2)-4*a*c;

if (a==0)
{
	x=-c/b;
	cout<<x;
}
if( a==0&&b==0 )
{
	cout<<"no real solution";

 if(a==0&&b==0&&c==0)

	cout<<"no real solution";
}
if(d==0)
{
	x=-b/2*c;
	cout<<"there is one double solution: "<<x;
}
if(d<0)
{
	cout<<"no real solution since d is negative";
}
if(d>0)
{
	x1=((-b)+sqrt(d))/(2*a);
	x2=((-b)-sqrt(d))/(2*a);
	cout<<"There is two real solutions that are \nx1= "<<x1<<"\nand\nx2= "<<x2;
}

}
