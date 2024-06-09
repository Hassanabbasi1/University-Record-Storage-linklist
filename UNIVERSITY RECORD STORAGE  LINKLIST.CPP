/*_________________________________________________________
		PROJECT OF UNIVERSITY RECORD STORAGE      		   

//Usman Khan Ghauri(10-arid-129) 
//BSCS-3-B
//bscs-notes.blogspot.com                                  

___________________________________________________________*/

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
struct node
{
	int s_id;
	char s_name[20];
	int s_age;
	long s_aridid;
	node *next;
};



class LinkList
{
	node *head;
   // int count;

	public:
		LinkList()
			{
				head = NULL;
			}

			void insert (int, char[],int,long);
			void display();
			void search();
			int del(int);
};

// END OF CLASS**************

//*********** INSERT FUNCTION START

	LinkList l;
void LinkList::insert(int sid, char name[20], int age, long saridid)
{
	node *ins = new node();

	ins->s_id = sid;
	strcpy(ins->s_name,name);
	ins->s_age = age;
	ins->s_aridid = saridid;

	ins->next = head;
	head = ins;
	cout<<"\n\n Record Successfully Stored\nPress any key to continue";
	getch();
}

//END OF INSERT FUNCTION *****************************

//*********************** SEARCH FUNCTION START


void LinkList:: search()
{
	clrscr();
	int search_id;
	cout<<"------- Search Menu ----------";
	cout<<"\n\n Enter Student ID\n\n";
	cin>>search_id;
	node  *search_node=head;
	while(search_node!=NULL)
	{
		if(search_node->s_id==search_id)
		{
			cout<<"\n Student ID : "<<search_node->s_id<<endl;
			cout<<"\n Student Name : "<<search_node->s_name[20]<<endl;
			cout<<"\n Student Age : "<<search_node->s_age<<endl;
			cout<<"\n Student ARIDReg Number : "<<search_node->s_aridid<<endl;
		}
	search_node=search_node->next;
	}
	getch();
}

//END OF SEARCH FUNCTION ******************

// ********************** DELETE FUNCTION START

int		LinkList::del(int val)
		{
		if(head == NULL)
			{
			cout<<"Link List is empty";
			return 1;
			}
		else if(head->next == NULL)
			{
			if(head->s_id == val)
				{
				node* temp = head;
				int y = head->s_id;
				head = temp->next;
				delete temp;
				return y;
				}
			else
				{
				cout<<"Value not found";
				return -1;
				}
			}
		else
			{
			if(head->s_id == val)
				{
				node* temp = head;
				int y = head->s_id;
				head = temp->next;
				delete temp;
				return y;
				}
			else
				{
				node* current;
				node* previous;
				int y;
				for(current = head; current != NULL && current->s_id != val; previous = current, current = current->next);
				if(current == NULL)
					{
					cout<<"Value not fount";
					return -1;
					}
				else
					{
					y = current->s_id;
					previous->next = current->next;
					delete current;
					return y;
					}
				}
			}
		}

void LinkList:: display()
{
//	clrscr();
	node *display_node;
	display_node = head;
	   if(display_node==NULL)
	   {
	cout<<"	NO DATA IS PRESENT";
	return;
	   }
	while(display_node!=NULL)
	{
		cout<<"\n\nStudent ID :"<<display_node->s_id<<endl;
		cout<<"\nStudent Name :"<<display_node->s_name<<endl;
		cout<<"\nStudent Age :"<<display_node->s_age<<endl;
		cout<<"\nStudent ARID Reg Number :"<<display_node->s_aridid<<endl;
		display_node = display_node->next;
	}
	getch();

}

void insert()
{

	int s_id, s_age;
	long s_aridid;
	char choice, s_name[20];
	do
	{
		clrscr();
		cout<<endl<<endl;
		cout<<" -------------- INSERT MENU --------"<<endl<<endl;
		cout<<"Enter Student ID :";
		cin>>s_id;
		cout<<"\nEnter Student Name : ";
		gets(s_name);
		cout<<"\nEnter Student Age : ";
		cin>>s_age;
		cout<<"\nEnter Student ARID Reg Number: ";
		cin>>s_aridid;

		l.insert(s_id,s_name,s_age,s_aridid);

		cout<<"\n\nEnter More records (Y/N): ";
		cin>>choice;
	}while (choice!='n');
}

//*************  Main Function Began ****************

void main (void)
{

	int ch;
	long d;
	clrscr();
	do
	{
		clrscr();
		cout<<endl<<endl;
		cout<<"-------- MAIN MENU ---------"<<endl<<endl;
		cout<<"1.	INSERT "<<endl<<endl;
		cout<<"2.	SEARCH "<<endl<<endl;
		cout<<"3.	DELETE "<<endl<<endl;
		cout<<"4.	DISPLAY "<<endl<<endl;
		cout<<"5.	EXIT "<<endl<<endl;
		cout<<"Enter Your Choice..: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
					{
						insert();
						break;
					}

			case 2:
					{
						l.search();
						break;
					}
			case 3:
					{
						l.del(d);
						break;
					}
			case 4:
					{
						l.display();
						break;
					}
			case 5:
					{
						break;
					}
		}
	}while (ch!=5);

	   clrscr();
	  getch();
}