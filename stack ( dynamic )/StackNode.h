template < class T >
class StackNode
{
	public:

		StackNode * next;
		T value;

	public:

		StackNode ( T v , StackNode * ptr ) : value ( v ) , next ( ptr )
		{}

		StackNode ( )
		{
			next = 0;
		}

};