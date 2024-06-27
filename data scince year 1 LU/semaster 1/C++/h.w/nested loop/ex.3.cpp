#include <iostream>
using namespace std;
main()
{
	int n,i;
	cout<<"Enter a integer value: ";
	cin>>n;
	if (n<=1)
	{
		cout<<n<<" is not a prime number ";
	}
	else if (n>1)
	{
		cout<<"The prime numbers under "<<n<<" are: "<<endl;
		for(i=2;i<n;i++)
		{	bool prime = 1;
			for(int j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					prime = 0;
					break;
				}
			}
			if (prime)
			{
				cout<<i<<"\t";
			}
		}
		cout<<endl;
	}
		



}