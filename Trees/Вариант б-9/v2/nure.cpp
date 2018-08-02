#include "tree_static.hpp"

#include <iostream>

void PrintNodeLabel ( const Tree & _t, int _nodeIndex )
{
	int temp = _nodeIndex;
	while ( temp != 0 )
	{
		temp = TreeGetParentIndex( _t, temp );
		std::cout << "    ";
	}

	std::cout << TreeGetLabel(_t, _nodeIndex) << std::endl;
}

int main()
{
	const int sizeNure = 44;
	Tree* pT = TreeCreate( sizeNure );
	
	TreeSetLabel( *pT, 0, "Nure" );

	TreeSetLabel( *pT, 1, "AKT" );
	TreeSetLabel( *pT, 2, "ET" );
	TreeSetLabel( *pT, 3, "KIY" );
	TreeSetLabel( *pT, 4, "KN" );
	TreeSetLabel( *pT, 5, "PMM" );
	TreeSetLabel( *pT, 6, "RT" );
	TreeSetLabel( *pT, 7, "TKVT" );
	TreeSetLabel( *pT, 8, "PHIG" );

	TreeSetLabel( *pT, 9, "AKIT" );
	TreeSetLabel( *pT, 10, "REA" );
	TreeSetLabel( *pT, 11, "CI" );

	TreeSetLabel( *pT, 12, "BMI" );
	TreeSetLabel( *pT, 13, "EPC" );
	TreeSetLabel( *pT, 14, "MN" );
	TreeSetLabel( *pT, 15, "OT" );

	TreeSetLabel( *pT, 16, "BIKC" );
	TreeSetLabel( *pT, 17, "KI" );

	TreeSetLabel( *pT, 18, "VPC" );
	TreeSetLabel( *pT, 19, "KN" );
	TreeSetLabel( *pT, 20, "PI" );

	TreeSetLabel( *pT, 21, "EK" );
	TreeSetLabel( *pT, 22, "INP" );
	TreeSetLabel( *pT, 23, "PM" );
	TreeSetLabel( *pT, 24, "CA" );

	TreeSetLabel( *pT, 25, "AT" );
	TreeSetLabel( *pT, 26, "RT" );
	TreeSetLabel( *pT, 27, "CTZI" );

	TreeSetLabel( *pT, 28, "MIBT" );
	TreeSetLabel( *pT, 29, "MCC" );
	TreeSetLabel( *pT, 30, "TK" );
	TreeSetLabel( *pT, 31, "YIB" );

	TreeSetLabel( *pT, 32, "AKITi" );
	TreeSetLabel( *pT, 33, "BIKCi" );
	TreeSetLabel( *pT, 34, "BMIi" );
	TreeSetLabel( *pT, 35, "BPCi" );
	TreeSetLabel( *pT, 36, "EKi" );
	TreeSetLabel( *pT, 37, "EPCi" );
	TreeSetLabel( *pT, 38, "KIi" );
	TreeSetLabel( *pT, 39, "KNi" );
	TreeSetLabel( *pT, 40, "MCCi" );
	TreeSetLabel( *pT, 41, "PIi" );
	TreeSetLabel( *pT, 42, "REAi" );
	TreeSetLabel( *pT, 43, "TKi" );


	TreeSetParentIndex( * pT, 1, 0 );
	TreeSetParentIndex( * pT, 2, 0 );
	TreeSetParentIndex( * pT, 3, 0 );
	TreeSetParentIndex( * pT, 4, 0 );
	TreeSetParentIndex( * pT, 5, 0 );
	TreeSetParentIndex( * pT, 6, 0 );
	TreeSetParentIndex( * pT, 7, 0 );
	TreeSetParentIndex( * pT, 8, 0 );

	TreeSetParentIndex( * pT, 9,  1 );
	TreeSetParentIndex( * pT, 10, 1 );
	TreeSetParentIndex( * pT, 11, 1 );


	TreeSetParentIndex( * pT, 12, 2 );
	TreeSetParentIndex( * pT, 13, 2 );
	TreeSetParentIndex( * pT, 14, 2 );
	TreeSetParentIndex( * pT, 15, 2 );

	TreeSetParentIndex( * pT, 16, 3 );
	TreeSetParentIndex( * pT, 17, 3 );

	TreeSetParentIndex( * pT, 18, 4 );
	TreeSetParentIndex( * pT, 19, 4 );
	TreeSetParentIndex( * pT, 20, 4 );

	TreeSetParentIndex( * pT, 21, 5 );
	TreeSetParentIndex( * pT, 22, 5 );
	TreeSetParentIndex( * pT, 23, 5 );
	TreeSetParentIndex( * pT, 24, 5 );

	TreeSetParentIndex( * pT, 25, 6 );
	TreeSetParentIndex( * pT, 26, 6 );
	TreeSetParentIndex( * pT, 27, 6 );

	TreeSetParentIndex( * pT, 28, 7 );
	TreeSetParentIndex( * pT, 29, 7 );
	TreeSetParentIndex( * pT, 30, 7 );
	TreeSetParentIndex( * pT, 31, 7 );

	TreeSetParentIndex( * pT, 32, 8 );
	TreeSetParentIndex( * pT, 33, 8 );
	TreeSetParentIndex( * pT, 34, 8 );
	TreeSetParentIndex( * pT, 35, 8 );
	TreeSetParentIndex( * pT, 36, 8 );
	TreeSetParentIndex( * pT, 37, 8 );
	TreeSetParentIndex( * pT, 38, 8 );
	TreeSetParentIndex( * pT, 39, 8 );
	TreeSetParentIndex( * pT, 40, 8 );
	TreeSetParentIndex( * pT, 41, 8 );
	TreeSetParentIndex( * pT, 42, 8 );
	TreeSetParentIndex( * pT, 43, 8 );
	
	TreeDirectWalk( *pT, PrintNodeLabel);
	
	TreeDestroy( pT );
	return 0;
}