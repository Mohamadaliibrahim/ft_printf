#include <iostream>
using namespace std;
main()
{
int t[20],i,x,z,y,g;
for(i=0;i<20;i++)
	{
		cout<<"Enter T["<<i<<"]: ";	
		cin>>t[i];
	}
	for(i=0,x=t[0],y=t[0];i<20;i++)
	{
		if(t[i]>x)
		{
			x=t[i];
			z=i;
		}
		else if(t[i]<y)
		{
			y=t[i];
			g=i;
		}
	}
	cout<<"The largest value is: "<<x<<" and the smallest value is: "<<y;
	cout<<"\nThe position of the largest value is: "<<z<<" and the position of the smalest value is: "<<g;
	
}