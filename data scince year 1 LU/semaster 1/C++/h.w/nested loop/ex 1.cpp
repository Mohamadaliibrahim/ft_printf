#include <iostream>
#include <cmath>
using namespace std;
main()
{
	float z,s,x,n,j,i,d,f;
	cout<<"Enter the first positive integer N: ";
	cin>>n;
	cout<<"Enter the second positive integer X: ";
	cin>>x;
	s=0;
	z=0;
	for (i=1;i<=n;i++)
	{
		z=pow(x, i);
		for(d=0,f=1,j=1;j<=i;j++)
		{
			f=f*j;
			d+=f;
		} 
		s+=z/f;
	}
	
	cout<<s;
	
	
	
	
	
	
}     