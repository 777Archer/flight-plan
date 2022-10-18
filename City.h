/*David Archer
Flight Plan*/

#ifndef CITY
#define CITY

#include <iostream>
#include <string>

using namespace std;

template<class ItemType>
class City 
{
public:
	string originCity;
	string destinationCity;
	City<ItemType>* headPtr;
	City();
	City(string origin, string destination);
	City(const City<ItemType>& aCity);
	void setOriginCity(string aCityOrigin);
	void setDestinationCity(string aCityDestination);
	string getOriginCity();
	string getDestinationCity();
	void displayOriginCity();
};
#endif
template<class ItemType>
City<ItemType>::City() 
{
	originCity = " ";
	destinationCity = " ";
	headPtr = 0;
}
template<class ItemType>
City<ItemType>::City(string origin, string destination) 
{
	originCity = origin;
	destinationCity = destination;
}
template<class ItemType>
City<ItemType>::City(const City<ItemType>& aCity) 
{
	this->originCity = aCity.originCity;
	this->destinationCity = aCity.destinationCity;
	this->headPtr = aCity.headPtr;
}
template<class ItemType>
void City<ItemType>::setOriginCity(string aCityOrigin) 
{
	this->originCity = aCityOrigin;
}
template<class ItemType>
void City<ItemType>::setDestinationCity(string aCityDestination) 
{
	this->destinationCity = aCityDestination;
}
template<class ItemType>
void City<ItemType>::displayOriginCity() 
{
	cout << this->originCity << endl;
}
template<class ItemType>
string City<ItemType>::getOriginCity() 
{
	return (this->originCity);
}
template<class ItemType>
string City<ItemType>::getDestinationCity() 
{
	return(this->destinationCity);
}
