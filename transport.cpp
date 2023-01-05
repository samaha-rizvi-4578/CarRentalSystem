#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "transport.h"

void transport::printtransport(transport *t){
	        
	        cout<<"Service: Transport\n";
	        cout<<"\nDays: "<<t->days; 
			cout<<"\nBRAND: "<<t->brand;
			cout<<"\nMODEL: "<<t->model;
			cout<<"\nAC/non-AC: ";
			if(t->AC==1){
				cout<<"AC";
				 
				}
			   else {
				cout<<"non- AC"; 
			    }
			cout<<"\nAutomatic/Manual: ";
			if(t->autom==1){
				cout<<"Auto";
			 }
			   else {
				cout<<"Manual";
				}
}
