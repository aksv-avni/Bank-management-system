//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************


#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{
	int acno;
	char name[50];
       unsigned	int deposit;
	char type;
public:
	void create_account();	//function to get data from user
	void show_account();	//function to show data on screen
	void modify();   //function to get new data from user
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report();	//function to show data in tabular format
	int retacno();	//function to return account number
	int retdeposit();	//function to return balance amount
	char rettype();          //function to return type of account
	char retname();          //function to return name
};         //class ends here

void account::create_account()
{
	for(int i=1;i<80;i++)
	 cout<<(char)4;
	 for(i=1;i<80;i++)
	 cout<<(char)4;
	cout<<"\n\n\tEnter The account No.                        :";
	cin>>acno;
	cout<<"\n\n\tEnter The Name of The account Holder         :";
	gets(name);
	cout<<"\n\n\tEnter Type of The account (C/S)              :";
	cin>>type;
	type=toupper(type);
	rev:
	cout<<"\n\n\tEnter The Initial amount\n(>=500 for Saving and >=1000 for current)            :";
	cin>>deposit;
	if((type=='C' && deposit<1000)||(type=='S' && deposit<500))
	  {    cout<<"\n                INSUFFICIENT BALANCE !!  ";
	     goto rev; }
	cout<<"\n\n\t~~~~~~~~~~~~YOUR ACCOUNT IS BEING CREATED...~~~~~~~~~~~~~~\n\n";   delay(1000);
	cout<<"\t~~~~~~~~~~~ACCOUNT SUCCESSFULLY CREATED!!~~~~~~~~~~~~~~~~~";
	 textbackground(YELLOW);
	textcolor(YELLOW);
}

void account::show_account()
{
	cout<<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	cout<<"\n\tAccount No.           : "<<acno;
	cout<<"\n\tAccount Holder Name   : ";
	cout<<name;
	cout<<"\n\tType of Account       : "<<type;
	cout<<"\n\tBalance amount        : "<<deposit;
	cout<<"\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	 textbackground(CYAN);
	textcolor(BLUE);
}


void account::modify()
{       textbackground(WHITE);
	textcolor(BLUE);
	cout<<"\n\tThe account No.                      : "<<acno;
	cout<<"\n\tEnter The Name of The account Holder : ";
	gets(name);
	cout<<"\n\tEnter Type of The account (C/S)      : ";
	cin>>type;
	type=toupper(type);
	rev:
	cout<<"\n\tEnter The amount                     : ";
	cin>>deposit;
		if((type=='C' && deposit<1000)||(type=='S' && deposit<500))
	  {    cout<<"\n                INSUFFICIENT BALANCE !!  ";
	     goto rev; }
}



void account::dep(int x)
{       for(int i=1;i<40;i++)
	 cout<<(char)1<<" ";
	 cout<<"\n";
	deposit+=x;
}

void account::draw(int x)
{
	 for(int i=1;i<40;i++)
	 cout<<(char)1<<" ";
	 cout<<"\n";
	deposit-=x;
}

void account::report()
{
cout<<"\t | "<<acno<<setw(13)<<name<<"           "<<type<<setw(17)<<deposit<<"    |"<<"\n";
}

int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}

char account::retname()
{
       return name[20];
}


//***************************************************************
//    	function declaration
//****************************************************************
int write_account();	//function to write record in binary file
int display_sp(int);	//function to display account details given by user
int modify_account(int);	//function to modify record of file
int delete_account(int);	//function to delete record of file
int display_all();		//function to display all account details
int deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{
	int ch;
	int num;
	clrscr();
	 textbackground(RED);
       textcolor(YELLOW);
	intro();
	back:
	do
	{
		clrscr();
		account ac;
		textbackground(BLUE);
		textcolor(YELLOW);
			for(int i=1;i<40;i++)
		 cout<<(char)4<<" ";

		cout<<"\n\n\t<<<<<<<<<<<<<WELCOME TO THE BANK MANAGEMENT SYSTEM>>>>>>>>>>>>>>>";
		cout<<endl<<"\t\t====================MAIN MENU===================";
		cout<<endl<<"\n\t\t01. NEW ACCOUNT                          ";              delay(50);
		cout<<endl<<"\n\t\t02. DEPOSIT AMOUNT                       ";           delay(50);
		cout<<endl<<"\n\t\t03. WITHDRAW AMOUNT                      ";          delay(50);
		cout<<endl<<"\n\t\t04. BALANCE ENQUIRY                      ";          delay(50);
		cout<<endl<<"\n\t\t05. ALL ACCOUNT HOLDER LIST              ";  delay(50);
		cout<<endl<<"\n\t\t06. CLOSE AN ACCOUNT                     ";         delay(50);
		cout<<endl<<"\n\t\t07. MODIFY AN ACCOUNT                    ";        delay(50);
		cout<<endl<<"\n\t\t08. EXIT                                 ";                     delay(50);
		cout<<endl<<"\n\t\tSelect Your Option (1-8)                 ";
		cin>>ch;
		clrscr();
		textbackground(BLUE);
		textcolor(GREEN);
		switch(ch)
		{
		case 1:
		       int p=write_account();
		       textbackground(BLACK);
			textcolor(YELLOW);
		       if(p==0)
			goto back;
			break;
		case 2:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			p=deposit_withdraw(num, 1);
			 textbackground(YELLOW);
			textcolor(BLUE);
			if(p==0)
			 goto back;
			break;
		case 3:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
		       p=deposit_withdraw(num, 2);
		       textbackground(GREEN);
			  textcolor(BLACK);
		       if(p==0)
			goto back;
			break;
		case 4:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
		       p=display_sp(num);
		       textbackground(BLACK);
			 textcolor(CYAN);
		       if(p==0)
		       goto back;
			break;
		case 5:
		       p=display_all();
		       textbackground(GREEN);
			 textcolor(YELLOW);
		       if(p==0)
		       goto back;
			break;
		case 6:
			cout<<"\n\n\tEnter The account No. to be deleted :\n ";
			cin>>num;
			 textbackground(CYAN);
			  textcolor(BLACK);
		       p=delete_account(num);
			if(p==0)
			goto back;
			break;
		 case 7:
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			textbackground(YELLOW);
			  textcolor(BLUE);
		      p= modify_account(num);
		       if(p==0)
			  goto back;
			break;
		 case 8:
			cout<<"\n\n\t^^^^^^^^^^^^THANKS FOR USING BANK MANAGEMENT SYSTEM !^^^^^^^^^^^^^^";
			textbackground(RED);
			break;
		 default :gotoxy(26,5);
			  cout<<"WRONG OPTION ENTERED !!";
			  textcolor(YELLOW);
			  textbackground(YELLOW);
			   break;
		}
		getch();
    }while(ch>8);

}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{      char r=2,w=5,v=3;
       cout<<"\n\n";
       delay(500);
       for(int i=1;i<41;i++)
      {
	cout<<r<<" "; }

       delay(500);
       printf("\n\n\n\t\t\t\tBANK\n\n");    delay(500);

       printf("\t\t\t      MANAGEMENT\n\n");     delay(500);

       printf("\t\t\t\tSYSTEM\n\n\n");       delay(500);

       for(i=1;i<41;i++)
       {
	cout<<v<<" "<<w<<" ";
		 }
	delay(500);
       printf("\n\t\t\t  MADE BY: AVNI SINGH\n\n");     delay(500);

       printf("\t\t\t SCHOOL:ST TERESA SCHOOL\n\n");    delay(500);

	for(i=1;i<41;i++)
	{
	cout<<r<<" ";
	}
	getch();
}
//***************************************************************
//    	function to write in file
//****************************************************************

int write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
	getch();
	return 0;
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

int display_sp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
    inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"\t\tFile could not be open !! Press any Key...";
		return 0;
	}

    while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{       cout<<"\n\tYOUR CURRENT BALANCE DETAILS ARE :\n\n";
			ac.show_account();
			flag=1;
		}
	}
    inFile.close();


	if(flag==0)
		cout<<"\n\n\t\tAccount number does not exist";
		getch();
		return 0;
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

int modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\t\tFile could not be open !! Press any Key...";
		return 0;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\tEnter The New Details of account :"<<endl;
			cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
			ac.modify();
			cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
		    File.write((char *) &ac, sizeof(account));
		    cout<<"\n\t\t\t Record Updated !";
		    found=1;
		  }
	}
	File.close();
	if(found==0)
		cout<<"\n\n\t\t Record Not Found! ";
		getch();
	      return 0;
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


int delete_account(int n)
{       int c=0;
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
		else
		 c=1;
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	if(c==0)
	cout<<"                           RECORD DOES NOT EXISTS !!";
	else
	cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@ Record Deleted ..!! @@@@@@@@@@@@@@@@@@@@@@@";
	getch();
	return 0;
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

int display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	cout<<"\n\t ^^^^^^^^^^^^^^^^ACCOUNT HOLDER LIST^^^^^^^^^^^^^^^^^\n\n";
	cout<<"\t ====================================================\n";
	cout<<"\t A/c no.      NAME           Type          Balance   \n";
	cout<<"\t ====================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
	getch();
	return 0;
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

int deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
    while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSIT AMOUNT: ";
				cout<<"\n\n\tEnter The amount to be deposited :";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\n\tEnter The amount to be withdrawn :";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
				     {	cout<<"                   Insufficient balance !!";
					cout<<"\n\tEnter The amount to be withdrawn again : ";
					cin>>amt;
					  }
				else
					ac.draw(amt);
		      }
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			char a=2;
			cout<<"\n\n\t\t   "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<" RECORD UPDATED ! "<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
			found=1;
	       }
	 }
    File.close();
	if(found==0)
		cout<<"\n\n\t\t Record Not Found!! ";
		getch();
		return 0;
}




//***************************************************************
//    			END OF PROJECT
//***************************************************************