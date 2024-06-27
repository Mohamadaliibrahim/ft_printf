#include <iostream>
using namespace std;
main()
{
	int n,x,i;
	x=0;
	cout<<"Enter a postive integer: ";
	cin>>n;
	if (n<=0)
	{
		cout<<"positive number needed!";
	}
	else 
	{
		for(i=1;i<=n/2;i++)
		{
			if (n%i==0)
			{
				x+=i;	
			}
		}
		if (x==n)
		{
			cout<<n<<" is a perfect number";
		}
		else 
		{
			cout<<n<<" is not a perfect number";
		}
	}
}