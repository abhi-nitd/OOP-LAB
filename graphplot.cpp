#include<iostream>
#include<iomanip>
#include<cmath>
#define pi 3.14
using namespace std;

int main()
{	
	int i,k;
	i=0;
	float f;
	float count=0.0;
	int l;
	cout<<"Enter the multiple of pi";
	cin>>l;

	for(count=0;count<l*pi;count+=0.1)
	{
		f=sin(count);
		i++;
	}
	count=0.0;	
	for(int j=0;j<=i;j++)
	{
		
		f=sin(count);
		
		if (f>0)
		{

			cout<<"\t\t\t\t "<<fixed << setprecision(1)<<count<<" ";
			cout<< setfill('*')<<setw(f*30);
		}
		if(f<0)
		{
			k=36-(abs(f*30));
			for(int i=0;i<=k;i++)
			{
				cout<<" ";
			}
			
			cout<<setfill('*')<<setw(abs(f*30));	
			cout<<fixed << setprecision(1)<<count<<" ";
		}
		count+=.1;

	
	cout<<"\n";
	}
}