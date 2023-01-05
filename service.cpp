#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "service.h"
#include "available.h"
#include "uhaul.h"
#include "transport.h"
#include "commute.h"

void service::getuhauldetails(string name,string destination, string source){
			cout<<"\nBook U-Haul\n";
			cout<<"For how many days you want it?\t";
			cin>>days;
			cout<<"\n\tEnter height..\t";
			cin>>height;
			cout<<"\n\tEnter Width..\t";
			cin>>width;
			cout<<"\n\tEnter length..\t";
			cin>>length;
			cout<<"\n\tShould it be a towingcar..\t";
			cin>>towcar;
			uhaul* temp=new uhaul();
   	 	    temp->length=length;
   	        temp->height=height;
   	        temp->width=width;
   	        volume=length*height*width;
   	        temp->volume=volume;
   	        temp->days=days;
   	        if(temp->volume <= 402){
   	        this->capacity=402;
			temp->capacity=402;
		}
			else if(temp->volume <= 764){
				
			this->capacity=764;
		}
			else if(temp->volume <= 1016){
				this->capacity=1016;
		}
			else if(temp->volume <= 1688){
			this->capacity=1688;
		}
	    if( temp->capacity == 402){
			this->feultank=31;
		}
			else if(temp->volume == 764){
			this->feultank=40;
		}
			else if(temp->volume == 1016){
			this->feultank=40;
		}
			else if(temp->volume == 1688){
			this->feultank=60;
		}
		temp->capacity=capacity;
		temp->feultank=feultank;
		temp->towcar=towcar;
		system("cls");
		this->u1=temp;
		billuhaul();
		//temp->printuhaul();
		fstream f1;
		f1.open("service.txt", ios::out | ios::app);
		f1 <<name<<" U-haul";
		f1.close();
		fstream f2;
		f2.open("uhaul.txt", ios::out | ios::app);
		f2<<name<<" "<< temp->days <<" "<< temp->capacity<<" "<<temp->feultank<<" "<<temp->towcar<<" "<<source<<" "<< destination<<endl;
		f2.close();
}
void service::getcommutedetails(string name,string source, string destination){
	cout<<"\nBook A Ride (Commute)\n";
	cout<<"\n\tPress 1 for a AC car..\t";
	cin>>AC;		     
	cout<<"\n\tPress 1 for Auto..\t";
	cin>>autom;
	commute *c=new commute();
	available *h=new available();
	h=setbrands();
	 if(c !=NULL){
		 c->AC=AC;
		 c->autom=autom;
		recommendcommute(name,AC,autom,h,c,source,destination);
		}
		billcommute();
}
void service::gettransportdetails(string name){
	cout<<"\nBook Transport\n";
	cout<<"For how many days you want it?\t";
	cin>>days;
	cout<<"\n\tPress 1 for a AC car..\t";
	cin>>AC;		     
	cout<<"\n\tPress 1 for Auto..\t";
	cin>>autom;
	transport *t=new transport();
	available *h=new available();
	h=setbrands();
	 if(t !=NULL){
		 t->AC=AC;
		 t->autom=autom;
		 t->days=days;
		recommendtransport(name,AC,autom,h,t);
		billtransport();
		
		}
}
char service::getchoice(){
		cout<<"\n\n---------Choose The Service---------\n\n";
		cout<<"<a> U-haul\n";
		cout<<"<b> Transport\n";
		cout<<"<c> Commute\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		return choice;
	}

bool service::isavailable(string brand, string model, available *h){
	while(h != NULL){
		if(brand == h->brand){
			if(model == h->model){
				return true;
			}
			else{
				cout<<"\n\tUnfortunately, this car has been booked\n";
				return false;
			}
		}
		else{
			cout<<"\n\tSorry! we donot have this brand\n";
			return false;
		}
		h= h->next;
	}
}	

available* service::setbrands(){
	        available* head=new available();
		    available* first=new available();
		    available* second=new available();
		    available* third=new available();
		    available* fourth=new available();
		    available* fifth=new available();
		    available* six=new available();
		    available* seven=new available();
		    
		    head->brand= "toyota";
		    head->model= "corolla";
		    head->AC=1;
		    head->autom=0;
		    first->brand= "suzuki";
		    first->model= "swift";
		    first->AC=1;
		    first->autom=0;
		    second->brand= "changan";
		    second->model= "alsvin";
		    second->AC=1;
		    second->autom=1;
		    third->brand= "toyota";
		    third->model= "mira";
		    third->AC=0;
		    third->autom=1;
		    fourth->brand= "toyota";
			fourth->model= "yaris";
		    fourth->AC=1;
		    fourth->autom=1;
		    fifth->brand= "suzuki";
			fifth->model= "mehran";
		    fifth->AC=0;
		    fifth->autom=0;
		    six->brand= "suzuki";
			six->model= "alto";
		    six->AC=0;
		    six->autom=0;
		    seven->brand= "honda";
		    seven->model= "civic";
		    seven->AC=0;
		    seven->autom=1;
		    
		    head->next=first;
		    first->next=second;
		    second->next=third;
		    third->next=fourth;
		    fourth->next=fifth;
		    fifth->next=six;
		    six->next=seven;
		    seven->next=NULL;
		    
		    return head;
}	
void service::recommendtransport(string name,bool ac, bool autom,available *h,transport *t){
	int i=0,j=0,k=1;
	int choice;
			string arr[3][2];
			while(h != NULL){
				if(t->AC == h->AC  && t->autom== h->autom){
					
					cout<<"\n\t"<<k<<"\t"<<h->brand<<"\t"<<h->model<<"\t\n";
					arr[i][j] = h->brand;
					arr[i][j+1] = h->model;
					i++;
					k++;
				}
				h= h->next;
			
			}
			cout<<"\n\tEnter your choice..\t";
			cin>>choice;
			for( i=0,j=0;i<3;i++){
				if(choice == i+1){
					t->brand = arr[i][j];
					t->model = arr[i][j+1];
					break;
				}
			}
			this->t1=t;
		fstream f1;
		f1.open("service.txt", ios::out | ios::app);
		f1 << name<<" transport";
		f1.close();
		fstream f2;
		f2.open("transport.txt", ios::out | ios::app);
		f2<<name<<" "<< t->model<<" "<<t->brand<<" "<<t->AC<<" "<<t->autom<<" "<< t->days<<endl;
		f2.close();
}	
void service::recommendcommute(string name,bool ac, bool autom,available *h,commute *c,string source, string destination){
	int i=0,j=0,k=1;
	int choice;
			string arr[3][2];
			while(h != NULL){
				if(c->AC == h->AC  && c->autom== h->autom){
					
					cout<<"\n\t"<<k<<"\t"<<h->brand<<"\t"<<h->model<<"\t\n";
					arr[i][j] = h->brand;
					arr[i][j+1] = h->model;
					i++;
					k++;
				}
				h= h->next;
			
			}
			cout<<"\n\tEnter your choice..\t";
			cin>>choice;
			for(i=0;i<3;i++){
				if(choice == i+1){
					c->brand = arr[i][0];
					c->model = arr[i][1];
					break;
				}
				
			}
			this->c1=c;
			fstream f1;
		f1.open("service.txt", ios::out | ios::app);
		f1 <<name<<" commute";
		f1.close();
		fstream f2;
		f2.open("commute.txt", ios::out | ios::app);
		f2<< name <<" "<< c->model<<" "<<c->brand<<" "<<c->AC<<" "<<c->autom<< " " <<source<<" "<< destination<<endl;
		f2.close();
}
void service::billuhaul(){
	if(u1->capacity==402){
		this->bill=8;
	}
	else
	if(u1->capacity==764){
		this->bill=10;
	}
	else
	if(u1->capacity==1016){
		this->bill=12;
	}
	else{
		this->bill=14;
	}
	if(u1->towcar==1){
		bill+=10;
	}
	this->bill=bill*u1->days;
}
void service::billcommute(){
	if(c1->AC==1){
		this->bill=10;
	}
	else{
		this->bill=5;
	}
	if(c1->autom==1){
		this->bill=bill+10;
	}
	else{
		this->bill=bill+5;
	}
}
void service::billtransport(){
		if(c1->AC==1){
		this->bill=10;
	}
	else{
		this->bill=5;
	}
	if(c1->autom==1){
		this->bill=bill+10;
	}
	else{
		this->bill=bill+5;
	}
	this->bill=bill*t1->days;
}
int service::getbill(){
	return bill;
}
void service::storebill(int bil){
	fstream f1;
	f1.open("service.txt", ios::out | ios::app);
		f1 <<" "<<bil<< endl;
		f1.close();
		this->bill=bil;
}
void service::displayuhual(){
	u1->printuhaul();
	cout<<"\nTotal Bill: "<<getbill()<<" $";
}
void service::displaycommute(){
	c1->printcommute(c1);
	cout<<"\nTotal Bill: "<<getbill()<<" $";
}
void service::displaytransport(){
	t1->printtransport(t1);
	cout<<"\nTotal Bill: "<<getbill()<<" $";
}
