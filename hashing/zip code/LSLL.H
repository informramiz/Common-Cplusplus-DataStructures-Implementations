#include <iostream>
#include <stdexcept>
using namespace std;

#include "ListEmpty.h"
#include "NoMatch.h"

template < class T >
class Node
{
	public:

		Node * next;
		T info;

		Node ( );
		Node ( T val );
};

template < class T >
Node<T>::Node ( )
{
	next = 0;
	info = 0;
}

template < class T >
Node<T>::Node ( T val )
{
	next = 0;
	info = val;
}

template < class T >
class LSLL
{
	private:

		Node<T> * head;

		bool isEmpty ( )const;

	public:

		LSLL ( );
		~LSLL ( );

		void insertAtHead ( T val );
		void deleteAtHead ( ) ;

		void insertAtTail ( T val );
		void deleteAtTail ( );

		void insertBefore ( T key , T val );
		void deleteBefore ( T key );

		void insertAfter ( T key , T val );
		void deleteAfter ( T key );

		void deleteX ( T key );
		Node<T>  * isFound ( T key ) const;

		void traverse ( ) const
		{
			Node<T> * p = head;

			while ( p != 0 )
			{
				cout << p->info << endl;
				p = p->next ;
			}
		}


};