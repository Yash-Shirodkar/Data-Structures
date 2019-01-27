#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10

class Phone
{
	struct node
	{
		unsigned long long num;
		char name[20];
		node *next=NULL;
	};
	node *array[MAX];
	public:
	Phone()
	{
		for(int i=0;i<MAX;i++)
		{
			array[i]=NULL;
		}
	}
	int hashFunction(char name[]);
	void insertRecord();
	void deleteRecord(char name[]);
	void searchRecord(char name[]);
};

void Phone::insertRecord()
{
	char name[20];
	unsigned long long num=0;
	cout<<"Enter Name:";
	cin>>name;
	cout<<"Enter Number:";
	cin>>num;
	int index=hashFunction(name);
	node *trav=array[index];
	node *temp=new node;
	strcpy(temp->name,name);
	temp->num=num;
	if(trav==NULL)
	{
		array[index]=temp;
	}
	else
	{
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=temp;
	}
	cout<<"Inserted!\n";
}

void Phone::searchRecord(char name[])
{
	int index=hashFunction(name);
	node *trav=array[index];
	while(trav!=NULL&&strcmp(trav->name,name))
	{
		trav=trav->next;
	}
	if(trav==NULL)
	{
		cout<<"NOT Found!\n";		
	}
	else
	{
		cout<<trav->name<<" found!\n";
		cout<<"Number:"<<trav->num<<endl;
	}
}

void Phone::deleteRecord(char name[])
{
	int index=hashFunction(name);
	node *trav=array[index];
	if(trav==NULL)
	{
		cout<<"NOT Found\n";
		return;
	}
	if(!strcmp(trav->name,name))
	{
		array[index]=trav->next;
		delete(trav);
		cout<<"Deleted!\n";
		return;
	}
	while(trav->next!=NULL&&strcmp(trav->next->name,name))
	{
		trav=trav->next;
	}
	if(trav->next==NULL)
	{
		cout<<"NOT Found!\n";
		return;
	}
	else
	{
		cout<<trav->next->name<<" found!\n";
		cout<<"Number:"<<trav->next->num<<endl;
		node *temp=trav->next;
		trav->next=trav->next->next;
		cout<<temp->name<<":";
		delete(temp);
		cout<<"Deleted\n";
	}
}

int Phone::hashFunction(char name[])
{
	int sum=0;
	int i=0;
	while(name[i]!='\0')
	{
		sum+=(int)name[i];
		i++;
	}
	int index=sum%MAX;
	return index;
}

int main()
{
	Phone ob;
	int ch;
	do
	{
	cout<<"1.Insert\n";
	cout<<"2.Delete\n";
	cout<<"3.Search\n";
	cout<<"4.Exit\n";
	cin>>ch;
	char name[20];
	switch (ch)
	{
		case 1:
			ob.insertRecord();
			break;
		case 2:
			cout<<"Enter record to delete:";
			cin>>name;
			ob.deleteRecord(name);
			break;
		case 3:
			cout<<"Enter record to searched:";
			cin>>name;
			ob.searchRecord(name);
			break;
	}
	}while(ch!=4);
	return 0;
}
