#include "Stack.cpp"

template class Stack <int>;
void main ( )
{
	Stack<int> a;

	a.push ( 4 );
	a.push ( 6 );

	cout << a.stackTop ( ) << endl;
	cout << a.stackTop ( ) << endl;
}