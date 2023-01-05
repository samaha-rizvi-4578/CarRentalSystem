#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "login.h"

login::login()
{
}
void login::settype(){
	cout<<setw(50)<<"Are you User or Admin?\n";
	cout<<setw(50)<<"Enter your Domain: ";
	cin>>type;
	//this->type=type;
}
void login::setpassword(){
	char ch;
	password="";
	cout<<endl<<setw(50)<<"Enter Password: ";
	ch=_getch();
	while(ch !=13){
		password.push_back(ch);
		cout<<'*';
		ch=_getch();
	}
	this->password=password;
}
string login::gettype(){
	return type;
}
string login::getpassword(){
	return password;
}
int login::signin(){
			int n=0;
			oncemore:
			string uname,line;
			fstream file1;
			int flag=0;
			int pos=0;
			system("cls");
			cout<<setw(50)<<"Sign -In\n";
			cout<<"\nPlease Enter the User Name: ";
			cin>>name;
			file1.open("user.txt",ios::in);
			file1.seekg(0,ios::beg);
			while(file1){
				getline(file1,line);
				pos=line.find(" ");
				uname=line.substr(0,pos);
				line=line.substr(pos+1,line.length());
				if(uname==name){
					flag=1;
					cout<<line;
					break;
				}
			}
			file1.close();
			if(flag==1){
				for(int i=0;i<3;i++){//3 tries for password
					setpassword();
					cout<<endl<<getpassword();
					if(getpassword()==line){
						cout<<"\nSign-In Succesful\n";
						welcome(uname);
						break;
					}
					else{
						cout<<"\nSorry! Incorrect Password";
					}	
				}
			}
			else{
				cout<<"\nIncorrect User Name\n";
				cout<<"\nPress <1> to Sign-Up\nOR\nPress <2> to Sign-In Again\n";
				int choice;
				cin>>choice;
				switch (choice){
					case 1:{
						n=signup();
						//cout<<"\nwe will go to sign up\n";//sign up
						break;
					}
					case 2:{
						goto oncemore;//sign in
						break;
					}
					default:{
						cout<<"Wrong choice";
						return 0;
						break;
					}
				}
			}
			return n;
		}
int login::access(){
	again:
	settype();
	setpassword();
	if(getpassword()=="boss" && gettype()=="admin" ){
		cout<<"\nAdmin access granted!\n";
		return 2;
	}
	else if(getpassword()=="user" && gettype()=="user"){
		cout<<"\nUser access granted!\n";
		return 1;
	}
	else{
		char choice;
		cout<<"\nSorry Wrong choice\nDo You Want To Enter Again?";
		cout<<"\nPress 'y' to enter Again\nOR \n press 'n' to exit\n";
		cin>>choice;
		if(choice=='y'){
			goto again;
		}
		else {
			return 0;	
		}
	}
}
int check(string a)
{
	int flag=0;
	string b;
	fstream f1;
	f1.open("user.txt",ios::in);
	while(f1)
	{
		f1 >> b;
		if(b==a)
		{
			flag = 1; break;
		}
	}
	f1.close();
	if(flag==1)
	{
		cout << "\nSorry! Username already exists. \nPlease try another: ";
		return 1;
	}
	return 0;
}

int login::signup(){
	string uname, line;
	int flag;
	fstream f1;
	f1.open("user.txt",ios::in|ios::out|ios::app);
	system("cls");
	cout<<setw(50)<<"Sign-Up\n";
	retry:
	cout<<setw(50)<<"Please Enter User name: ";
	cin>>name;
	flag=check(name);
	if(flag==1){
		goto retry;
	}
	//cout<<"\nPlease Enter Password: ";
	setpassword();
	f1<<"\n"<<name<<" "<<getpassword();
	cout<<"\nAccount created Succesfully\n";
	return 1;
	f1.close();
	system("pause");
	return 0;
	
}
void login::welcome(string uname){
	fstream f3;
	string line,fname,lname;
	int pos=0,flag=0;
	f3.open("data.txt",ios::in);
	f3.seekg(0,ios::beg);
			while(f3){
				getline(f3,line);
				pos=line.find(" ");
				fname=line.substr(0,pos);
				line=line.substr(pos+1,line.length());
				pos=line.find(" ");
				lname=line.substr(0,pos);
				line=line.substr(pos+1,line.length());
				if(uname==fname || uname==lname){
					flag=1;
					break;
				}
			}
			f3.close();
			if(flag==1){
			system("cls");
			cout<<"\n\n--------------Welcome "<<fname<<" "<<lname<<"--------------\n\n";	
			}
			this->fullname=fname+" "+lname;
			
}
string login::getfullname(){
	return fullname;
}
string login::getname(){
	return name;
}
