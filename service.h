#ifndef SERVICE_H
#define SERVICE_H
#include "available.h"
#include "transport.h"
#include "commute.h"
#include "uhaul.h"
class service
{
	int height;
	int width;
	int length;
	int volume;
//	transport* good;
	bool towcar;
	int capacity;
	int days;
	char choice;
	int feultank;
	string brand;
	string model;
	int bill;
	bool AC;
	bool autom;
	uhaul *u1=new uhaul();
	transport *t1=new transport();
	commute *c1=new commute;
	public:
	void getuhauldetails(string name,string destination, string source);
	void getcommutedetails(string name, string source, string destination);
	void gettransportdetails(string name);
	char getchoice();
	bool isavailable(string brand,string model,available *h);
	available* setbrands();
	void recommendtransport(string name,bool ac,bool autom,available *h, transport *t);
	void recommendcommute(string name,bool ac,bool autom,available *h, commute *c,string source, string destination);
	void billuhaul();
	void billcommute();
	void billtransport();
	int getbill();
	void storebill(int bill);
	void displayuhual();
	void displaycommute();
	void displaytransport();
};

#endif
