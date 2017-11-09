#include "Process.h"
#include "Queue.cpp"
#include "InvalidLength.h"

class Schedular
{
	private:

	Process * processArray;
	int processArrayLength;
	int timeQuantum;

	public:
	
		Schedular ( Process * arr , int length , int time );

		void assignProcess ( );
};
