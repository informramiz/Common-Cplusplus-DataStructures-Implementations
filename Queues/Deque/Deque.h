#include <iostream>
using namespace std;

#include "InvalidCapacity.h"
#include "DequeEmpty.h"
#include "DequeFull.h"


template < class T >
class Deque
{
	private:

		int capacity;
		int rear;
		int front;

		T * data;

	public:

		Deque ( int size = 10 );
		~Deque ( );

		void insertAtTail ( T value );
		T deleteAtTail ( );

		void insertAtHead ( T value );
		T deleteAtHead ( );

		bool isFull ( ) const;
		bool isEmpty ( ) const;

		int getElements ( ) const;
};