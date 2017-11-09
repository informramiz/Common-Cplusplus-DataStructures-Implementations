#include <iostream.h>
#include "vector.h"



class HeapTrack
{
	private:

		typedef const void * raw;
		static Vector < raw > addresses;

		bool isOnHeap ( void * ) const;

	public:

		virtual ~HeapTrack ( ) = 0;

		static void * operator new ( size_t );
		static void operator delete ( void * ptr );

		bool isOnHeap ( ) const;
	
};

