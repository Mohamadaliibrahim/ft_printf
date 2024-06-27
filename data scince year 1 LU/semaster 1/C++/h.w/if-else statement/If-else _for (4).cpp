#include <iostream>
using namespace std;
main()
{
	int n,i,x,y;
	cout<<"Enter a positive number N: ";
	cin>>n;
	if(n<=0)
	{
		cout<<"Eror enter a positive number!";
	}
	else
	{
		cout<<"enter number 1: ";
			cin>>y;
		for (i=2;i<=n;i++)
		{
			cout<<"enter number "<<i<<": ";
			cin>>x;
			if (y<x)
			{
				y=y;
				x=y;
			}
			else if (x<y)
			{
				y=x;
			}
		
		}cout<<"minimum value is "<<y;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
