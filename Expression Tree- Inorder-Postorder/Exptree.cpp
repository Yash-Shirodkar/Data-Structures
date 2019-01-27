#include<string>
#include <iostream>
using namespace std;
class node;
class tree;
const int MAX=50;

class Stack
		{
		 int top;
		 node *info[MAX];

		public:
		 Stack()
		{
			  top=-1;
		}
		 void push(node *cnode)
		 {
			  top=top+1;
			  info[top]=cnode;
		 }
		 node *Top()
		 {
			  return info[top];
		 }
		 node * pop()
		 {
			  if(!empty())
			  {
			   return info[top--];
			  }
	
			  return NULL;
		 }
		 bool empty()
		 {
			  if(top==-1)
			   return true;
	
			  else
			   return false;
		 }
		 bool isFull()
		 {
			  if(top==MAX-1)
			   return true;
	
			  else
			   return false;
 	}
};

class node
{
		node *left,*right;
		char data;
		public:
		node()
		{
		 	 left=right=NULL;

		}
		node(char ch)
		 {
		  	left=right=NULL;
		  	data=ch;
		 }
		friend class tree;
};


class tree
{
		private:
		 node *root;

		public:
		 tree()
		{
		  root=NULL;
		}
		 void create(string str);
		 void inorderNonRec();
     		 void preorder_rec(node *);
		 void inorder_rec(node *);
		 void postorder_rec(node *);
		 void postorderNon();
		 
		 void postorder()
		 {
		  postorder_rec(root);
		 }
		 
		 void inorder()
		 {
		  inorder_rec(root);
		 }
		 
		 int priority(char ch);
};


int tree::priority(char ch)							//PRIORITY
{
	 switch(ch)
	 {
	 case '+':
	 case '-':
	  return 0;
	  break;
	 case '*':
	 case '/':
	  return 1;
	  break;
	 case '^':
	  return 2;
	  break;

	 }
	 return -1;
}

void tree::inorder_rec(node *rnode)						//INORDER
{
 if(rnode)
	 {
	  inorder_rec(rnode->left);
	  cout<<" "<<rnode->data;
	  inorder_rec(rnode->right);
	 }
}
void tree::postorder_rec(node *rnode)						//POSTORDER
{
 if(rnode)
	 {
	  postorder_rec(rnode->left);
	  postorder_rec(rnode->right);
	  cout<<" "<<rnode->data;
	 }
}
void tree::create(string str)							//CREATE
{
	 Stack s1,s2;
	 int i=0;
	 char ch;
	 while(str[i]!='\0')
	 {

		  ch=str[i];
	  if(isalpha(ch))
	  {
		   node *temp=new node(ch);
		   s1.push(temp);
  	  }
	  else
	  {
	   if(s2.empty())
	   {
	   	 node *temp=new node(ch);
	   	 s2.push(temp);
	   }
	   else if(priority(ch)>priority(s2.Top()->data))
	   {
	  	  node *temp=new node(ch);
	  	  s2.push(temp);
	   }
	   else
	   {
	    while(!s2.empty()&&priority(ch)<=priority(s2.Top()->data) )
	    {
	  	   node *op=s2.pop();
	  	   node *rchild=s1.pop();
	  	   node *lchild=s1.pop();

	  	   op->right=rchild;
	  	   op->left=lchild;

	  	   s1.push(op);
	    }
	    s2.push(new node(ch));
	   }
	  }

	  i++;

	 }
	 while(!s2.empty())
	 {
	  	node *op=s2.pop();
	  	node *rchild=s1.pop();
	  	node *lchild=s1.pop();

	  	op->right=rchild;
	  	op->left=lchild;
	  	s1.push(op);
	 }
	 root=s1.pop();

}

int main() 									//MAIN
{
     cout << "" << endl;
     tree t1;
     string exp;
     cout<<"\nEnter the Expression: ";
     cin>>exp;
     t1.create(exp);
     cout<<"\nInorder : ";
     t1.inorder();
     cout<<"\nPostorder : ";
     t1.postorder();

     return 0;
}
