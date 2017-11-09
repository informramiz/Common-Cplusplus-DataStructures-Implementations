# include <string>

using namespace std;

class Excaption
{
	char* msg;

public:

	Excaption(const char*);
	Excaption(const Excaption &);
	
	char* getMsg();
	void  addMsg(const char *);

};


		
	
		// 2N + 3

Excaption :: Excaption(const char *msg1)
{
	int a = strlen(msg1);	

	msg = new char [a];

	strcpy(msg, msg1);	// 2N + 1

}

		// 2N + 2
	
Excaption :: Excaption(const Excaption &obj)
{
	msg = new char [strlen(obj.msg)];

	strcpy(msg, obj.msg);	// 2N + 1

}
char* Excaption :: getMsg()
{
	return msg;
}

	// 4N + 7

void  Excaption :: addMsg(const char *msg1)
{
	int a  = strlen(msg1);
	int b  = strlen(msg);

	char *temp = new char [a];

		strcpy(temp, msg);		// 2N + 1

		strncat(temp, msg1, a);	// 2N + 1
		
		msg = temp;

		temp = NULL;

}