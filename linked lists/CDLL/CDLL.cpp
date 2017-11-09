#include "CDLL.h"

template < class T >
CDLL<T>::CDLL ( )
{
	head = 0;
}

template < class T >
void CDLL<T>::insertAtHead ( T val )
{
	if ( isEmpty ( ) )
	{
		DNode<T> * p = new DNode<T> ( val );
		head = p;
		
		head->next = head;
		head->prev = head;
		
		return;
	}


	DNode<T> * p = new DNode<T> ( val );

	p->prev = head->prev;
	head->next->prev = p;
	
	head->prev->next = p;
	p->next = head;

	head = p;
}

template < class T > 
void CDLL<T>::deleteAtHead ( )
{
	if ( isEmpty ( ) )
		throw ListEmpty ( "List is empty" );

	DNode<T> * temp = head;

	head->next->prev = head->prev;
	head->prev->next = head->next;

	head = head->next;

	if ( head == temp )
		head = 0;

	delete temp;
}

template < class T >
bool CDLL<T>::isEmpty ( ) const
{
	return head == 0;
}