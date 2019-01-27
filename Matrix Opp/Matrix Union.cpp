#include<iostream>

using namespace std;

class SetOps
{
	unsigned int iCrick,iBadm,iTotal,iBoth,iUnion,iTotalSet[120],iSetA[60],iSetB[60],iCount,iUSet[120],iISet[60],iNum;
	int i,j;
public :

	void getData();
	void Union();
	void Inter();
	void Crick();
	void Badm();
	void Neither();

};														//class end

void SetOps::getData()											//getdata
{
	iTotal=60;
	cout << "\n Enter total number of students : ";
	cin >> iTotal;
	cout << "\n Enter their roll no.s : ";
	for(i=0;i<iTotal;i++)
		cin >> iTotalSet[i];
	cout << "\n Enter number of students who play cricket : ";
	cin >> iCrick;
	cout << "\n Enter their roll no.s : ";
	for(i=0;i<iCrick;i++)
		cin >> iSetA[i];
	cout << "\n Enter number of students who play badminton : ";
	cin >> iBadm;
	cout << "\n Enter their roll no.s : ";
	for(i=0;i<iBadm;i++)
		cin >> iSetB[i];
}

void SetOps::Union()
{
	iUnion = iCrick + iBadm;

	for(i=0;i<iCrick;i++)
		iUSet[i]=iSetA[i];

	for(j=0;j<iBadm;i++,j++)
		iUSet[i]=iSetB[j];


	for(i=0;i<iUnion;i++)
	{
		iCount=0;
		for(j=i;j<iUnion;j++)
		{
			if(iUSet[j]==iUSet[i])
			{
				++iCount;
				if(iCount>1)
		{
			iUSet[j] = iUSet[iUnion-1];
			iUnion--;
		}
			}
		}
	}

	cout << "\n\n ";
	cout << "\n Roll numbers of students who play cricket or badminton or both are : " ;
	for(i=0;i<iUnion;i++)
		cout << iUSet[i] << " ";


}

void SetOps::Inter()
{
  iBoth=0;
  for(i=0;i<iCrick;i++)
  {
    iCount=0;
    for(j=0;j<iBadm;j++)
      {
        if(iSetA[i]==iSetB[j])
        {
            if(iCount<1)
            {
              iISet[iBoth] = iSetA[i];
              iBoth++;
              iCount++;
            }
        }
      }
  }
	cout << "\n Roll numbers of students who play both are : " ;
	for(i=0;i<iBoth;i++)
    cout << iISet[i] << " ";
}

void SetOps::Crick()
{	
	bool check;	
	cout << "\n Roll numbers of students who only play cricket are : ";
	for(i=0;i<iCrick;i++)
    {
    	check=true;

    	for(j=0;j<iBoth;j++)
    		if(iSetA[i]==iISet[j])
    			check = false;
    		
    	if(check==true)
    		cout << iSetA[i] << " ";	
    }
}

void SetOps::Badm()
{
	
	bool check;	
	cout << "\n Roll numbers of students who only play badminton are : ";
	for(i=0;i<iBadm;i++)
    {
    	check=true;

    	for(j=0;j<iBoth;j++)
    		if(iSetB[i]==iISet[j])
    			check = false;
    		
    	if(check==true)
    		cout << iSetB[i] << " ";	
    }
}

void SetOps::Neither()
{
  
	bool check;
	cout << "\n Number of students who play neither are : " ;
	for(i=0;i<iTotal;i++)
	{
		check = true;
		for(j=0;j<iUnion;j++)
			if(iTotalSet[i]==iUSet[j])
				check = false;
				
		if(check==true)
			cout << iTotalSet[i] << " ";		
	}
}

int main()
{
	int iChoice;
	char cChoice;
	SetOps obj;
	obj.getData();
	obj.Union();
	obj.Inter();
	obj.Crick();
	obj.Badm();
	obj.Neither();
}
