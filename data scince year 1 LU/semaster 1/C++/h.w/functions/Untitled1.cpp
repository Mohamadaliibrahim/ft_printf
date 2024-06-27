#include <iostream>
float avarage( float n1,float n2)
{
	return (n1+n2)/2.0;
}
using namespace std;
main()
{
	float k,x,y;
	cout<<"Enter the first number: ";
	cin>>x;
	cout<<"Enter the second number: ";
	cin>>y;
	k=avarage(x,y);
	cout<<"the arithmetic mean of two real numbers is: "<<k;
}