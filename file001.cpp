#include<iostream>
#include<iomanip>
using namespace std;
class student
{
	private:
		int rn,s1,s2,s3,s4,tot;
		float per;
		char name[20];
	public:
		void set_info();
		void dis_info();
		void list_info();
		int getrn();
		char *getname();
};
char * student::getname()
{
	return name;
}
void student::set_info()
{
	cout<<"\n Enter roll no. :   ";
	cin>>rn;
	cout<<"\n Enter name     :   ";
	cin>>name;
	fflush(stdin);
	cout<<"\n physics        :   ";
	cin>>s1;
	cout<<"\n Chemistry      :   ";
	cin>>s2;
	cout<<"\n Maths          :   ";
	cin>>s3;
	tot=s1+s2+s3;
	per=tot/3.0;
}
void student::dis_info()
{
	cout<<"\n Roll no.   :   "<<rn;
	cout<<"\n Name       :   "<<name;
	cout<<"\n Physics    :   "<<s1;
	cout<<"\n Chemistry  :   "<<s2;
	cout<<"\n Maths      :   "<<s3;
	cout<<"\n Total      :   "<<tot;
	cout<<"\n Percentage :   "<<per;
	cout<<"\n------------------------------------------------------------------------------";
}
void student::list_info()
{
	cout<<setw(5)<<rn<<setw(12)<<name<<setw(13)<<s1<<setw(11)<<s2<<setw(11)<<s3<<setw(9)<<tot<<setw(9)<<setprecision(2)<<per<<endl;
}
int student::getrn()
{
	return rn;
}


