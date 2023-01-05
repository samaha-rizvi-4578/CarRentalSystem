#ifndef UHAUL_H
#define UHAUL_H

class uhaul
{
	public:
	int height;
	int width;
	int length;
	int volume;
	int feultank;
	bool towcar;
	int capacity;
	uhaul *node;
	int days;
	
	void printuhaul();
};

#endif
