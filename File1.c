#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//
typedef  void (*RT)( int input );
typedef  RT (*TER)( int input );

// Forward declarations
extern TER state1( int input );
extern TER state2( int input );
extern TER state3( int input );

// First state
TER state1( int input )
{
    printf( "one\t" );
    return input < 10 ? (TER)&state2 : (TER)NULL;
}

// Second state
TER state2( int input )
{
	printf( "two\t" );
	return (TER)&state3;
}

// Third state
TER state3( int input )
{
    printf( "three\t" );
    return (TER)&state1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int n;

    // Set Start state
    TER state = (TER)&state1;

    // Exercises the state machine. Ends when state == NULL
    for ( n = 0 ; state ; ++n ) {
        // Executes the current state (state variable) then goes to the next state
        state = (TER)( state( n ) );
    }

    printf( "\n\nPress any key\n" );
    getch();

	return 0;
}
