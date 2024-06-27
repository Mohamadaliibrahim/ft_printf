#include <iostream>
float min(float n1,float n2)
{
	if(n1<n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}
using namespace std;
main()
{
	int n,k;
	do
	{
		cout<<"Enter an integer N: ";
		cin>>n;
	}while (n<=0);
	int x;
	cout<<"Enter the 1 number: ";
	cin>>x;
	for(int i=2;i<=n;i++)
	{
		int z;
		cout<<"Enter the"<<i<<"number: ";
		cin>>z;
		k=min(z,x);
	}
	cout<<"\nThe minimum number is: "<<k;
	
}