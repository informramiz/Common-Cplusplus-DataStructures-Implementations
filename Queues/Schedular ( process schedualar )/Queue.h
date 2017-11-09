#include <iostream>
using namespace std;

#include "InvalidCapacity.h"
#include "QueueEmpty.h"
#include "QueueFull.h"


template < class T >
class Queue
{
	private:

		int capacity;
		int rear;
		int front;

		T * data;

	public:

		Queue ( int size = 10 );
		~Queue ( );

		void enQueue ( T value );
		T deQueue ( ) ;

		bool isFull ( ) const;
		bool isEmpty ( ) const;

		int getElements ( ) const;
};