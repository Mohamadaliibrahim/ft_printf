#include <iostream>
using namespace std;
main()
{
	int n,i;
	float t[50],h[50],x,y,z;
	do
	{
		cout<<"Enter an integer (0<N<=50): ";
		cin>>n;
	} while(n<=0 || n>50);
	
	cout<<"\nEnter T["<<i<<"]: ";
		for(i=0;i<n;i++)
		{
			cin>>t[i];
		}
		cout<<"\nEnter H["<<i<<"]: ";
		for(i=0;i<n;i++)
		{
			cin>>h[i];
		}
	for(i=0;i<n;i++)
	{
		z+=t[i]*h[i];
	}
	cout<<"The results are: "<<z;

}