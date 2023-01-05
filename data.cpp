#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cwchar>
#include <windows.h>
using namespace std;
#include "data.h"
void dat::setdata(){
	system("cls");
	cout<<"\nEnter First Name: ";
	cin>>fname;
	this->setfname(fname);
	cout<<"\nEnter Last Name: ";
	cin>>lname;
	this->setlname(lname);
	cout<<"\nEnter Your CNIC No: ";
	cin>>cnic;
	this->setcnic(cnic);
	cout<<"\nEnter Your Phone No: ";
	cin>>contact;
	this->setcontact(contact);
	storedata();
}
void dat::setfname(string fname){
	this->fname=fname;
}
void dat::setlname(string lname){
	this->lname=lname;
}
void dat::setcontact(string contact){
	this->contact=contact;
}
void dat::setcnic(string cnic){
	this->cnic=cnic;
}
string dat::getfname(){
	return fname;
}
string dat::getlname(){
	return lname;
}
string dat::getcontact(){
	return contact;
}
string dat::getcnic(){
	return cnic;
}
void dat::getdata(){
	cout<<"\nCustomer Data\n\n";
	cout<<"\nFirst Name: "<<getfname();
	cout<<"\nLast Name: "<<getlname();
	cout<<"\nContact: "<<getcontact();
	cout<<"\nCNIC No: "<<getcnic();
}
void dat::storedata(){
	fstream f2;
	f2.open("data.txt",ios::app);
		f2<<"\n"<<getfname()<<" ";
		f2<<getlname()<<" ";
		f2<<getcnic()<<" ";
		f2<<getcontact();
	f2.close();	
	//sortdata();
}
void dat::searchdata(){
	string line;
	string first,last,cn,no,fName,lName;
	char choice;
	int flag;
	int pos=0;
	system("color F0");
	system("cls");
	fstream file2;
	file2.open("data.txt",ios::in);
	
	do{
		cout << "\n\n\t\t-----------Search User Data-------------\n\n";
			flag=0;
			file2.seekg(0,ios::beg);
		
				cout<<endl<<"Enter First Name: ";
				cin>>first;
				cout<<"Enter Last Name: ";
				cin>>last;
				if(file2.is_open()){
				
				while (file2)
				{
				
					getline (file2,line);
					pos=line.find(" ");
					fName=line.substr(0,pos);
					line = line.substr(pos+1,line.length());
					pos=line.find(" ");
					lName=line.substr(0,pos);
					line = line.substr(pos+1,line.length());
					cn=line.substr(0,pos);
					line = line.substr(pos+1,line.length());
					no = line;
					if(fName==first && lName==last)
					{
					
						cout<<"\nFound!!"<<endl;
						cout<<endl<<"First Name: "<<fName<<endl;
						cout<<"Last Name: "<<lName<<endl;
						cout<<"CNIC Number: "<<cn<<endl ;
						cout<<"Phone Number: "<<no<<endl ;
						flag=1;
						break;
					}
				}
			
				}
			else
			{
				
				cout << "Unable to open file"<<endl;
				exit(0);
			}
			if(flag==0)
			{
				
				cout<<"User Data Not Found"<<endl;
			}
			cout << "\nDo you want to search another?(y/n) ";
			cin >> choice;
		
			system("cls");
	}while(choice=='y');
	
	file2.close();

	return;
}
void dat::moddata()
{
	system("cls");
	system("color F0");
	string line, fName, lName, LName, FName, no,cn;
    int pos=0,flag=0;
    cout << "\n\n\t\t-----------Modify User Data-------------\n\n";
    afgh:
    cout << "Please enter the first name of record you want to modify: ";
    cin>>FName;
    cout << "\nPlease enter the last name of record you want to modify: ";
    cin>>LName;
    
    ifstream myfile;
    ofstream temp;
    myfile.open("data.txt");
    temp.open("temp.txt");
    
    while (!myfile.eof())
    {
  	getline (myfile,line);
  	
	pos=line.find(" ");
	fName=line.substr(0,pos);
	
	line = line.substr(pos+1,line.length());
	pos=line.find(" ");
	lName=line.substr(0,pos);
	
	line = line.substr(pos+1,line.length());
	cn=line.substr(0,pos);
	
	line = line.substr(pos+1,line.length());
	no = line;
	
	if(!(fName==FName && lName==LName))
	{
	
      	temp << fName <<" "<< lName <<" "<< cn<<" "<<no<< endl;
      
      }
    else
    {
    		flag++;
    		break;
		}
		
  }
  ofstream temp2;
  	temp2.open("t2.txt");
  while(!myfile.eof()){
  	
  	getline(myfile,line);
  	temp2<<line<<endl;
  }
  temp2.close();
  if(flag==0)
  {
  	 cout<<"\nRecord not found!! Try Again.\n\n";
	 goto afgh;
  }
  myfile.close();
  temp.close();
  remove("data.txt");
  rename("temp.txt", "data.txt");


	ifstream temp3;
	temp3.open("t2.txt");
	string fname2, lname2, no2,cn2;
	fstream myfile2("data.txt",ios::app);
	cout << "\n\nEnter New First Name : ";
	cin >> fname2;
	myfile2 << fname2 << " ";
	cout << "\nEnter New Last Name : ";
	cin >> lname2;
	myfile2 << lname2 << " ";
	cout << "\nEnter New CNIC Number : ";
	cin >> cn2;
	myfile2 << cn2<< " ";
	cout << "\nEnter New Phone Number : ";
	cin >> no2;
	myfile2 << no2<<endl;
	while(!temp3.eof()){
		getline(temp3,line);
		myfile2 <<line <<endl;
	}
	myfile2.close();
	temp3.close();
	remove("t2.txt");
	return;
}
void dat::display(){
	string line;
	string first,last,cn,no,fName,lName;
	int pos=0;
	system("color F0");
	system("cls");
	fstream file2;
	file2.open("data.txt",ios::in);
		cout << "\n\n\t\t-----------Display User Data-------------\n\n";
						file2.seekg(0,ios::beg);
				if(file2.is_open()){
				
				while (! file2.eof() )
				{
				
					getline (file2,line);
					pos=line.find(" ");
					fName=line.substr(0,pos);
					setfname(fName);
					line = line.substr(pos+1,line.length());
					pos=line.find(" ");
					lName=line.substr(0,pos);
					setlname(lName);
					line = line.substr(pos+1,line.length());
					cn=line.substr(0,pos);
					setcnic(cn);
					line = line.substr(pos+1,line.length());
					no = line;
					setcontact(no);
					getdata();
				}
			
				}
			else
			{
				
				cout << "Unable to open file"<<endl;
				exit(0);
			}
	file2.close();

	return;
}
//void dat::sortdata(){
//	fstream s1;
//	fstream s2;
//	cout<<"\nexception a";
//	s1.open("user.txt",ios::in |ios::out);
//	s2.open("data.txt", ios::in);
//	string s1s[20];
//	string s2s[20];//=NULL;
//	string line;
//	cout<<"\nexception b";
//	s1.seekg(0,ios::beg);
//	s2.seekg(0,ios::beg);
//	int i=0;
//	//sort data in txt file 
//	while(!s1.eof()){
//		getline(s1,line);
//		s1s[i]=line;
//		++i;
//	}
//	cout<<"\nexception c";
//	int n=i;
//	cout<<n;
//    i=0;
//	while(!s2.eof()){
//		getline(s2,line);
//		s2s[i]=line;
//		++i;
//	}
//	cout<<"\nexception 1";
//	quickSort(s1s,0,n,s2s);
//	cout<<"\nexception 2";
//	//i=0;
//	s1.close();
//	s2.close();
//	remove("user.txt");
//	remove("data.txt");
//	//checek
//	for(i=0;i<=n;i++){
//		cout<<s1s[i]<<endl;
//		cout<<s2s[i]<<endl;
//	}
//	
//	ofstream s11;
//	ofstream s22;
//	s11.open("user.txt");
//	s22.open("data.txt");
//	for(i=0;i<=n;i++){
//		cout<<"\nexception "<<i+10;
//		line=s1s[i];
//		s11<<line;
//		s11<<"\n";
//		line=s2s[i];
//		s22<<line;
//		s22<<"\n";
//	}
//	s1.close();
//	s2.close();	
//}
//int dat::partition(string *arr, int low, int high,string *sar)
//{
//
//	string pivot = arr[low];
//
//	int count = 0;
//	for (int i = low + 1; i <= high; i++) {
//		if (arr[i] <= pivot)
//			count++;
//	}
//
//	// Giving pivot element its correct position
//	int pivotIndex = low + count;
//	swap(arr[pivotIndex], arr[low]);
//	swap(sar[pivotIndex], sar[low]);
//
//	// Sorting left and right parts of the pivot element
//	int i = low, j = high;
//
//	while (i < pivotIndex && j > pivotIndex) {
//
//		while (arr[i] <= pivot) {
//			i++;
//		}
//
//		while (arr[j] > pivot) {
//			j--;
//		}
//
//		if (i < pivotIndex && j > pivotIndex) {
//			i++;
//			j--;
//			string temp=arr[i];
//			arr[i]=arr[j];
//			arr[j]=temp;
//			//swap(arr[i++], arr[j--]);
//			//swap(sar[i++], sar[j--]);
//		   temp=sar[i];
//			sar[i]=sar[j];
//			sar[j]=temp;
//		}
//	}
//
//	return pivotIndex;
//}
//void dat::quickSort(string *arr, int low, int high,string *sar){
//	// base case
//	if (low >= high)
//		return ;
//
//	// partitioning the array
//	int p = partition(arr, low, high,sar);
//
//	// Sorting the left part
//	quickSort(arr, low, p - 1,sar);
//
//	// Sorting the right part
//	quickSort(arr, p + 1, high,sar);
//	}
