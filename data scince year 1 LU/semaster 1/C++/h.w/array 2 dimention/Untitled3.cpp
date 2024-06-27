#include <iostream>
using namespace std;
main()
{
	int r,c;
	cout<<"enter the row dimension: ";
	cin>>r;
	cout<<"enter the column dimension: ";
	cin>>c;
	int a[r][c];
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"Enter A["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	}
	int x;
	double b[r][c];
	cout<<"\nenter X: ";
	cin>>x;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			b[i][j]=a[i][j]*x;
		}
		
	}
	cout<<"\nbefore multiplication:\n";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nafter multiplication: \n";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<b[i][j]<<"\t";
	
		}
		cout<<"\n";
	}
}