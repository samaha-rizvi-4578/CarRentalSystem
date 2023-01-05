#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "available.h"

available available::push(available **n,string brand,string model,bool AC,bool autom){
		available* temp = new available();  
	    temp->brand=brand;
	    temp->model=model;
	    temp->AC=AC;
	    temp->autom=autom;
	    
		temp->next = (*n);   
		(*n)= temp;      
}
