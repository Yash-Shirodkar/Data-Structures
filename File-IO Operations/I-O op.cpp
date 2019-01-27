/*	Department maintains a student information. The file contains roll number, name, division and address. 
Allow user to add, delete information of student. Display information of particular employee. 
If record of student does not exist an appropriate message is displayed. If it is, then the system displays the student details.
Use sequential file to main the data.  */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

typedef struct stud{
	unsigned int roll;
	char name[100];
	char div,addr[100];
}stud;

int main(){
	int op=1;
	char ch,keyName[100];
	while(1){
		switch(op){
			case 1:
				do{
					fstream infile;
					stud ob;
					cout<<"Enter Name ";
					cin>>ob.name;
					cout<<"Enter Roll number ";
					cin>>ob.roll;
					cout<<"Enter Div ";
					cin>>ob.div;
					cout<<"Enter Address ";
					cin>>ob.addr;
					infile.open("test.txt",ios::app);
					infile.write((char*)&ob, sizeof(ob));
					infile.close();
					cout<<"Do you want to add more info (Y/N) ";
					cin>>ch;
				}while(ch== 'Y' || ch=='y');
				break;
				
			case 2:
				{
					char keyName[100];
					fstream oldfile,newfile;
					cout<<"\nEnter name of student whose data you want to delete ";
					cin>>keyName;
					stud o;
					oldfile.open("test.txt",ios::in);
					newfile.open("test2.txt",ios::app);
					while(!oldfile.eof()){
						oldfile.read((char*)&o,sizeof(o));
						if(!strcmp(o.name,keyName))
							continue;
						newfile.write((char*)&o,sizeof(o));
					}
					oldfile.close();
					newfile.close();
					remove("test.txt");
					rename("test2.txt","test.txt");
				}
				break;
				
			case 3:
			{
				int flag=0;
				cout<<"\nEnter Name of person ";
				cin>>keyName;
				fstream sfile;
				stud obj;
				//int flag;
				sfile.open("test.txt",ios::in);
				while(!sfile.eof()){
					sfile.read((char*)&obj, sizeof(obj));
					if(strcmp(obj.name,keyName)==0){
						flag=1;
						break;
					}
				}
				if(flag){
					cout<<"\nDetails of Person ";
					cout<<"\nName: "<<obj.name;
					cout<<"\nRoll Number: "<<obj.roll;
					cout<<"\nDivision: "<<obj.div;
					cout<<"\nAddress: "<<obj.addr;
				}
				else
					cout<<"\nNOT FOUND...:(";
					
				sfile.close();
				break;
			}
				
			case 4:
				exit(0);
			
		}
		cout<<"\n\n1.Add Info\n2.Delete Info\n3.Search for employee\n4.Exit ";
		cin>>op;
	}
	
}
