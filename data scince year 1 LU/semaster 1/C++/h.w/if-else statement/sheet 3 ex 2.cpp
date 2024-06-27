#include <iostream>
#include <cmath>
using namespace std;
main()
{
	float n,i,s,x,y;s=0.0;
	cout<<"Enter a positive integer: ";
	cin>>n;
	if (n>0)
	{
		for (i=1;i<=n;++i)
		{
			s+=(i=3)/(i*i-5);
		}
	
		cout<<"The results are: "<<s;
}
	
	else if (n<=0)
	{
		cout<<"Enter a postive number";
		
	}
}