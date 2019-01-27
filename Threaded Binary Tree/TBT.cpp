#include<iostream>
using namespace std;

class node
{
	int data,rbit;
    node *left, *right;
    friend class tree;
};

class tree
{
	node *root;
public:
	tree();
	void display();
	void insert();
    node* create(node*, int);
    node* leftmost(node*);
    void inorder(node*,node*);
    void disp(node*);
};
tree::tree()
{
	root = NULL;
}
void tree::display()
{
	if(root==NULL)
	{
		cout << "\n Tree is Empty ";
		return;
	}
	cout << "\n Inorder Display : ";
	inorder(root,NULL);
    disp(root);
}
void tree::insert()
{
	int no;
	cout << "Enter the data ";
	cin >> no;
	if(root==NULL)
	{
		root=create(root,no);
		return;
	}
	create(root,no);
}
node* tree::create(node* root, int n)
{
    if (root == NULL)
    {
        root = new node;
        root->data = n;
        root->left = root->right = NULL;
    }
    else
    {
        if (n < root->data)
            root->left = create(root->left, n);
        else
            root->right = create(root->right, n);
    }
    return root;
}
void tree::inorder(node *root,node *prev)
{
    if(root!=NULL)
    {

        inorder(root->right,prev);
        if(root->right==NULL && prev!=NULL)
        {
            root->right=prev;
            root->rbit=0;
        }
        inorder(root->left,root);
    }
}
node* tree::leftmost(node *root)
{
    if(root==NULL)
        return NULL;
    else
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
}
void tree::disp(node *root)
{
    node *first;
    first=leftmost(root);
    while(first!=NULL)
    {
        cout<<first->data << " ";
        if(first->rbit==0)
            first=first->right;
        else
            first=leftmost(first->right);
    }
}

int main()
{
	int choice;
    tree obj;
	while(true)
	{
		cout << "\n Enter Choice:\n1. Insert\n2. Display\n3. Exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
				obj.insert();
				break;

			case 2:
				obj.display();
				break;

			case 3:
				return 0;

			default:
				cout << "\n Unexpected Choice";
		}
	}
    return 0;
}
