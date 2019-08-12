//TIHAR JAIL MANAGEMENT
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
int password()                                                          //PASSWORD FUNCTION
{
	char ch[25]="                     ";
	int i=0,b=0;
	while(1)
	{
		ch[i]=getch();
		if(ch[i]!=8&&ch[i]!=13)
		{
			cout<<"*";
			i++;
		}
		else if(ch[i]==13)
			break;
		else if(ch[i]==8)
		{
			cout<<"\b";
			clreol();
			ch[i]='~';
			i--;
		}
	}
	ch[i]=NULL;
	for(i=0;ch[i]!=NULL;i++)
	{
		if(ch[i]=='~')
		{
			for(int j=i;ch[i]!=NULL;j++)
				ch[j]=ch[j+1];
			i++;
		}
	}
	if(strcmp(ch,"hello")==0)
		b=1;
	return b;
}
int n,n2,dat[25];
struct date                                                             //STRUCTURE OF DATE
{
	int year,mon,day;
}d2;
struct info                                                             //STORING PRISONER DETAILS
{
	int pno;
	char pname[25],fname[25];
	int age;
	date d1,d3;
	char crime[30];
};
void input(info a[],int n)                                              //INPUT DETAILS
{
	int x=8;
	for(int i=0;i<n;i++)
	{
		gotoxy(1,x);
		cin>>a[i].pno;
		gotoxy(12,x);
		gets(a[i].pname);
		gotoxy(23,x);
		gets(a[i].fname);
		gotoxy(43,x);
		cin>>a[i].d1.day;
		gotoxy(45,x);
		cout<<"/";
		gotoxy(46,x);
		cin>>a[i].d1.mon;
		gotoxy(48,x);
		cout<<"/";
		gotoxy(49,x);
		cin>>a[i].d1.year;
		gotoxy(56,x);
		cin>>a[i].age;
		gotoxy(66,x);
		gets(a[i].crime);
		x++;
	}
}
void output(info a2[],int n)                                              //DISPLAY INFORMATION
{
	int x=7;
	for(int i=0;i<n;i++)
	{
		gotoxy(1,x);
		cout<<a2[i].pno;
		gotoxy(12,x);
		cout<<a2[i].pname;
		gotoxy(23,x);
		cout<<a2[i].fname;
		gotoxy(43,x);
		cout<<a2[i].d1.day<<"/"<<a2[i].d1.mon<<"/"<<a2[i].d1.year;
		gotoxy(56,x);
		cout<<a2[i].age;
		gotoxy(64,x);
		cout<<a2[i].crime;
		x++;
	}
}
void output2(info a2[],int n)
{
	int x=7;
	for(int i=0;i<n;i++)
	{
		gotoxy(1,x);
		cout<<a2[i].pno;
		gotoxy(12,x);
		cout<<a2[i].pname;
		gotoxy(23,x);
		cout<<a2[i].fname;
		gotoxy(43,x);
		cout<<a2[i].d1.day<<"/"<<a2[i].d1.mon<<"/"<<a2[i].d1.year;
		gotoxy(53,x);
		cout<<a2[i].d3.day<<"/"<<a2[i].d3.mon<<"/"<<a2[i].d3.year;
		gotoxy(63,x);
		cout<<a2[i].age;
		gotoxy(69,x);
		cout<<a2[i].crime;
		x++;
	}
}
int search1(info a[],int n,char str[])                                    //SEARCH FOR A PRISONER
{
	int flag=-1;
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].pname,str)==0)
		{
			flag=i;
			break;
		}
	}
	return flag;
}
int search2(info a[],int n,date d2)                                       //CHECKING THE DATE
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].d3.year==d2.year)
		{
			if(a[i].d3.mon==d2.mon)
			{
				if(a[i].d3.day==d2.day)
				{
					dat[k]=i;
					k++;
				}
			}

		}
	}
	return k;
}
void modout(int m,info a[])                                               //DISPLAY CHANGED INFORMATION
{
	gotoxy(1,10);
	cout<<"PRISONER";
	gotoxy(3,11);
	cout<<"NO";
	gotoxy(12,10);
	cout<<"NAME";
	gotoxy(23,10);
	cout<<"FATHER'S NAME";
	gotoxy(43,10);
	cout<<"ADM. DATE";
	gotoxy(56,10);
	cout<<"AGE";
	gotoxy(64,10);
	cout<<"CASE DETAILS";
	gotoxy(1,13);
	cout<<a[m].pno;
	gotoxy(12,13);
	cout<<a[m].pname;
	gotoxy(23,13);
	cout<<a[m].fname;
	gotoxy(43,13);
	cout<<a[m].d1.day<<"/"<<a[m].d1.mon<<"/"<<a[m].d1.year;
	gotoxy(56,13);
	cout<<a[m].age;
	gotoxy(64,13);
	cout<<a[m].crime;
}
void modify(info a[],int n)                                               //MODIFY
{
	int ch,m,i,temp;
	char str[25];
	cout<<"\t\t\tMAIN MENU\n\n"
		<<"  1. Change the name"
		<<"\t2. Change the age"
		<<"\t3. Change father's name"
		<<"\n\nenter choice=";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter the incorrect prisoner name=";             //CHANGE PRISONER NAME
		            		 gets(str);
				m=search1(a,n,str);
				if(m!=-1)
				{
					cout<<"enter correct name=";
					gets(a[m].pname);
					cout<<endl;
					modout(m,a);
				}
				else
				{
					cout<<"\nname does not exist..";
				}
				break;
		case 2: cout<<"enter the prisoner name:";                     //CHANGE AGE
				gets(str);
				m=search1(a,n,str);
				if(m!=-1)
				{
					cout<<"incorrect age="<<a[m].age<<endl;
					cout<<"enter correct age=";
					cin>>a[m].age;
					modout(m,a);
				}
				else
				{
					cout<<"\nname does not exist..";
				}
				break;
		case 3: cout<<"Enter the prisoner name=";                      //CHANGE FATHER'S NAME
				gets(str);
				m=search1(a,n,str);
				if(m!=-1)
				{
					cout<<"incorrect father's name="<<a[m].fname<<endl;
					cout<<"enter correct father's name=";
					gets(a[m].fname);
					cout<<endl;
					modout(m,a);
				}
				else
				{
						cout<<"\nname does not exist..";
				}
				break;
	}
}
void main()
{

	clrscr();
	info a[20],a2[20];
	int b=0,flag=0,m,t,z;
	int ch;
	char str[20],prison[20];
	date d2,d3;
	while(b!=1)
	{
		clrscr();
		cout<<"\n\n\n\n\n\n\n\t\tEnter password:";
		b=password();
		if(b==1)
		{
			while(1)
			{
				clrscr();
				cout<<"\t\tWELCOME TO TIHAR PRISONS\n\n"                 //MAIN MENU
					<<"\t1. Input Record\n"
					<<"\t2. Display the List Of The Prisoners\n"
					<<"\t3. Search a Prisoner\n"
					<<"\t4. Change the record\n"
					<<"\t5. Input the Prisoner Released\n"
					<<"\t6. List of the prisoner Released\n"
					<<"\t7. Prisoners released on a particular date\n"
					<<"\t8. Exit"
					<<"\t\t\n\nEnter Your Choice=";
				cin>>ch;
				switch(ch)
				{
					case 1: clrscr();
							cout<<"Enter the number of records=";
							cin>>n;
							flag=1;
							gotoxy(1,4);
							cout<<"PRISONER";
							gotoxy(3,5);
							cout<<"NO";
							gotoxy(12,4);
							cout<<"NAME";
							gotoxy(23,4);
							cout<<"FATHER'S NAME";
							gotoxy(43,4);
							cout<<"ADM. DATE";
							gotoxy(56,4);
							cout<<"AGE";
							gotoxy(64,4);
							cout<<"CASE DETAILS";
							input(a,n);                                 //calling function
							getch();
							break;
					case 2: clrscr();
							if(flag==1)
							{
								gotoxy(1,4);
								cout<<"PRISONER";
								gotoxy(3,5);
								cout<<"NO";
								gotoxy(12,4);
								cout<<"NAME";
								gotoxy(23,4);
								cout<<"FATHER'S NAME";
								gotoxy(43,4);
								cout<<"ADM. DATE";
								gotoxy(56,4);
								cout<<"AGE";
								gotoxy(64,4);
								cout<<"CASE DETAILS";
								output(a,n);
							}
							else
								cout<<"\n\nNo records found... india is free from criminals...please enter it";
							getch();
							break;
					case 3: clrscr();
							if(flag==1)                                 //searching
							{
								cout<<"Enter the name to be searched=";
								gets(str);
								m=search1(a,n,str);
								if(m==-1)
								{
									cout<<"no records found";
								}
								else
								{
									clrscr();
									int i;
									cout<<"PRISONER NO:"<<a[m].pno<<endl
										<<"NAME:"<<a[m].pname<<endl
										<<"FATHER'S NAME:"<<a[m].fname<<endl
										<<"ADM. DATE:"<<a[m].d1.day<<"/"<<a[m].d1.mon<<"/"<<a[m].d1.year<<endl
										<<"AGE:"<<a[m].age<<endl
										<<"CASE DETAILS:"<<a[m].crime;
								}
							}
							else
								cout<<"first input records";
							getch();
							break;
					case 4: clrscr();                                   //modifications
							modify(a,n);
							getch();
							break;
					case 5: clrscr();
							n2=0;
							int y=4;
							if(flag==1)                                 //prisoner released
							{
								cout<<"Enter number of prisoners released=";
								cin>>t;
								for(int i=0;i<t;i++)
								{
									cout<<"Name "<<i+1<<"=";
									gets(prison);
									m=search1(a,n,prison);
									if(m!=-1)
									{
										a2[i]=a[m];
										for(int j=m;j<n;j++)
										{
											a[j]=a[j+1];
										}
										cout<<endl<<prison<<" released on=";
										gotoxy(30,y);
										cin>>a2[i].d3.day;
										gotoxy(32,y);
										cout<<"/";
										gotoxy(33,y);
										cin>>a2[i].d3.mon;
										gotoxy(35,y);
										cout<<"/";
										gotoxy(36,y);
										cin>>a2[i].d3.year;
										n--;
										y+=4;
										cout<<endl;
									}
									else
									{
										cout<<"\nname does not exist..";
										n2--;
									}
								}
								n2+=i;
							}
							else
								cout<<"first input records";
							getch();
							break;
					case 6: clrscr();                                   //list of prisoner released
							if(flag==1)
							{
								gotoxy(1,4);
								cout<<"PRISONER";
								gotoxy(3,5);
								cout<<"NO";
								gotoxy(12,4);
								cout<<"NAME";
								gotoxy(23,4);
								cout<<"FATHER'S NAME";
								gotoxy(43,4);
								cout<<"ADM.";
								gotoxy(43,5);
								cout<<"DATE";
								gotoxy(53,4);
								cout<<"RELEASE";
								gotoxy(53,5);
								cout<<"DATE";
								gotoxy(63,4);
								cout<<"AGE";
								gotoxy(69,4);
								cout<<"CASE";
								gotoxy(69,5);
								cout<<"DETAILS";
								output2(a2,n2);
							}
							else
								cout<<"first input records";
							getch();
							break;
					case 7: clrscr();
							if(flag==1)                                 //prisoner released on particular date
							{
								gotoxy(1,1);
								cout<<"enter the date to be searched:";
								gotoxy(35,1);
								cin>>d2.day;
								gotoxy(37,1);
								cout<<"/";
								gotoxy(38,1);
								cin>>d2.mon;
								gotoxy(40,1);
								cout<<"/";
								gotoxy(41,1);
								cin>>d2.year;
								z=search2(a2,n,d2);
								if(z==0)
								{
									cout<<"no prisoner released on this date";
								}
								else
								{
									for(int i=0;i<z;i++)
									{
										clrscr();
										cout<<"PRISONER NO:"<<a2[dat[i]].pno<<endl
											<<"NAME:"<<a2[dat[i]].pname<<endl
											<<"FATHER'S NAME:"<<a2[dat[i]].fname<<endl
											<<"ADM. DATE:"<<a2[dat[i]].d1.day<<"/"<<a2[dat[i]].d1.mon<<"/"<<a2[dat[i]].d1.year<<endl
											<<"AGE:"<<a2[dat[i]].age<<endl
											<<"CASE DETAILS:"<<a2[dat[i]].crime<<endl<<endl;
									}
								}
							}
							else
								cout<<"first input records";
							getch();
							break;
					case 8: exit(0);                                    //exit
					default: cout<<"incorrect choice";
				}
			}
			getch();
		}
		else
		{
			clrscr();
			cout<<"\n\n\t\tincorrect password...try again";
			getch();
		}
	}
	getch();
}

