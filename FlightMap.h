/*David Archer
Flight Plan*/

#include <iostream>
#include "LinkedStack.h"
#include "City.h"
#include <fstream>
#include <vector>

using namespace std;

template <class ItemType>
class Map
{
private:

    vector<City<ItemType>> cityVector;
    LinkedStack<City<ItemType>> stackCity;
    City<ItemType> aDummyCity;

public:

    void readFlights();
    void addToHead(City<ItemType>& anOriginCity, City<ItemType>& aDestinationCity);
    void verifyRequestedFile();
    bool isPath(City<ItemType>& flightCity, City<ItemType>& requestedCity);
};

template<class ItemType>
bool Map<ItemType>::isPath(City<ItemType>& flightCity, City<ItemType>& requestedCity) 
{
    bool result, done;

    City<ItemType>* requestedPtr = new City<ItemType>(requestedCity);

    for (City<ItemType>* tempPtr = flightCity.headPtr; tempPtr != 0; tempPtr = tempPtr->headPtr) 
    {
        if (tempPtr->destinationCity == requestedPtr->destinationCity) 
        {
            done = true;
            return done;
        }
    }
    done = false;
    return done;
}

template<class ItemType>
void Map<ItemType>::verifyRequestedFile() 
{
    fstream requestedRoutes;
    string originCity, destinationCity;
    bool doesNotMatch;
    bool correctPath;

    requestedRoutes.open("requestFile.txt", ios::in);
    char test;
    if (requestedRoutes.is_open())
    {
        while (!requestedRoutes.eof()) 
        {
            getline(requestedRoutes, originCity, ',');

            requestedRoutes.get(test);
            while (requestedRoutes.peek() == '\t') 
            {
                requestedRoutes.get(test);
            }

            getline(requestedRoutes, destinationCity, '\n');

            doesNotMatch = false;
            for (int i = 0; i < cityVector.size(); ++i)
            {
                if (cityVector[i].getOriginCity() == originCity)
                {
                    doesNotMatch = true;

                    aDummyCity.setOriginCity(originCity);
                    aDummyCity.setDestinationCity(destinationCity);

                    correctPath = isPath(cityVector[i], aDummyCity);
                    if (correctPath)
                        cout << "HPAir flies from " << originCity << " to " << destinationCity << endl;
                    else
                        cout << "Sorry. HPAir does not fly from " << originCity << " to " << destinationCity << endl;
                }
            }
            while (!doesNotMatch)
                cout << "Sorry. HPAir does not serve " << originCity << endl;
        }
    }

}

template<class ItemType>
void Map<ItemType>::addToHead(City<ItemType>& anOriginCity, City<ItemType>& aDestinationCity) 
{
    City<ItemType>* newOne = new City<ItemType>(aDestinationCity);
    City<ItemType>* newSecond = new City<ItemType>(anOriginCity);

    if (anOriginCity.headPtr == 0) 
    {
        anOriginCity.headPtr = newOne;
    }

    else 
    {

        newOne->headPtr = anOriginCity.headPtr;
        anOriginCity.headPtr = newOne;
    }
}


template<class ItemType>
void Map<ItemType>::readFlights() 
{
    fstream readCities, readFlights;
    City<ItemType> aCity;
    string originCity, destinationCity;
    char test;

    readCities.open("cityFile.txt", ios::in);

    if (readCities.is_open())
        while (!readCities.eof())
            while (getline(readCities, originCity)) 
            {
                aCity.setOriginCity(originCity);
                cityVector.push_back(aCity);
            }
    for (int i = 0; i < cityVector.size(); i++)

        readCities.close();

    readFlights.open("flightFile.txt", ios::in);
    if (readFlights.is_open()) 
    {
        while (!readFlights.eof()) 
        {
            getline(readFlights, originCity, ',');

            readFlights.get(test);
            while (readFlights.peek() == '\t') 
            {
                readFlights.get(test);
            }

            getline(readFlights, destinationCity, '\n');

            for (int i = 0; i < cityVector.size(); ++i)
            {

                if (cityVector[i].getOriginCity() == originCity)
                {
                    aDummyCity.setOriginCity(originCity);
                    aDummyCity.setDestinationCity(destinationCity);

                    addToHead(cityVector[i], aDummyCity);
                    stackCity.push(aDummyCity);
                }
            }
        }

    }
    readFlights.close();
}