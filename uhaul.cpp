#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "uhaul.h"
void uhaul::printuhaul(){
	cout<<"Service: UHAUL";
	cout<<"\nNo. Of Days: "<<days;
	cout<<"\nCapacity: "<<capacity<<" cu.ft";
	cout<<"\nFeul Tank: "<<feultank<<" gallons";
	cout<<"\nCar Towing Applicable: "<<towcar;
}
