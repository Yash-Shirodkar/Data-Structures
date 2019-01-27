#include<iostream>
using namespace std;
class Sort
{
	public:
	void quick(float *c,int start,int end);
	int partition(float *c,int start,int end);
};
void Sort::quick(float *c,int start,int end)
{
	int pindex;
	if(start<end)
	{
		pindex=partition(c , start, end);
		quick(c,start,pindex-1);
		quick(c,pindex+1,end);
	}
}
int Sort::partition(float *c,int start,int end)
{
	int pivot=c[end];
	int pindex=start;
	for(int i=start;i<end;i++)
	{
		if(c[i]<=pivot)
		{
			float temp;
			temp=c[pindex];
			c[pindex]=c[i];
			c[i]=temp;
			pindex++;
		}
	}
	float temp;
	temp=pivot;
	c[end]=c[pindex];
	c[pindex]=temp;
	return pindex;
}
int main()
{
	Sort s;
	int t,z;
	char c;
	do
    {
        cout<<"\nENTER NUMBER OF STUDENTS";
        cin>>t;
        z=t-6;
        cout<<"ENTER THE PERCENTAGE OF STUDENTS:-"<<endl;
        float d[100];
        for(int i=0;i<t;i++)
        {
            cin>>d[i];
        }
        s.quick(d,0,t-1);
        cout<<"THE PERCENTAGE OF STUDENTS IN SORTED ORDER ARE:-"<<endl;
        for(int i=0;i<t;i++)
        {
			cout<<d[i]<<endl;
        }
        cout<<"AND THE FIRST FIVE TOP SCORERS ARE:-"<<endl;
        int cnt=0;
        for(int i=t-1;i>z;i--)
        {
            cnt++;
            if(cnt>5)
            {
                break;
            }
            cout<<d[i]<<endl;
        }
        cout<<"DO YOU WANT TO CONTINUE??"<<endl;
        cout<<"ENTER y or n"<<endl;
        char c;
        cin>>c;
    }while(c=='y');

}
