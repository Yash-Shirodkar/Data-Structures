#include<iostream>
#include<map>
using namespace std;
class STL
{
    int ch,key,value,fkey,dkey;
public:
	map<int,int>ok;
  	map<int,int>::iterator p;
	void insert_();
	void search();
	void display();
	void delet();
};
void STL::insert_()
{
	cout<<"Enter a unique key : ";
	cin>>key;
	cout<<"Enter value : ";
	cin>>value;
	ok.insert(make_pair(key,value));
}
void STL::search()
{
	if(ok.empty())
		cout<<"Hashmap is empty"<<endl;
	else
	{
		cout<<"Enter key to be found : ";
	 	cin>>fkey;
	  	if(ok.find(fkey)==ok.end())			//if no element is found returns last and compares with end
			cout<<"The key doesn't exist."<<endl;
	  	else
		{
	  		cout<<"The value at key "<<fkey<<" is ";
	  		cout<<ok.find(fkey)->second;
	  	}
	}
}
void STL::display()
{
	if(ok.empty())
		cout<<"Hashmap is empty"<<endl;
	else
	{
		cout<<"The elements are : "<<endl;
		for(p=ok.begin();p!=ok.end();p++)
		{
			cout<<p->first<<"->"<<p->second<<endl;
		}
		cout<<endl;
	}
}
void STL::delet()
{
	if(ok.empty())
	     	cout<<"Hashmap is already empty"<<endl;
    else
    {
      	cout<<"Enter the key to be deleted : "<<endl;
        	cin>>dkey;
        	if(ok.find(fkey)==ok.end())
          		cout<<"The key doesn't exist."<<endl;
        	else
        	{
			 ok.erase(dkey);
			 cout<<"Key "<<dkey<<" deleted."<<endl;
			 cout<<"The updated elements are : "<<endl;
			for(p=ok.begin();p!=ok.end();p++)
			{
				cout<<p->first<<"->"<<p->second<<endl;
			}
		}
      }
}
int main()
{
  	STL obj;
  	int ch;
    	char c;
  	do
  	{
    		cout<<"\n1.Insert \n2.Find \n3.Display map elements\n4.Delete a key \nEnter your choice : ";
    		cin>>ch;
	  	switch(ch)
  		{
    			case 1:obj.insert_();
		      break;
    			case 2:obj.search();
    			break;
		    	case 3:obj.display();
		    	break;
    			case 4:obj.delet();
    			break;
      	default: cout<<"Invalid choice."<<endl;
		}
  cout<<"\nDo you want to continue? (y/n) ";
  cin>>c;
  }while(c=='Y'||c=='y');
}
