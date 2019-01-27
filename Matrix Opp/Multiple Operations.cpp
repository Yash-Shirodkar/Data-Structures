using namespace std;

class Matrix
{
public:
int a[10][10],b[10][10],s[10][10],
d[10][10],m[10][10];
int i,j,k,y,m1,n1,m2,n2;
int input()
{
cout<<"Enter the rows and columns of the matrix:"<<endl;
cin>>m1>>n1;
return 0;
}
int input2()
{
cout<<"Enter the rows and columns of the matrix:"<<endl;
cin>>m2>>n2;
return 0;
}
int accept()
{
cout<<"Enter 1st Matrix";
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
cin>>a[i][j];
}
}
return 0;
}

int accept2()
{
cout<<"Enter 2nd Matrix";
for(i=0;i<m2;i++)
{
for(j=0;j<n2;j++)
{
cin>>b[i][j];
}
}
return 0;
}

int upper()
{
int up=0;
int cnt=0;
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
if(i>j)
cnt++;
if(a[i][j]==0)
up++;
}
}
if(up==cnt)
cout<<"Upper Traingular Matrix \n";
else
cout<<"Not an Upper Traingular Matrix \n";
return 0;
}

int lower()
{
  int cnt1=0;
  int down=0;
  for(i=0;i<m1;i++)
    {
     for(j=0;j<n1;j++)
       {
        if(i<j)
        cnt1++;
        if(a[i][j]==0)
        down++;
        }
    }
if(down==cnt1)
  cout<<"Lower Traingular Matrix \n";
else
  cout<<"Not a Lower Traingular Matrix \n";
  return 0;
}

int transpose()
{
cout<<"Transpose of the Matrix is: \n";
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
cout<<a[j][i]<<"\t";
}
cout<<"\n";
}
return 0;
}

int diagonal()
{
int sum=0;
for(i=0;i<n1;i++)
{
for(j=0;j<m1;j++)
{
if(i==j)
sum=sum+a[i][j];
}
}
cout<<"Sum of Diagonal Elements is: "<<sum<<"\n";
return 0;
}

int add()
{
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
s[i][j]=a[i][j]+b[i][j];
}
}
cout<<"Resultant Sum Matrix: \n";
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
cout<<s[i][j]<<"\t";
}
cout<<"\n";
}
return 0;
}

int subtract()
{
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
d[i][j]=a[i][j]-b[i][j];
}
}

cout<<"Resultant Difference Matrix: \n";
for(i=0;i<m1;i++)
{
for(j=0;j<n1;j++)
{
cout<<d[i][j]<<"\t";
}
cout<<"\n";
}
return 0;
}
int checkm()
{
if(n1==m2)
return 0;
else
{
cout << "Error! column of first matrix not equal to row of second. \n";
return 1;
}
}
int multiply()
{
for(i=0; i<m1;i++)
{
for(j=0; j<n2;j++)
{
m[i][j]=0;
for(k=0; k<n1;k++)
{
m[i][j]+=a[i][k]*b[k][j];
}
}
}

cout<<"Multiplied Matrix: \n";
for(i=0;i<m1;i++)
{
for(j=0;j<n2;j++)
{
cout<<m[i][j]<<"\t";
}
cout<<"\n";
}
return 0;
}
};
int main()
{
char ans;
int a[10][10],i,j,ch;
Matrix x;
do
{
cout<<"What Operations would you like to Perform? \n";
cout<<"1.Check if Matrix is Upper Traingular. \n";
cout<<"2.Check if Matrix is Lower Traingular. \n";
cout<<"3.Find Transpose of the Matrix. \n";
cout<<"4.Find Sum of Diagonal Elements. \n";
cout<<"5.Add Two Matrices. \n";
cout<<"6.Subtract Two Matrices. \n";
cout<<"7.Multiply Two Matrices. \n";
cout<<"Enter Your Choice? \n";
cin>>ch;

switch (ch)
{
case 1:    x.input();
if(x.m1!=x.n1)
    {
    cout<<"\n The operation cannot be performed";
    break;
    }
else
x.accept();
x.upper();
break;
case 2:x.input();
if(x.m1!=x.n1)
    {
    cout<<"\n The operation cannot be performed";
    break;
    }
    else
x.accept();
x.lower();
break;
case 3:x.accept();
x.transpose();
break;
case 4:x.accept();
x.diagonal();
break;
case 5:x.input();
x.input2();
if(x.m1!=x.m2)
    {
    cout<<"\n The operation cannot be performed";
    break;
    }
else if(x.n1!=x.n2)
    {
    cout<<"\n The operation cannot be performed";
    break;
    }
else
x.accept();
x.accept2();
x.add();
break;
case 6:
x.input();
x.input2();
if(x.m1!=x.m2)
    {
    cout<<"\n The operation cannot be performed";
    break;
    }
else if(x.n1!=x.n2)
    {
    cout<<"\n The operation cannot be performed";
    break;
    }
    else
x.accept();
x.accept2();
x.subtract();
break;
case 7:x.accept();
x.accept2();
x.y=x.checkm();
if(x.y==1)
break;
else
x.multiply();
break;
case 0:
break;
default:cout<<"Invalid choice. Try Again! \n";
}

cout<<"\n Do another(y/n)?";
cin>>ans;
}
while(ans=='y');
return 0;
}
