#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "InvalidHeight.h"
#include "TreeEmpty.h"
#include "NoMatchFound.h"
#include "NoSpaceForChild.h"

template < class T >
class ArrayBT
{
	private:

		int height;
		T * data;
		char * status;

		int findTreePosition ( T key ) const;
		void erase ( int i ) ;

	public:

		ArrayBT ( int h );
		void setRightChild ( T key , T val );

		void setLeftChild ( T key , T val );
		void deleteNode ( T key );

		T getLeftChild ( T key ) const;
		T getRightChild ( T key ) const;

		void setRoot ( T val );
		bool isEmpty ( ) const;

		void preOrderTraversal ( int i ) const;
		void inOrderTraversal ( int i ) const;

		void postOrderTraversal ( int i ) const;
		void displayIteratively ( ifstream & inFile ) ;

		void display ( ifstream & inFile , int count );
};