#include <iostream>
using namespace std;

#include "ListEmpty.h"

template < class T >
struct DNode
{
	T info;
	DNode * next;
	DNode * prev;

	DNode ( )
	{
		next = 0;
		prev = 0;
	}

	DNode ( T val ) : info ( val )
	{
		next = 0;
		prev = 0;
	}
};

template < class T >
class CDLL
{
	private:

		DNode<T> * head;

		bool isEmpty ( ) const;

	public:

		CDLL ( );
		void insertAtHead ( T val );

		void deleteAtHead ( );

		void traverse ( )
		{
			DNode<T> * p ;

			p = head;
			
			if ( head == 0 )
				return;

			do
			{
				cout << p->info  << endl;
				p = p->next ;

			}while ( p != head );
		}
};