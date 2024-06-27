#include <iostream>
using namespace std;
main()
{
	int n;
	cout<<"Enter an integer postive value n: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<"# ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int z=1;z<=n;z++)
	{
		for(int y=1;y<=n-z+1;y++)
		{
			cout<<"# ";
		}
		cout<<endl;
	}
}