#ifndef AVAILABLE_H
#define AVAILABLE_H

class available
{
	public:
		public:
	    string model;
    	string brand;
    	bool AC;
    	bool autom;
	    available *next;
	    
	available push(available **n,string brand,string model,bool AC,bool autom);
	protected:
};

#endif
