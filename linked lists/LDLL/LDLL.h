#include <iostream>
#include "exception.h"

using namespace std;

template <class T>
class DNode
{

public:

	T info;
	DNode<T> *next;
	DNode<T> *prev;

	DNode();
	DNode( T value );
};

template < class T >
DNode<T>::DNode()
	{
		next = prev = NULL;
	}

template < class T >
DNode<T>::DNode( T value)
	{
		info = value;
		next = prev = 0;
	}

template <class T>
class LDLL
{

	DNode<T> *head;

	public:
		
		LDLL()
		{
			head = NULL;
		}

		~LDLL();

		void insertAtHead( const T );
		void insertAtTail( const T );
		void insertBefore( const T, const T );
		void insertAfter ( const T, const T );
		void deleteBefore( const T );
		void deleteAfter ( const T );	
		void deleteAtHead();
		void deleteAtTail();
		void delete_( const T );

		void traverse()
		{
			DNode<T> *p = head;

			while( p )
			{
				cout<<p->info<<endl;

				p = p->next;

			}
		}

};