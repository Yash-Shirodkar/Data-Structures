#include<iostream>
#include<string>
#include<stack>
using namespace std;

void para(string ex)
{int i,num;
    stack<char> ob;
    for (i=0;i<ex.length();i++)
    {
        if (ex[i]=='{'||ex[i]=='['||ex[i]=='(')
            {
            ob.push(ex[i]);
            }


		else if (ob.empty())
			{
			cout<<"Invalid Operator. Opening braces needed before"<<ex[i]<<" at position "<<i+1;
			return ;
			}

        else if(ex[i]=='}'||ex[i]==']'||ex[i]==')')
               {
                if (ex[i]=='}'&& ob.top()=='{')
                {
                ob.pop();
                }
                else if (ex[i]==']'&& ob.top()=='[')
                {
                ob.pop();
                }
                else if (ex[i]==')'&& ob.top()=='(')
                {
                ob.pop();
                }
                else
                {
                      cout<<"Invalid Input\n";
                      cout<<"No match for "<<ex[i]<<"  placed after "<<ex[i-1]<<" at position"<<i;
                return  ;
                }
            }
	}
	if (!ob.empty())
	{
	cout<<"Invalid Input\nNO match for  ";
		while (!ob.empty())
		{
		cout<<ob.top();
		ob.pop();
		}
	}
else  cout<<"valid inputs";
}

int main ()
{
int i,num;
string exp;


cout<<"Enter the expression\n";

    cin>>exp;

para(exp);
return 0;
}
