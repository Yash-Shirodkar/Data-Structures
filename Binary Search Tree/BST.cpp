#include<iostream>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;
    friend class tree;
};

class tree
{
    node *root;
    public:
            tree();
            void create();
            void insert(node*,node*);
            void inorder(node*);
            void preorder(node*);
            void postorder(node*);
            int search(node*,int);
            void minN(node*);
            void maxN(node*);
            node* del(node*,int);
            int height(node*);
            void disp1();
            void disp2();
            void disp3();
            void srch();
            int ht();
            void minn();
            void maxn();
            void del();
};

tree::tree()
{
    root = NULL;
}
void tree::create()
{
    node* temp = new node;
    cout<<"Enter the number to be inserted : ";
    cin>>temp->data;
    insert(root, temp);
}
void tree::insert(node *temp, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->data = newnode->data;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added";
        return;
    }
    if (temp->data == newnode->data)
    {
        cout<<"Element already in the tree";
        return;
    }
    if (temp->data > newnode->data)       //if key is less than the root
    {
        if (temp->left != NULL)
        {
            insert(temp->left, newnode);
        }
        else
        {
            temp->left = newnode;
            (temp->left)->left = NULL;
            (temp->left)->right = NULL;
            cout<<"Node Added To Left";
            return;
        }
    }
    else
    {                                      //if key is greater than the root
        if (temp->right != NULL)
        {
            insert(temp->right, newnode);
        }
        else
        {
            temp->right = newnode;
            (temp->right)->left = NULL;
            (temp->right)->right = NULL;
            cout<<"Node Added To Right";
            return;
        }
    }

}
void tree::inorder(node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<"  ";
        inorder(ptr->right);
    }
}
void tree::preorder(node *ptr)
{
    if (ptr != NULL)
    {
        cout<<ptr->data<<"  ";
        preorder(ptr->left);
    	  preorder(ptr->right);
    }
}
void tree::postorder(node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
    	  postorder(ptr->right);
    	  cout<<ptr->data<<"  ";
    }
}
int tree::search(node *root,int key)
{

        if(root==NULL)
        {
                return 0;
        }
        if(key==root->data)
        {
                return 1;
        }
        else if(key<root->data)
        {
                return search(root->left,key);
        }
        else if(key>root->data)
        {
                return search(root->right,key);
        }
}
int tree::height(node *T)               //Finding height;
{
	if(T==NULL)
	return 0;
	if(T->left==NULL && T->right==NULL)
	return 0;
	return(max(height(T->left),height(T->right))+1);
}
void tree::minN(node *root)
{
        if(root==NULL)
        {
                cout<<"\nTree is Empty";
                return;
        }
        while(root->left!=NULL)
        {
                root=root->left;
        }
        cout<<"\nMinimum element in the tree is : "<<root->data;
}
void tree::maxN(node *root)
{
        if(root==NULL)
        {
                cout<<"\nTree is Empty";
                return;
        }
        while(root->right!=NULL)
        {
                root=root->right;
        }
        cout<<"\nMaximum element in the tree is : "<<root->data;
}

node* tree::del(node *T,int x)
{
	node *temp;
	if(T==NULL)
		return (T);
	if(x < T->data)
	{
		T->left=del(T->left,x);
		return(T);
	}
	if(x > T->data)
	{
		T->right=del(T->right,x);
		return(T);
	}
	if(T->left==NULL && T->right==NULL)
	{
		temp=T;
		delete temp;
		return (NULL);
	}
	if(T->left==NULL)
	{
		temp=T;
		T=T->right;
		delete temp;
		return (T);
	}
	if(T->right==NULL)
	{
		temp=T;
		T=T->left;
		delete temp;
		return (T);
	}
	temp=T->right;
	while(temp->left!=NULL)
		temp=temp->left;
	T->data=temp->data;
	T->right=del(T->right,temp->data);
	return (T);
}
void tree:: disp1()
{
    inorder(root);
}
void tree:: disp2()
{
    preorder(root);
}
void tree:: disp3()
{
    postorder(root);
}
void tree::srch()
{
    int k,key,fnd;
    cout<<"Enter the element to be searched ";
    cin>>key;
    fnd=search(root,key);
    if(fnd==1)
        cout<<"Element is Present";
    else
        cout<<"Element is Absent";
}
int tree::ht()
{
    int h;
    h=height(root);
    return h;
}
void tree::minn()
{
    minN(root);
}
void tree::maxn()
{
    maxN(root);
}
void tree::del()
{
    int key;
    cout<<"\nEnter the element to be deleted : ";
    cin>>key;
    del(root,key);
}
int main()
{
    tree obj;
    int k,key,fnd;
    while(1)
    {
        cout<<"\n\n1.Insert \n2.Display inorder \n3.Display preorder \n4.Display postorder\n5.Search an element \n6.Height of the Tree \n7.Minimum element \n8.Maximum element\n9.Delete Element \nEnter your choice : ";
        cin>>k;
        switch(k)
        {
            case 1: obj.create();
            break;
            case 2: obj.disp1();
            break;
            case 3:	obj.disp2();
            break;
            case 4: obj.disp3();
            break;
            case 5: obj.srch();
            break;
            case 6: cout<<"\nHeight of tree is : "<<obj.ht();
            break;
            case 7: obj.minn();
            break;
            case 8: obj.maxn();
            break;
            case 9: obj.del();
            break;
        }
    }
    return 0;
}





/*MIRROR
void tree::swap_node(node *n) 
{
  if(n != NULL)
   {
    node *tmp = n->left;
    n->left = n->right;
    n->right = tmp;

    swap_node(n->left);
    swap_node(n->right);
    
  }  
}*/
