#include "Stack.h"

template < typename T >

class GenericStack : private Stack
{
	public:

		void push ( T * );
		T * pop ( );

		bool empty ( ) const;
};

template < typename T >
void  GenericStack<T>::push ( T * newData )
{
	Stack::push ( newData );
}

template < typename T >
T * GenericStack<T>::pop ( ) 
{
	return ( T * )Stack::pop ( );
}

template < typename T >
bool GenericStack<T>::empty ( ) const
{
	return Stack::empty ( );
}