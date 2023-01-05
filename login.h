#ifndef LOGIN_H
#define LOGIN_H

class login
{	string type;
	string password;
	string fullname;
	string name;
	public:
		login();
		void settype();
		void setpassword();
		string gettype();
		string getpassword();
		string getfullname();
		int signin();
		int access();
		int signup();
		void welcome(string uname);
		string getname();
	protected:
};

#endif
