//==================================================================
#include <iostream>
using namespace std;
class hash
{
	string word,meaning;

        friend class hashing;
};


class hashing
{

        hash arr[10];
        string key,value;
public:
	hashing();
	void get_input();
	void hash_func(string key,string value);
	void display();
	void search();
	void del();
};
hashing::hashing()
{
        	for(int i=0;i<10;i++)
		{
			arr[i].word="\0";
		}
}
void hashing::get_input()
{

cout<<"enter the word"<<endl;
cin>>key;
cout<<"enter the meaning"<<endl;
cin>>value;
hash_func(key,value);
}

void hashing:: hash_func(string key,string value)
{
	int count=0;
	int index=0;

	for(int i=0;i<key.length();i++)
	{
	  index=(index+key[i]);
	}
        index=index%10;


	if(arr[index].word=="\0")
	{
		arr[index].word=key;
		arr[index].meaning=value;
	}
	else
	{
		for(int i=index;count<10;i=(i+1)%10,count++)
	{
		if(arr[i].word=="\0" || arr[i].word=="$")
		{
			arr[i].word=key;
			arr[i].meaning=value;
			break;
		}
		if(count==10)
			cout<<"hash table is full"<<endl;
	}
	}
}

void hashing::display()
{
	for(int i=0;i<10;i++)
		{
		cout<<endl<<i<<") "<<arr[i].word<<" => "<<arr[i].meaning<<endl;
		}
}
void hashing::search()
{

	int count=0,pos=0;
	cout<<"enter the word"<<endl;
	cin>>key;


	for(int i=0;i<key.length();i++)
		{
			 pos=(pos+key[i]);
		}
		 pos=pos%10;

         for(int i=pos;count<10;i=(i+1)%10,count++)
         {
		if(arr[i].word==key)
		{
			cout<<"word found and "<<"Meaning is: "<<arr[i].meaning<<endl;
			break;
		}
		if(arr[i].word=="\0" )
		{
			count=10;
			break;
		}
	}
	if(count==10)
	{
		cout<<"word is not present"<<endl;
	}
}

void hashing::del()
{
        int pos=0,count=0;
        string key;
	cout<<"enter the word to be deleted"<<endl;
	cin>>key;


	for(int i=0;i<key.length();i++)
	{
		 pos=(pos+key[i]);
	}
        pos=pos%10;

	for(int i=pos;count<10;i=(i+1)%10,count++)
	{
		if(arr[i].word==key )
		{
			arr[i].word="$";
                        arr[i].meaning='$';
			break;
		}
		if(arr[i].word=="\0")
		{
			count=10;
			break;
		}
	}
	if(count==10)
	{
		cout<<"word is not present"<<endl;
	}
}

int main()
{
hashing H;
int n;
char c='y';
do{
	cout<<"enter your choice"<<endl;
	cout<<"1.insert\n2.display\n3.search\n4.delete"<<endl;
	cin>>n;
	switch(n)
	{
	case 1:
	H.get_input(); break;

	case 2:
		H.display(); break;

	case 3:
		H.search(); break;

	case 4:
		H.del(); break;

	}
	cout<<"do you want to continue (y/n)"<<endl;
	cin>>c;
}while(c=='y');

return 0;
}
