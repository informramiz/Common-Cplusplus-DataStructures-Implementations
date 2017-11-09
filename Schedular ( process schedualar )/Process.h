#include <string>
using namespace std;

class Process
{
	public:

	int processId;
	string processName;
	int processExeTime;

	Process ( int id = 1 , string name = "Notepade" , int time = 10 );
};