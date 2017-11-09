#include "Schedular.h"

void main ( )
{
	Process arr[4] = { Process ( 1 , "notepade" , 20 ) , Process ( 13 , "mp3Player" , 5 ),
		Process ( 4 , "bcc" , 30 ) , Process ( 11 , "explorer" , 2 ) };

	Schedular s ( arr , 4 , 10 );
	s.assignProcess ( );
}