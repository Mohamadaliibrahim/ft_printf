#include <iostream>
using namespace std;
main()
{
	int n,s;
	
	do
	{
		cout<<"Enter a value: ";
		cin>>n;
		s+=n;
	}while(s<100);
	cout<<"FINISHED";
}