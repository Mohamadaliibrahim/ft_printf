#include <iostream>
using namespace std;
main()
{
	int a[20],pos,val,i,z;
	bool x=0;
	for(i=1;i<=20;i++)
	{
		cout<<"Enter the value of A["<<i<<"]: ";
		cin>>a[i];
	}
	cout<<"enter the value \"Val\": " ;
	cin>>val;
	for(i=1;i<=20;i++)
	{
		if(val==a[i])
		{
			z=i;
			x=1;
		}
		
	}
		if(x==1)
		{
			cout<<"The value is in A["<<z<<"] and it is Pos: "<<z;
		}
		else if(x==0)
		{
			cout<<"NOT FOUND"<<endl<<"Pos= -1";
		}
}