#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#define size 18
#include "data.h"
#include "login.h"
#include "map.h"
#include "service.h"
#include "uhaul.h"
                    
int main(){
	dat d1;
	mapping M;
	service S;
	system("cls");
	cout<<setw(65)<<"_________________________________________"<<endl;
	cout<<setw(50)<<"Welcome"<<setw(50)<<endl<<endl;
	cout<<setw(50)<<"Lost In The City"<<setw(50)<<endl;
	cout<<setw(50)<<"Car Rental System"<<setw(50)<<endl;
	cout<<setw(65)<<"_________________________________________"<<endl;
	login l1;
	int s=l1.access();
	if(s==1){
		int c1;
	system("cls");
	cout << "\n\n\t\t-----------WELCOME USER-------------\n\n";
	cout << "Please Sign-In or Sign-Up to Continue\n\n";
	cout<<"\t1.  Sign-In to an Existing Account\n";
	cout<<"\t2.  Create a new Account\n";
	cout<<"\t3.  Exit\n";
	cout << "\nPlease Enter your choice: ";
	cin>>c1;
	int bill=0;
	if(c1==1){
		int n=l1.signin();	
		if(n==1){
			d1.setdata();
			}
			string name=l1.getfullname();
			char cc=S.getchoice();
			system("cls");
			if(cc=='a'){
            	cout << "\n\n\t\t-----------U-Haul Service-------------\n\n";
				S.getuhauldetails(name,M.getdestination(),M.getsource());
				M.take_city();
				bill=M.bill+S.getbill();
				S.storebill(bill);
				S.displayuhual();
			}	
			else
			if(cc=='b'){
				S.gettransportdetails(name);
				M.take_city();
				bill=M.bill+S.getbill();
				S.storebill(bill);
				S.displaytransport();
			}
			else 
			if(cc=='c'){
				S.getcommutedetails(name,M.getsource(),M.getdestination());
				M.take_route();
				bill=M.bill+S.getbill();
				S.storebill(bill);
				S.displaycommute();
			}
		}
	else if(c1==2){
		int n=l1.signup();	
		if(n==1){
			d1.setdata();
			l1.welcome(l1.getname());
			char cc=S.getchoice();
			string name=l1.getfullname();
			if(cc=='a'){
				S.getuhauldetails(name,M.getdestination(),M.getsource());
				M.take_city();
				bill=M.bill+S.getbill();
				S.storebill(bill);
				S.displayuhual();
			}	
			else
			if(cc=='b'){
				S.gettransportdetails(name);
				M.take_city();
				bill=M.bill+S.getbill();
				S.storebill(bill);
				S.displaytransport();
			}
			else 
			if(cc=='c'){
				S.getcommutedetails(name,M.getsource(),M.getdestination());
				M.take_route();
				bill=M.bill+S.getbill();
				S.storebill(bill);
				S.displaycommute();
			}
			}
			}
		else if(c1==3){
		system("pause");
		exit(0);
	}
		}	
	else if(s==2){
		int c1;
		system("cls");
		cout << "\n\n\t\t-----------WELCOME ADMIN-------------\n\n";
		cout<<"\t1.  Search a User's Data\n";
		cout<<"\t2.  Modify a User's Data\n";
		cout<<"\t3.  Display All Data\n";
		cout<<"\t4.  Exit\n";
		cout << "\nPlease Enter your choice: ";
		cin>>c1;
		if(c1==1){
			d1.searchdata();
		}
		else if(c1==2){
		d1.moddata();	
		//d1.sortdata();
		}
		else if(c1==3){
		//display function will be put here	
		d1.display();
		}
		else if(c1==4){
			system("pause");
			exit(0);	
		}
		else {
			cout<<"Wrong entery!!!";
		}
		
	}
	return 0;
}
