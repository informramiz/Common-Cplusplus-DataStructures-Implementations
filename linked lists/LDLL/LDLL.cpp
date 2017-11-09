#include "LDLL.h"

template <class T>
void LDLL<T> :: insertAtHead( const T value )
{
	if ( head == 0 )
	{
		head = new DNode<T> (value);
		return;
	}
	
	DNode<T> *temp = new DNode<T> (value);

	temp->next = head;
	head->prev = temp;
	head = temp;
}
template <class T>
void LDLL<T> :: insertAtTail( const T value )
{
	
	if ( head == 0 )
	{
		head = new DNode<T> (value);
		return;
	}

	DNode<T> *p = head;

	while ( p->next )
	{
			p = p->next;
	}

	DNode<T> *temp = new DNode<T> (value);
	temp->next = 0;
	temp->prev = p;
	p->next = temp;
}
template <class T>
void LDLL<T> :: insertBefore( const T key, const T value )
{
	if ( head == 0 )
		throw ListIsEmpty("list empty");

	DNode<T> *p = head;

	while( p != NULL && p->info != key)
	{
		p = p->next;
	}

	if ( p == head )
	{
		insertAtHead(value); 
		return;
	}

	if ( p == 0 )
	{
		throw ValueNotFound("no match found");
		return;
	}
		
	DNode<T> *x = new DNode<T> (value );

	p->prev->next = x;
	x->prev = p->prev;
	p->prev = x;
	x->next = p;
}
template <class T>
void LDLL<T> :: insertAfter ( const T key, const T value )
{
	if ( head == 0 )
		throw ListIsEmpty("List empty");

		DNode<T> *p = head;

		while ( p != NULL && p->info != key )
		{
			p = p -> next;
		}

		if ( p == 0 )
		{
			throw ValueNotFound("No match found");
		}
		
		DNode<T> *x = new DNode<T> ( value );

		x->next = p->next;
		x->prev = p;
		x->next->prev = x;
		x->prev->next = x;
}
template <class T>
void LDLL<T> :: deleteBefore( const T key )
{
	if ( head == 0 )
		throw ListIsEmpty("No match found");

	DNode<T> *p = head;

	while( p && p->info != key )
	{
		p = p->next;		
	}

	if ( head->next == p )
	{
		deleteAtHead();
		return;
	}

	if ( p == 0 )
		throw ValueNotFound("value not found");

	DNode<T> *temp = p->next;

	p->prev->prev->next = p;
	p->prev = p->prev->prev;

	delete temp;	
}
template <class T>
void LDLL<T> :: deleteAfter ( const T key )
{
	if ( head == 0 )
		throw ListIsEmpty("No match found");

	DNode<T> *p = head;

	while ( p && p->info != key )
	{
		p = p->next;
	}

	if ( p == 0 )
		throw ValueNotFound("No match found");

	if (  !p->next )
		return;

	else if ( !p->next->next )
	{
		DNode<T> *temp = p->next;
		p->next = NULL;
				
		delete temp;
	}
	else if ( p->next->next )
	{
		DNode<T> *temp = p->next;

		p->next->next->prev = p;
		p->next = p->next->next;

		delete temp;
	}
}
template <class T>
void LDLL<T> :: deleteAtHead()
{
	if ( head )
	{
		DNode<T> *p = head;

		head = head->next;
		
		if ( head )
			head->prev = 0;

		delete p;
	}
	else
		throw ListIsEmpty(" in deleteAtHead :: try to delete an alement at Head but list is empty \n ");



}
template <class T>
void LDLL<T> :: deleteAtTail()
{
	if ( head )
	{
		DNode<T> *p = head;
	
		while ( p->next )
		{
			p = p->next;
		}
		
		if ( p == head )
			deleteAtHead();
	
		else
		{
			p->prev->next = NULL;
		
			delete p;
		}
	}
	else
		throw ListIsEmpty(" in deleteAtTail :: try to delete an alement at tail but list is empty \n ");

}
template <class T>
void LDLL<T> :: delete_( const T key )
{
	if ( head )
	{
	
		DNode<T> *p = head;
	
		while( p != NULL && p->info != key )
		{
			p = p->next;
		}

		if ( p )
		{
			if ( head == p )
				deleteAtHead();

			else if ( p->next == NULL )
			{
				p->prev->next = p->next;

				delete p;
			}
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;

				delete p;
				
			}
		}
		else
			throw ValueNotFound(" in delete_ :: try to delete value but value not found \n");
	}
	else
		throw ListIsEmpty(" in delete_ :: try to delete an alement but list is empty \n ");

}

template <class T>
LDLL<T> :: ~LDLL()
{
	while( head )
		deleteAtHead();

}
