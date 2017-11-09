# include <iostream>
# include "Excaption.h"

using namespace std;

class ValueNotFound : public Excaption
{

public:
	ValueNotFound( const char* ptr ) : Excaption(ptr)
	{}

};

class ListIsEmpty : public Excaption
{

public:
	ListIsEmpty( const char* ptr ) : Excaption(ptr)
	{}

};

template <class T>
class DNode
{

public:

	T info;
	DNode<T> *next;
	DNode<T> *prev;

	DNode()
	{
		next = prev = NULL;
	}
	DNode( T value)
	{
		info = value;
		next = prev = 0;
	}
};

template <class T>
class CSLL
{

	DNode<T> *head;

public:
	CSLL()
	{
		head = NULL;
	}

	~CSLL();

	void insertAtHead( const T );
	void insertAtTail( const T );
	void insertBefore( const T, const T );
	void insertAfter ( const T, const T );
	void deleteBefore( const T );
	void deleteAfter ( const T );	
	void deleteAtHead();
	void deleteAtTail();
	void delete_( const T );

	void l()
	{
		DNode<T> *p = head;

		while( p )
		{
			cout<<p->info<<endl;

			p = p->next;

		}
	}

};

void main()
{

	CSLL<int> obj;

	obj.insertAtHead(4);
	obj.insertAtHead(3);
	obj.insertAtHead(2);
	obj.insertAtHead(1);
	
	obj.l();

}

template <class T>
void CSLL<T> :: insertAtHead( const T value )
{
	if ( head )
	{
		DNode<T> *temp = new DNode<T> (value);

		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
		head = new DNode<T> (value);

}
template <class T>
void CSLL<T> :: insertAtTail( const T value )
{
	
	if ( head )
	{
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
	else
		head = new DNode<T> (value);

}
template <class T>
void CSLL<T> :: insertBefore( const T key, const T value )
{
	if ( head )
	{
		DNode<T> *p = head;

		while( p != NULL && p->info != key)
		{
			p = p->next;
		}

		if ( p == head )
		{
			insertAtHead(value); 
		}
		else if ( p )
		{
			DNode<T> *x = new DNode<T> (value );

			p->prev->next = x;
			x->prev = p->prev;
			p->prev = x;
			x->next = p;
					
		}	
		else
			throw ValueNotFound(" in delete_ :: try to delete value but value not found \n");
	}
	else
		throw ListIsEmpty(" in delete_ :: try to delete an alement but list is empty \n ");


}
template <class T>
void CSLL<T> :: insertAfter ( const T key, const T value )
{
	if ( head )
	{
		DNode<T> *p = head;

		while ( p != NULL && p->info != key )
		{
			p = p -> next;
		}

		if ( p )
		{
			DNode<T> *x = new DNode<T> ( value );

			x->next = p->next;
			x->prev = p;
			x->next->prev = x;
			x->prev->next = x;
		
		}
		else
			throw ValueNotFound(" in delete_ :: try to delete value but value not found \n");
	}
	else
		throw ListIsEmpty(" in delete_ :: try to delete an alement but list is empty \n ");


}
template <class T>
void CSLL<T> :: deleteBefore( const T key )
{
	if ( head )
	{
		DNode<T> *p = head;

		while( p && p->info != key )
		{
			p = p->next;		
		}

		if ( head->next == p )
			deleteAtHead();

		else if ( p )
		{
			DNode<T> *temp = p->next;

			p->prev->prev->next = p;
			p->prev = p->prev->prev;

			delete temp;
		
		}		
		else
			throw ValueNotFound(" in delete_ :: try to delete value but value not found \n");
	}
	else
		throw ListIsEmpty(" in delete_ :: try to delete an alement but list is empty \n ");

}
template <class T>
void CSLL<T> :: deleteAfter ( const T key )
{
	if ( head )
	{
		DNode<T> *p = head;

		while ( p && p->info != key )
		{
			p = p->next;
		}

		if ( p )
		{
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
		else
			throw ValueNotFound(" in delete_ :: try to delete value but value not found \n");
	}
	else
		throw ListIsEmpty(" in delete_ :: try to delete an alement but list is empty \n ");

}
template <class T>
void CSLL<T> :: deleteAtHead()
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
void CSLL<T> :: deleteAtTail()
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
void CSLL<T> :: delete_( const T key )
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
CSLL<T> :: ~CSLL()
{
	while( head )
		deleteAtHead();

}
