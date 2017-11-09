#ifndef STACK_H
#define STACK_H

#include <iostream.h>


class Stack
{
	private:

		struct StackNode
		{
			StackNode * next;
			void * data;

			StackNode ( void * value , StackNode * ptr )
				:data ( value ) , next ( ptr )
			{
			
			}
		};

		StackNode * top;

		Stack ( const Stack & )
		{}

		Stack & operator = ( const Stack & )
		{}

		protected:

			Stack ( );

			void push ( void * );
			void * pop ( ) ;

			bool empty ( ) const;

			~Stack ( );
};

#endif