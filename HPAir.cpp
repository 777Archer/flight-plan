/*David Archer
Flight Plan*/

#include <iostream>
#include "FlightMap.h"

using namespace std;

int main() 
{
	Map<string> aMap;

	aMap.readFlights();
	aMap.verifyRequestedFile();
} 