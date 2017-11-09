#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;

#include "NoMatchFound.h"
#include "TreeEmpty.h"
#include "NoChildExist.h"
#include "FileNotOpened.h"

template < class T >
struct Node
{
	T info;
	
	Node * left;
	Node * right;

	Node ( )
	{
		left = right = 0;
	}

	Node ( T val ) : info ( val )
	{
		left = right = 0;
	}
};

template < class T >
struct Back
{
	Node<T> * ptr ;
	int f;

	Back ( )
	{
		ptr = 0;
		f = 0;
	}

	Back ( Node<T> * p , int flag = 0 )
	{
		ptr = p;
		f = flag;
	}
};

template < class T >
class BinaryTree
{
	private:

		Node<T> * root;

		Node<T> * search ( T key , Node<T> * root ) const;
		Node<T> * searchParent ( T key , Node<T> * root ) const;

		void erase ( Node<T> * ptr );

		void preOrder ( Node<T> * ptr ) const;
		void inOrder ( Node<T> * ptr ) const;

		void postOrder ( Node<T> * ptr ) const;
		void writeToFile ( ofstream & outFile , Node<T> * ptr ) const;

		Node<T> * copy ( Node<T> * root ) const;

		int displayDscendents ( T key , Node<T> * root  ) const;

		int heightOfTree ( Node<T> * root ) const;
		int noOfNodes ( Node<T> * root ) const;

		int isEqual ( Node<T> * root1 , Node<T> * root2 ) const;

		void displayParenthesizeView ( Node<T> * root ) const;
		Node<T> * readFile ( ifstream & inFile ) ;

		int levelOfNode ( Node<T> * p , T key , int count ) const;
		int printAncestors ( Node<T> * root , T key , queue<T> & q ) const;

		T minValue ( Node<T> * p ) const;
		T maxValue ( Node<T> * p ) const;

		int countLeafNodes ( Node<T> * root ) const;
		int isFull ( Node<T> * root ) const;

		int isComplete ( Node<T> * p ) const;

	public:
		
		BinaryTree ( );
		BinaryTree ( const BinaryTree & bt );

		const BinaryTree & operator = ( const BinaryTree & bt );

		int operator == ( const BinaryTree & bt ) const;

		void setRoot ( T info );

		void setLeftChild ( T key , T info );
		T getLeftChild ( T key ) const;
		
		void setRightChild ( T key , T info );
		T getRightChild ( T key  ) const;

		void deleteNode ( T key  );
		bool isEmpty ( ) const;

		void preOrder ( ) const;
		void inOrder ( ) const;

		void postOrder ( ) const;

		void writeToFile ( ofstream & outFile ) const;
		void readFromFile ( ifstream & inFile ) ;

		int isInternalNode ( T key ) const;
		int isExternalNode ( T key ) const;

		T findSiblingNode ( T key ) const;

		void levelOrder ( ) const;
		void displayDscendents ( T key ) const;

		int heightOfTree ( ) const;
		int noOfNodes ( ) const;

		BinaryTree mirrorImage ( ) const;
		void displayParenthesizeView ( ) const;

		void displayIndentedViewFromFile ( ifstream & inFile ) const;
		//void displayIndentedTree ( ) const;

		int levelOfNode ( T key ) const;
		void printAncestors ( T key ) const;

		T minValue ( ) const;
		T maxValue ( ) const;
		
		int countLeafNodes ( ) const;
		void nonRecPreOrder ( ) const;

		void nonRecInOrder ( ) const;
		void nonRecPostOrder ( ) const;

		int isFull ( ) const;
		int isComplete ( ) const;
};


