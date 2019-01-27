#include<iostream>

using namespace std;

int main()
{
  int i,j,k,iArr[10][10];
  unsigned int iSaddle,iRow,iColm,ipos,jpos,iCounter;
  bool flag;

  cout << "\n Enter size \n";
  cin >> iRow >> iColm;

  cout << "\n Enter matrix : \n";

  for(i=0;i<iRow;i++)
    for(j=0;j<iColm;j++)
      cin >> iArr[i][j];

  for(i=0;i<iRow;i++)
  {
    iCounter=0;												// Counter to check for multiple instances
    flag=true;
    iSaddle = iArr[i][0];
    jpos = 0;
    ipos = i;
    for(j=0;j<iColm;j++)
    {
    	if(iSaddle==iArr[i][j])
             iCounter++;
       if(iArr[i][j]<iSaddle)
         {
           iSaddle = iArr[i][j];
           jpos = j;
           ipos = i;
         }
    }

    if(iCounter > 1)
        flag = false;

    iCounter=0;

    for(k=0;k<iRow;k++)							// using i to run super-loop
    {
    if(iSaddle==iArr[k][jpos])
      iCounter++;

    if(iArr[k][jpos]>iSaddle)
      flag=false;
    }

    if(iCounter > 1)
      flag = false;

    if(flag==true)
     cout << "\n Saddle point is " << iSaddle << " at " << ipos+1 << " row and " << jpos+1 << " column \n";
  }
  return 0;
}
