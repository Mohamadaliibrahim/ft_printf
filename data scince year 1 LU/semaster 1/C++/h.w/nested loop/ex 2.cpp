#include <iostream>
using namespace std;
main()
{
	int n,i,x;
	do
	{
		cout<<"Enter an integer value: ";
		cin>>n;
		cout<<"The devisors of "<<n<<" are: ";
		for(i=1;i<=n;i++)
		{
			if(n%i==0)
			{
				cout<<i<<" ";
			}
		}cout<<endl;
	}while(n>0);
	
	cout<<"goodbye!";
}