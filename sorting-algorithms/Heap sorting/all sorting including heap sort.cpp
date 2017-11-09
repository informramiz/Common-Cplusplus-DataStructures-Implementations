#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void heapify ( int * data , int parent , int n )
{
	int leftChild = 2 * parent + 1;
	int rightChild = 2 * parent + 2;

	if( !( ( leftChild < n && data[leftChild] > data[parent] ) || ( rightChild < n && data[rightChild] > data[parent] ) ) )
		return;

	if ( leftChild < n && rightChild < n )
	{
		if ( data[leftChild] > data[rightChild] )
			swap ( data[parent] , data[leftChild] );
		else
			swap ( data[parent] , data[rightChild] );
	}
	else
		swap ( data[parent] , data[leftChild] );
}

int deleteFirst ( int * data , int noOfElements )
{
	int dataOfFirst = data[0];

	data[0] = data[noOfElements];

	int parent = 0;
	int leftChild = 2 * parent + 1;
	
	int rightChild = 2 * parent + 2;

	while ( parent < noOfElements && ( ( leftChild < noOfElements &&  data[leftChild] > data[parent] )
		|| ( data[rightChild] > data[parent] ) ) )
	{
		heapify ( data , parent , noOfElements );

		if ( leftChild < noOfElements  && rightChild < noOfElements )
			parent = data[leftChild] > data[rightChild] ? leftChild : rightChild;
		else 
			parent = leftChild;

		leftChild = 2 * parent + 1;
		rightChild = 2 * parent + 2;
	}

	return dataOfFirst;
}

void heapSort ( int * data , int n )
{
	for ( int i = ( n / 2 ) - 1 ; i>= 0 ; i-- )
		heapify ( data , i , n );

	for ( i = n - 1 ; i >= 0 ; i-- )			
		data[i] = deleteFirst ( data , i );
}

void main ( )
{

	const int n = 5;
	int a[n] = { 5 , 4 , 0 , 2 , 1 };
	
	heapSort ( a , n );

	for ( int i = 0 ; i < n ; i++ )
		cout << a[i] << ' ';
}