#include <iostream>
using namespace std;
main()
{
	int n,min;
		cout<<"Enter a number: ";
		cin>>min;
		if ( min>0 )
		{
			while( true )
			{
			cout<<"Enter a number: ";
			cin>>n;
			if (n<=0)
			{
				break;
			}
			if ( n<min )
			{
				min=n;
			}
			}
		}
		else
		{
			cout<<"Enter a postive number";
			
		}
		cout<<"The minimum number is: "<<min;
}