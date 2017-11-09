#include "HeapTrack.h"

class NewHeapStack : public HeapTrack
{
	public:

		NewHeapStack ( )
		{}
};

void main ( )
{
	NewHeapStack s;
	NewHeapStack * sPtr = new NewHeapStack;

	cout << sPtr->isOnHeap ( );
	cout << s.isOnHeap ( );

	delete &s;
}
