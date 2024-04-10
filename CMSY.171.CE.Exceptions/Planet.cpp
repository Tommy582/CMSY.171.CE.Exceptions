#include <iostream>
#include <string>
#include "Planet.h"
using namespace std;

Planet::Planet()		// default constructor
{
	name = "none";
	setNumPlanet();
	setNumMoons(getNumPlanet());
	setRadius(getNumPlanet());
}

Planet::Planet(int i)	// constructor with name parameter
{
	if (i < MERCURY)
		throw PlanetNumberLow();
	if (i > NEPTUNE)
		throw PlanetNumberHigh();
	numPlanet = i;
	setName(getNumPlanet());
	setNumMoons(getNumPlanet());
	setRadius(getNumPlanet());
}

void Planet::setNumPlanet()			// sets the planet number based on planet name
{
	if (name == "Mercury")
		numPlanet = MERCURY;
	else if (name == "Venus")
		numPlanet = VENUS;
	else if (name == "Earth")
		numPlanet = EARTH;
	else if (name == "Mars")
		numPlanet = MARS;
	else if (name == "Jupiter")
		numPlanet = JUPITER;
	else if (name == "Saturn")
		numPlanet = SATURN;
	else if (name == "Uranus")
		numPlanet = URANUS;
	else if (name == "Neptune")
		numPlanet = NEPTUNE;
	else
		numPlanet = 0;
}

void Planet::setNumMoons(int numPlanet)	// sets  number of moons based on planet number
{
	if (numPlanet == MERCURY)
		numMoons = MERCURY_MOONS;
	else if (numPlanet == VENUS)
		numMoons = VENUS_MOONS;
	else if (numPlanet == EARTH)
		numMoons = EARTH_MOONS;
	else if (numPlanet == MARS)
		numMoons = MARS_MOONS;
	else if (numPlanet == JUPITER)
		numMoons = JUPITER_MOONS;
	else if (numPlanet == SATURN)
		numMoons = SATURN_MOONS;
	else if (numPlanet == URANUS)
		numMoons = URANUS_MOONS;
	else if (numPlanet == NEPTUNE)
		numMoons = NEPTUNE_MOONS;
	else
		numMoons = 0;
}

void Planet::setName(int numPlanet)		// set sthe planet name based on planet number
{
	if (numPlanet == MERCURY)
		name = "Mercury";
	else if (numPlanet == VENUS)
		name = "Venus";
	else if (numPlanet == EARTH)
		name = "Earth";
	else if (numPlanet == MARS)
		name = "Mars";
	else if (numPlanet == JUPITER)
		name = "Jupiter";
	else if (numPlanet == SATURN)
		name = "Saturn";
	else if (numPlanet == URANUS)
		name = "Uranus";
	else if (numPlanet == NEPTUNE)
		name = "Neptune";
	else
		name = "none";
}

void Planet::setRadius(int numPlanet)
{
	if (numPlanet == MERCURY)
		radius = R_MERCURY;
	else if (numPlanet == VENUS)
		radius = R_VENUS;
	else if (numPlanet == EARTH)
		radius = R_EARTH;
	else if (numPlanet == MARS)
		radius = R_MARS;
	else if (numPlanet == JUPITER)
		radius = R_JUPITER;
	else if (numPlanet == SATURN)
		radius = R_SATURN;
	else if (numPlanet == URANUS)
		radius = R_URANUS;
	else if (numPlanet == NEPTUNE)
		radius = R_NEPTUNE;
}

string Planet::getName() const	// returns name
{
	return name;
}

int Planet::getNumPlanet()const	// returns planet number
{
	return numPlanet;
}

int Planet::getNumMoons()const	// returns planet moons
{
	return numMoons;
}

int Planet::getRadius()const	// returns planet radius
{
	return radius;
}

ostream& operator<<(ostream& out, Planet& s) // cout overload
{
	out << "The planet " << s.name << " is planet number: " << s.numPlanet << endl
		<< "It has " << s.numMoons << " moons and a radius of " 
		<< s.radius << " miles.\n\n";
	return out;
}
istream& operator>>(istream& in, Planet& s) // input overload
{// gets name from user and sets planet and moon number from name
	cout << "Enter the name of a Planet: ";
	in >> s.name;
	s.setNumPlanet();
	s.setNumMoons(s.numPlanet);
	s.setRadius(s.numPlanet);
	return in;
}

Planet Planet::operator++() // prefix increment
{
	numPlanet++;
	if (numPlanet > NEPTUNE)//if numPlanet>8, reset to 1
		numPlanet = MERCURY;
	setName(numPlanet);
	setNumMoons(numPlanet);
	setRadius(numPlanet);
	return *this;
}

Planet Planet::operator++(int)// postfix increment
{
	Planet temp(numPlanet);
	numPlanet++;
	if (numPlanet > NEPTUNE)//if numPlanet>8, reset to 1
		numPlanet = MERCURY;
	setName(numPlanet);
	setNumMoons(numPlanet);
	setRadius(numPlanet);
	return temp;
}

Planet Planet::operator=(Planet s)// copy an object
{
	name = s.getName();
	numPlanet = s.getNumPlanet();
	numMoons = s.getNumMoons();
	radius = s.getRadius();
	return s;
}

Planet Planet::operator-()
{
	numPlanet = MERCURY;
	setNumMoons(numPlanet);
	setName(numPlanet);
	setRadius(numPlanet);
	return *this;
}

Planet Planet::operator+()
{
	numPlanet = NEPTUNE;
	setNumMoons(numPlanet);
	setName(numPlanet);
	setRadius(numPlanet);
	return*this;
}