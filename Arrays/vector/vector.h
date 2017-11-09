#include <iostream.h>

template < typename T >
class Vector
{
	private:

		T ** list;
		int capacity;

		void resize ( );
		bool isValidIndex ( int );

	public:

		Vector ( );
		~Vector ( );

		void push ( T * );
		int getCapacity ( );

		void clear ( );

		T * operator [ ] ( int index );
		const T * operator [ ] ( int ) const;
};

template < typename T >
T * Vector<T>::operator [] ( int index )
{
	if ( isValidIndex ( index ) )
		return list[index];
	else
		return NULL;
}

template < typename T >
const T * Vector<T>::operator [] ( int index ) const
{
	if ( isValidIndex ( index ) )
		return list[index];
}

template < typename T >
Vector<T>::Vector ( )
{
	list = 0;
	capacity = 0;
}

template < typename T >
bool Vector<T>::isValidIndex ( int index )
{
	if ( index < 0 || index >= capacity )
		return false;

	return true;
}

template < typename T >
Vector<T>::~Vector ( )
{
	if ( list )
	{
		for ( int i = 0 ; i < capacity ; i++ )
			delete list[i];

		delete [ ] list;
		list = 0;
	}
}

template < typename T >
void Vector<T>::clear ( )
{
	for ( int i = 0 ; i < capacity ; i++ )
		delete list[i];

	delete [] list;
	list = 0;
	capacity = 0;
}

template < typename T >
void Vector<T>::push ( T * ptr )
{
	resize ( );
	list[ capacity ] = ptr;
	capacity ++;
}

template < typename T >
int Vector<T>::getCapacity ( )
{
	return capacity;
}

template < typename T >
void Vector<T>::resize ( )
{
	if ( list == 0)
	{
		list = new T * [1];
		return;
	}

	T ** newList = new T*[capacity + 1];

	for ( int i = 0 ; i < capacity ; i++ )
		newList[i] = list[i];

	delete [ ] list;

	list = newList;
}
