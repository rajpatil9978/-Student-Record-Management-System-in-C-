#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include"file001.cpp"
void addinfo();
void dis_info();
void list_info();
void srch_rn();
void srch_name();
void delete_info();
void edit_info();
void first_rec();
void last_rec();
void file_size();
using namespace std;
char filename[20]="result.txt";
int main()
{
	
	int ch;
	do
	{
		system("cls");
		
		cout<<"\n\n\t   1. Add info";
		cout<<"\n\t   2. Display info";
		cout<<"\n\t   3. List info";
		cout<<"\n\t   4. Search by roll no";
		cout<<"\n\t   5. Search by name";
		cout<<"\n\t   6. Edit info";
		cout<<"\n\t   7. Delete info";
		cout<<"\n\t   8. First info";
		cout<<"\n\t   9. Last info";
		cout<<"\n\t  10. File info";
		cout<<"\n\t  11. Exit";
		cout<<"\n------------------------------------------------------------------------------";
		cout<<"\n\n\t Enter your choice :   ";
		cin>>ch;
		cout<<"\n------------------------------------------------------------------------------";
		
		switch(ch)
		{
			case 1:
				addinfo();
				break;
			case 2:
				dis_info();
				break;
			case 3:
				list_info();
				break;
			case 4:
				srch_rn();
				break;
			case 5:
				srch_name();
				break;
			case 6:	
				edit_info();
				break;	
			case 7:
				delete_info();
				break;
			case 8:	
				first_rec();
				break;
			case 9:
				last_rec();
				break;	
			case 10:
				file_size();
				break;
			case 11:
				return 1;
				break;
			default:
				cout<<"\n - - - Invalide Choise - - - ";
		}
		
		getch();
	}while(ch>=1&&ch<=11);
}

void addinfo()
{
	student obj1;
	ofstream file1;
	file1.open(filename,ios::out|ios::app);
	if(file1.fail())
	{
		cout<<"\n Unable to open file";
		return;
	}
	char ch;
	cout<<"\n\n\t * * * Add Student info  * * * ";
	cout<<"\n---------------------------------------------------------";
	do
	{
		obj1.set_info();
		file1.write((char*)&obj1,sizeof (obj1));
		
		cout<<"\n Do you wnt to add next record....?";
		cin>>ch;
	}while(ch=='y');
	file1.close();	
}
void dis_info()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file...";
		return;
	}
	char cho;
	cout<<"\n\n\t * * * Displyaing students info  * * * ";
	cout<<"\n---------------------------------------------------------";
	do
	{
		file1.read((char *)&obj1,sizeof(obj1));
		if(file1.eof())
		{
			break;
		}
		
		obj1.dis_info();
	
		cout<<"\n Do you want to display next record...?";
		cin>>cho;
		
	}while(cho=='y');
	file1.close();
}
void list_info()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
	cout<<"\n\n\t * * * List of all Students  * * * ";
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\n Roll No.    Name         Physics   Chemistry   Maths    Total   percentage"<<endl;
	cout<<"------------------------------------------------------------------------------"<<endl;
	do
	{
		file1.read((char *)&obj1,sizeof(obj1));
		if(file1.eof())
		{
			break;
		}
		
		obj1.list_info();
		
	}while(!file1.eof());
	file1.close();
}
void srch_rn()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
	int tem,ch,xyz=0;
	cout<<"\n Enter roll number to display info :  ";
		
		cin>>tem;
	do
	{
		file1.read((char *)&obj1,sizeof(obj1));
		if(file1.eof())
		{
			break;
		}
		
		if(tem==obj1.getrn())
		{
			cout<<"\n\n\t * * * Info you Searched  * * * ";
	        cout<<"\n---------------------------------------------------------";
			obj1.dis_info();
			xyz=1;
		}
	
	}while(!file1.eof());
	if(xyz==0)
	{
		cout<<"\n Record not found....";
		return;
	}
	file1.close();
}
void srch_name()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
	char tem[20];
	int xyz=0;
	cout<<"\n Enter name to display info :  ";
	cin>>tem;
	do
	{
		file1.read((char *)&obj1,sizeof(obj1));
		if(file1.eof())
		{
			break;
		}
		
		if(strcmp(tem,obj1.getname())==0)
		{
			cout<<"\n\n\t * * * Info you Searched  * * * ";
	cout<<"\n---------------------------------------------------------";
			obj1.dis_info();
			xyz=1;
		}
	
	}while(!file1.eof());
	if(xyz==0)
	{
		cout<<"\n Record not found....";
		return;
	}
	file1.close();
}
void delete_info()
{
	student obj1;
	ifstream file1;
	ofstream f2;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file...";
		return;
	}
	f2.open("tem.txt",ios::out);
	if(f2.fail())
	{
		cout<<"\n Unable to open file...";
		return;		
	}
	cout<<"\n---------------------------------------------------------";
	int tem,xyz=0;
	char ch;
	cout<<"\n\n\t Enter roll no. to delete info :   ";
	cin>>tem;
	cout<<"\n---------------------------------------------------------";
	do
	{
		file1.read((char *)&obj1,sizeof(obj1));
		if(file1.eof())
		{
			break;
		}
		if(tem==obj1.getrn())
		{
			obj1.dis_info();
			xyz=1;
			
			cout<<"\n\t * * * * * RECORD DELETED PERMANENTLY * * * * *";	
		}
		else 
		{	
			    f2.write((char *)&obj1,sizeof(obj1));
			    
			    
	    }
		
		
	}while(!file1.eof());
	if(xyz=0)
	{
		cout<<"\n Record not found...";
		return;
	}
	file1.close();
	f2.close();
	remove(filename);
	rename("tem.txt",filename);
}
void edit_info()
{
	student obj1;
	fstream file1;
	file1.open(filename,ios::in|ios::out);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
		cout<<"\n\n\t * * * Edit info  * * * ";
	cout<<"\n---------------------------------------------------------";
	int tem,xyz=0;
	char ch;
	cout<<"\n\n\t Enter roll no. to edit info :   ";
	cin>>tem;
	cout<<"\n---------------------------------------------------------";
	do
	{
		file1.read((char *)&obj1,sizeof(obj1));
		if(file1.eof())
		{
			break;
		}
		if(tem==obj1.getrn())
		{
			obj1.dis_info();
			xyz=1;
			cout<<"\n\n\t --- Enter new info ---"<<endl;
			obj1.set_info();
			cout<<"\n Are you sure to edit this..?(y/n)";
			fflush(stdin);
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\n\t * * * * * YOUR EDITED RECORD SAVED SUCCSESSFULLY * * * * * ";
				file1.seekg(sizeof(obj1)*-1,ios::cur);
				file1.write((char *)&obj1,sizeof(obj1));
			}
			else
			{
				cout<<"\n\t * * * * * RECORD NOT SAVED * * * * * ";
				return;
			}
						
		}
	
	}while(!file1.eof());
	if(xyz==0)
	{
		cout<<"\n Record not found....";
		return;
	}
	file1.close();
	
}
void first_rec()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
	file1.read((char *)&obj1,sizeof(obj1));
	cout<<"\n\n\t * * * First Record * * * ";
	cout<<"\n---------------------------------------------------------";
	obj1.dis_info();
	file1.close();
		
}
void last_rec()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
	int pos;
	file1.seekg(0,ios::end);
	pos=sizeof(obj1)*-1;
	file1.seekg(pos,ios::cur);
	file1.read((char *)&obj1,sizeof(obj1));
	cout<<"\n\n\t * * * Last record * * * ";
	cout<<"\n---------------------------------------------------------";
	obj1.dis_info();
	file1.close();
}
void file_size()
{
	student obj1;
	ifstream file1;
	file1.open(filename,ios::in);
	if(file1.fail())
	{
		cout<<"\n Unable to open file....";
		return;
	}
	int pos,fs,tr,rs;
	file1.seekg(0,ios::end);
	fs=file1.tellg();
	rs=sizeof(obj1);
	tr=fs/rs;
	
	cout<<"\n\n\t * * * File Information * * * ";
	cout<<"\n---------------------------------------------------------";
	cout<<"\n\t File size      =   "<<fs<<" Bytes ";
	cout<<"\n\t Record size    =   "<<rs<<"  Bytes ";
	cout<<"\n\t Total Records  =   "<<tr;
	cout<<"\n---------------------------------------------------------";
}
