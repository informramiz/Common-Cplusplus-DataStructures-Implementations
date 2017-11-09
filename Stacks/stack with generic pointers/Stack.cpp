#include "stack.h"

Stack::Stack ( )
{
	top = 0;
}

Stack::~Stack ( )
{
	while ( top )
	{
		StackNode * toDie = top;
		top = top->next ;

		delete toDie->data ;
		delete toDie;
	}

	top = 0;
}

void Stack::push ( void * newPtr )
{
	top = new StackNode ( newPtr , top );
}

void * Stack::pop ( )
{
	StackNode * stackTop = top;
	top = top->next ;

	void * data = stackTop->data ;

	delete stackTop->data ;
	delete stackTop;

	return data;
}

bool Stack::empty ( ) const
{
	return top == 0;
}

