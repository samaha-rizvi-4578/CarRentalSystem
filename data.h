#ifndef DATA_H
#define DATA_H
class dat{
	string contact;
	string fname, lname;
	string cnic;
	public:
	void setdata();
	void setfname(string fname);
	void setlname(string lname);
	void setcontact(string contact);
	void setcnic(string cnic);
	void getdata();
	string getfname();
	string getlname();
	string getcontact();
	string getcnic();
	void storedata();
	void searchdata();
	void moddata();
	void display();
//	void sortdata();
//	int partition(string *arr, int low, int high,string *sar);
//	void quickSort(string *arr, int low, int high,string *sar);
};
#endif 
