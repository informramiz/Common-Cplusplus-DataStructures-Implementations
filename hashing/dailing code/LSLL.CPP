

#include "LSLL.h"

template < class T >
LSLL<T>::LSLL ( )
{
	head = 0;
}

template < class T > 
void LSLL<T>::insertAtHead ( T val ) 
{
	Node<T> * temp = new Node<T> ( val );

	temp->next = head;
	head = temp;
}

template < class T >
void LSLL<T>::deleteAtHead ( )
{
	if ( isEmpty ( ) )
		throw ListEmpty ( "List empty" );
	
	Node<T> * temp = head;
	
	head = head->next;
	delete temp;
}

template < class T >
void LSLL<T>::insertAtTail ( T value )
{
	if ( isEmpty ( ) )
	{
		head = new Node<T>(value);
		return;
	}

	Node<T> * p = head;

	while ( p->next != 0 )
	{
		p = p->next;
	}

	p->next = new Node<T> ( value );
}

template < class T >
void LSLL<T>::deleteAtTail ( )
{
	if ( isEmpty ( ) )
		throw ListEmpty  ( "List empty" );

	Node<T> * p = head;
	Node<T> * prev = head;

	while ( p->next != 0 ) 
	{
		prev = p;
		p = p->next;
	}
	
	delete p;

	prev->next = 0;
}

template < class T > 
void LSLL<T>::insertBefore ( T key , T value )
{
	if ( isEmpty ( ) )
		throw ListEmpty  ( "List empty" );

	if ( head->info == key )
	{
		Node<T> * temp = new Node<T>(value);
		temp->next = head;
		head = temp;

		return;
	}

	Node<T> * p = head;
	Node<T> * prev = p;

	while ( p != 0 && key != p->info )
	{
		prev = p;
		p = p->next;
	}

	if ( p == 0 )
		throw NoMatch ( "key not found" );

	Node<T> * temp = new Node<T>(value);

	temp->next = p;

	prev->next = temp;
}

template < class T >
void LSLL<T>::deleteBefore ( T key )
{
	if ( isEmpty ( ) )
		throw ListEmpty  ( "List empty" );

	if ( head->info == key )
		return;

	if ( head->next->info == key )
	{
		Node<T> * temp = head->next;
		delete head;
		
		head = temp;
		return;
	}

	Node<T>* prev = head;
	Node<T> * p = head->next->next;

	while ( p != 0  && p->info != key )
	{
		p = p->next;
		prev = prev->next;
	}

	if ( p == 0 ) 
		throw NoMatch ( "key not found" );

	delete prev->next;
	prev->next = p;
}

template < class T >
void LSLL<T>::insertAfter ( T key , T value )
{
	if ( isEmpty ( ) )
		throw ListEmpty  ( "List empty" );

	Node<T> * p = isFound ( key );

	if ( p == 0 )
		throw NoMatch ( "No match found" );

	Node<T> * temp = new Node<T>(value);

	temp->next = p->next;
	p->next = temp;
}

template < class T >
void LSLL<T>::deleteAfter ( T key )
{
	if ( isEmpty ( ) )
		throw ListEmpty ( "List empty" );

	Node<T> * p = isFound ( key );

	if( p == 0 )
		throw NoMatch ("No match found" );

	if ( p->next == 0 )
	{
		return;
	}

	Node<T> * temp = p->next;

	p->next = p->next->next;
	delete temp;
}

template < class T >
void LSLL<T>::deleteX ( T key )
{
	if ( isEmpty ( ) )
		throw ListEmpty ( "List is empty" );

	if ( head->info == key )
	{
		Node<T> * temp = head->next;
		delete head;

		head = temp;
		return;
	}

	Node<T> * p = head;
	Node<T> * prev = p;

	while ( p != 0 && p->info != key )
	{
		prev = p;
		p = p->next;
	}

	if ( p == 0 )
		throw NoMatch ( "No match found" );

	prev->next = p->next;
	delete p;
}

template < class T >
LSLL<T>::~LSLL ( )
{
	if ( head != 0 )
	{

		while ( head != 0 )
			deleteAtHead ( );

		head = 0;
	}
}

template < class T >
bool LSLL<T>::isEmpty ( ) const
{
	return head == 0;
}

template < class T >
Node<T> * LSLL<T>::isFound ( T key ) const
{
	Node<T> * p = head;

	while ( p != 0 && p->info != key )
	{
		p = p->next;
	}

	return p;
}

