#include "Schedular.h"

Schedular::Schedular ( Process * arr , int length , int time )
{
	if ( length <= 0 )
		throw InvalidLength ( "Invalid Length" );

	processArrayLength = length;
	timeQuantum = time;

	processArray = new Process[processArrayLength];

	for ( int i = 0 ; i < processArrayLength; i++ )
		processArray[i] = arr[i];
}

void Schedular::assignProcess ( )
{
	Queue<Process> q;

	for ( int i = 0 ; i < processArrayLength ; i++ )
		q.enQueue ( processArray[i] );

	while ( !q.isEmpty ( ) )
	{
		Process p = q.deQueue ( );

		p.processExeTime -= timeQuantum;

		if ( p.processExeTime <= 0 )
			cout << p.processName << ".exe, " << p.processId << " completed execution " << endl;
		else
			q.enQueue ( p );
	}
}