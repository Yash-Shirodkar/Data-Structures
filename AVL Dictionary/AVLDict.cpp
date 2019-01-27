#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
    public:
    char data[20];
    char data1[100];
    node *left,*right;
    int ht;
};

class AVL
{
    node *root;
    public:
    AVL();
    int height(node *);
    node *rotate_right(node *);
    node *rotate_left(node *);
    node *RR(node *);
    node *LL(node *);
    node *LR(node *);
    node *RL(node *);
    int BF(node *);
    node *insert(node *,char[],char[]);
    node *delet(node *,char[]);
    
    void preorder (node *);
    void inorder(node *);
    int search(node*,char[]);
    int update(node*,char[]);
};
AVL::AVL()
{
    root=NULL;
}

node *AVL::insert(node *T,char keyword[],char meaning[])
{
    if(T==NULL)
    {
        T=new node;
        strcpy(T->data,keyword);
        strcpy(T->data1,meaning);
        T->left=NULL;
        T->right=NULL;
    }
    else
    {
        if(strcmp(keyword,T->data)>0)
        {
            T->right=insert(T->right,keyword,meaning);
            if(BF(T)==-2)
            {
                if(strcmp(keyword,T->right->data)>0)
                    T=RR(T);
                else
                    T=RL(T);
            }
        }
        else if(strcmp(keyword,T->data)<0)
        {
            T->left=insert(T->left,keyword,meaning);
            if(BF(T)==2)
            {
                if(strcmp(keyword,T->left->data)<0)
                    T=LL(T);
                else
                    T=LR(T);
            }
        }
    }
    T->ht=height(T);
    return(T);
}

node *AVL::delet(node *T,char keyword[])
{
    node *p;
    if(T==NULL)
        return(0);
    else if(strcmp(keyword,T->data)>0)
    {
        T->right=delet(T->right,keyword);
        if(BF(T)==2)
            if(BF(T->left)>=0)
                T=LL(T);
            else
                T=LR(T);
    }
    else if(strcmp(keyword,T->data)<0)
    {
        T->left=delet(T->left,keyword);
        if(BF(T)==-2)
            if(BF(T->right)<=0)
                T=RR(T);
            else
                T=RL(T);
    }
    else
    {
        if(T->right!=NULL)
        {
            p=T->right;
            while(p->left!=NULL)
                p=p->left;
            strcpy(T->data,p->data);
            T->right=delet(T->right,p->data);
            if(BF(T)==2)
                if(BF(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
        }
        else
            return(T->left);
    }
    T->ht=height(T);
    return(T);
}

int AVL::height(node *T)

{
    int LH,RH;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        LH=0;
    else
        LH=1+T->left->ht;
    if(T->right==NULL)
        RH=0;
    else
        RH=1+T->right->ht;
    if(LH>RH)
        return (LH);
    else
        return (RH);
}

int AVL::BF(node *T)
{
    int LH,RH;
    if(T==NULL)
        return(0);
    if(T->left==NULL)
        LH=0;
    else
        LH=1+T->left->ht;
    if(T->right==NULL)
        RH=0;
    else
        RH=1+T->right->ht;
    return(LH-RH);
}

node *AVL::rotate_left(node *x)
{
    node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node *AVL::rotate_right(node *x)
{
    node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return(y);
}

node *AVL::LL(node *T)
{
    T=rotate_right(T);
    return(T);
}

node *AVL::RR(node *T)
{
    T=rotate_left(T);
    return(T);
}

node *AVL::LR(node *T)
{
    T->left=rotate_left(T->left);
    T=rotate_right(T);
    return(T);
}

node *AVL::RL(node *T)
{
    T->right=rotate_right(T->right);
    T=rotate_left(T);
    return(T);
}

void AVL::preorder(node *root)
{
    node *T=root;
    if(T!=NULL)
    {
        preorder(T->right);
        cout<<" \n"<<T->data<<" - "<<T->data1;
        preorder(T->left);
    }
}

void AVL::inorder(node *root)
{
    node *T=root;
    if(T!=NULL)
    {
        inorder(T->left);
        cout<<" \n"<<T->data<<" - "<<T->data1;
        inorder(T->right);
    }
}
int AVL::search(node *root,char key[100])
{
        if(root==NULL)
        {
                return 0;
        }
        if(strcmp(root->data,key)==0)
        {
                cout<<root->data<<" \nCurrent meaning : "<<root->data1<<endl;
                char neu[100];
                cout<<"\nEnter the new meaning of this word : ";
                ws(cin);
                cin.getline(neu,100);
                strcpy(root->data1,neu);
                return 1;
        }
        else if(strcmp(root->data,key)>0)
        {
                return search(root->left,key);
        }
        else if(strcmp(root->data,key)<0)
        {
                return search(root->right,key);
        }
}
int AVL::update(node *root,char key[100])
{
        if(root==NULL)
        {
                return 0;
        }
        if(strcmp(root->data,key)==0)
        {
                cout<<root->data<<" : "<<root->data1<<endl;
                return 1;
        }
        else if(strcmp(root->data,key)>0)
        {
                return search(root->left,key);
        }
        else if(strcmp(root->data,key)<0)
        {
                return search(root->right,key);
        }
}
int main()
{
    AVL A;
    int x,n,i,choice;
    char keyword[20],meaning[100];
    node *root=NULL;
    do
    {
    cout<<"\n MENU: ";
    cout<<"\n1.Insert\n2.Delete\n3.Ascending Display\n4.Descending Display\n5.Search\n6.Update";
    cout<<"\n\nEnter the choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\nEnter the keyword to be insert : ";
            cin>>keyword;
            cout<<"\nEnter the meaning : ";
            ws(cin);
            cin.getline(meaning,100);
            root=A.insert(root,keyword,meaning);
        break;
        case 2:
            cout<<"\n\nEnter a data which u have to delete: ";
            cin>>keyword;
            A.delet(root,keyword);
        break;
        case 3:
            cout<<"\n\nAscending Display:";
            A.inorder(root);
        break;
        case 4:
            cout<<"\n\nDescending Display:";
            A.preorder(root);
        break;
        case 5: cout<<"Enter the keyword to be searched : ";
                cin>>keyword;
                x=A.search(root,keyword);
        break;
        case 6: cout<<"Enter the keyword to be updated : ";
                cin>>keyword;
                x=A.update(root,keyword);
        break;
        }
    }while(1);
    return 0;
}
