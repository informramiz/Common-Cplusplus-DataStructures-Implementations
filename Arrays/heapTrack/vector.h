#include <iostream.h>

template < typename T >
class Vector
{
	private:

		T * list;
		int capacity;

		void resize ( );
		bool isValidIndex ( int ) const;

		void shiftElements ( int ) ;

	public:

		Vector ( );
		~Vector ( );

		void push ( const T & );
		int getCapacity ( ) const;

		void clear ( );

		T & operator [ ] ( int index );
		T  operator [ ] ( int ) const;

		void remove ( T  ptr ) ;
		int find ( T  ptr ) const;
};

template < class T >
int Vector<T>::find ( T  ptr ) const
{
	for ( int i = 0 ; i < getCapacity ( ) ; i++ )
		if ( ptr == list[i] )
			return i;
	return -1;
}

template < class T >
void Vector<T>::shiftElements ( int value ) 
{
	for ( int i = value ; i < getCapacity ( ) - 1 ; i++ )
		list[i] = list [ i + 1 ];
}

template < class T >
void Vector<T>::remove ( T  ptr )
{
	int index = find ( ptr );

	if ( index != -1 )
	{
		shiftElements ( index );
		capacity --;
	};
}

template < typename T >
T & Vector<T>::operator [] ( int index )
{
	if ( isValidIndex ( index ) )
		return list[index];
	else
		cout << "index : " << index << "out of range" << endl;
}

template < typename T >
T  Vector<T>::operator [] ( int index ) const
{
	if ( isValidIndex ( index ) )
		return list[index];
	else
		cout << "index : " << index << "out of range" << endl;
}

template < typename T >
Vector<T>::Vector ( )
{
	list = 0;
	capacity = 0;
}

template < typename T >
bool Vector<T>::isValidIndex ( int index ) const
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
		delete [ ] list;
		list = 0;
	}
}

template < typename T >
void Vector<T>::clear ( )
{
	delete [] list;
	list = 0;
	capacity = 0;
}

template < typename T >
void Vector<T>::push ( const T & ptr )
{
	resize ( );
	list[ capacity ] = ptr;
	capacity ++;
}

template < typename T >
int Vector<T>::getCapacity ( ) const
{
	return capacity;
}

template < typename T >
void Vector<T>::resize ( )
{
	if ( list == 0)
	{
		list = new T [1];
		return;
	}

	T * newList = new T[capacity + 1];

	for ( int i = 0 ; i < capacity ; i++ )
		newList[i] = list[i];

	delete [ ] list;

	list = newList;
}
