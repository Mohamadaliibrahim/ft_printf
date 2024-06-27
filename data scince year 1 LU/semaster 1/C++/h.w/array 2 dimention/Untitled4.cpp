#include <iostream>
using namespace std;
main()
{
	int n1,n2,i,j;
	cout<<"Enter the value of the row dimention of matrix A: ";
	cin>>n1;
	cout<<"Enter the value of the column dimention of matrix A: ";
	cin>>n2;
	int a[n1][n2];int b[n1][n2];int c[n1][n2];
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<"Enter the value of A["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<"Enter the value of B["<<i<<"]["<<j<<"]: ";
			cin>>b[i][j];
		c[i][j]=b[i][j]+a[i][j];
		}
	}
	cout<<endl<<endl<<"B: \n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<b[i][j]<<"\t";
		}
		cout<<endl;
	}	
	cout<<"\n\n+\n\nA: \n";
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<"C: \n";	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
}