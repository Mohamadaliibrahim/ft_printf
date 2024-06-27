#include <iostream>
using namespace std;
main()
{

float x,y,z,i;
	for ( i=1;i<=20;i++ )
	{
		
			
			cout<<"Enter the value of the 20 consumed energy: "<<endl;
			cout<<"enter the value for energy "<<i<<": ";
			cin>>x;
			
			if ( x<50 )
			{	
			y=x*0.5;
			z=y+y*0.11;
				cout<<"The bill without VAT is "<<y<<"$, and the bill with VAT is "<<z<<"$"<<endl<<endl;
			}
			
			else if (x>=50)
			{
			y=x*0.75;
			z=y+y*0.11;	
				cout<<"The bill without VAT is "<<y<<"$, and the bill with VAT is "<<z<<"$"<<endl<<endl;
			}
	
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
