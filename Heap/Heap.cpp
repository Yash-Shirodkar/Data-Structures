#include <iostream>
//#include <string.h>
using namespace std;
const int MAX=20;
class heap
{
private:
	int arr[MAX];
	int copy[MAX];
	int n;

public:
	
	heap()
	{
		for(int i=0;i<MAX;i++)
		{
			arr[i]=-1;
		}
		
		for(int i=0;i<MAX;i++)
		{
			copy[i]=999;
		}
		
	}

	void getdata()
	{
		int i;
		cout<<"\nEnter Total Numbers Of Students : ";
		cin>>n;
		arr[0]=n;
		copy[0]=n;
		cout<<"\n\nEnter Marks Of "<<n<<" Students : \n";
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
			copy[i]=arr[i];
		}
	}
		
	
	void maximum()
	{
		int p=n/2,i,l,r,m,temp,j;
		
		for(i=p;i>=1;i--)
		{
			l=arr[i*2];
			r=arr[i*2+1];
			
			m=max(l,r);
			
			if(m==l)
			{
				j=i*2;
			}
			
			if(m==r)
			{
				j=i*2+1;
			}
			
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
				
		}
		
		cout<<"\nMaximum Marks Are : "<<arr[1];
	}
	
	int max(int a,int b)
	{
		if(a>b)
		return a;
		return b;
	}
	
	void minimum()
	{
		int p=n/2,i,l,r,m,temp,j;
		
		for(i=p;i>=1;i--)
		{
			l=copy[i*2];
			r=copy[i*2+1];
			
			m=min(l,r);
			
			if(m==l)
			{
				j=i*2;
			}
			
			if(m==r)
			{
				j=i*2+1;
			}
			
			if(copy[i]>copy[j])
			{
				temp=copy[i];
				copy[i]=copy[j];
				copy[j]=temp;
			}
				
		}
		
		cout<<"\nMinimum Marks Are : "<<copy[1];
	}
	
	int min(int a,int b)
	{
		if(a<b)
		return a;
		return b;
	}
	
};

int main()
{
	heap obj;
	char choice1;
	//char name[30];
	int choice;

	do
	{
			cout<<"\n1.Insert";
			cout<<"\n2.Find Maximum Marks ";
			cout<<"\n3.Find Minimum Marks ";
			cout<<"\n\nEnter Your Choice : ";
			cin>>choice;

			switch(choice)
			{
				case 1:
				obj.getdata();
				break;

				case 2:
				obj.maximum();
				break;

				case 3:
				obj.minimum();
				break;

				default:
				cout<<"\nWrong Choice";
                                 break;
			}
			cout<<"\n\nDo You Want To Again Execute The Program (Yes=Y OR No=N): ";
			cin>>choice1;
	}
	while(choice1=='Y'||choice1=='y');

	return 0;
}

