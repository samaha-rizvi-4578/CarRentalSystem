#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "commute.h"

void commute::printcommute(commute *c){
			cout<<"Service: Commute";
			cout<<"\nBRAND: "<<c->brand;
			cout<<"\nMODEL: "<<c->model;
			cout<<"\nAC/non-AC: ";
			if(c->AC==1){
				cout<<"AC";
				 
				}
			   else {
				cout<<"non- AC"; 
			    }
			cout<<"\nAutomatic/Manual: ";
			if(c->autom==1){
				cout<<"Auto";
			 }
			   else {
				cout<<"Manual";
				}
}
