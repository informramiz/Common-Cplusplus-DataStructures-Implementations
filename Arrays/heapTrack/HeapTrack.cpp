#include "HeapTrack.h"


typedef const void * ra;
Vector<ra> HeapTrack::addresses  ;

HeapTrack::~HeapTrack ( ) 
{

}

void * HeapTrack::operator new ( size_t size )
{
	void * rawPtr = ::operator new ( size );

	addresses.push ( rawPtr );

	return rawPtr;
}

void HeapTrack::operator delete ( void * ptr )
{
	if ( addresses.find ( ptr ) != - 1 )
	{
		addresses.remove ( ptr );
		::operator delete ( ptr );
	}
	else
		cout << "Unknown pointer" << endl;
}


bool HeapTrack::isOnHeap ( void * ptr ) const
{
	for ( int i = 0 ; i < addresses.getCapacity ( ) ; i ++ )
		if ( ptr == addresses[i] )
			return true;

	return true;
}

bool HeapTrack::isOnHeap ( ) const
{
	int index = addresses.find ( this );

	return index != -1;
}