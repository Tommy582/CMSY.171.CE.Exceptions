// Program written by Tommy Trinh
// April 9, 2024
// This program shows a number of different operator overloads
// and shows planets and their moons
#include <iostream>
#include <iomanip>
#include <string>
#include "Planet.h"
using namespace std;

// define function prototypes
void header();

// function template
template <class T>
void decideRadius(Planet planet8, bool useRadius, T &returnvalue)
{
	if (useRadius)
		returnvalue = planet8.getRadius();
	else
		returnvalue = static_cast<double>(planet8.getRadius()) / R_EARTH;
	return;
}

int main()
{
	// call header
	header();

	Planet planet1(5);
	Planet planet2, planet3, planet4, planet5, planet6;

	cout << "Using cout and the standard streaming operator:\n";
	cout << "Planet name: " << planet1.getName() << endl
		<< "Planet number: " << planet1.getNumPlanet() << endl
		<< "Planet Moons: " << planet1.getNumMoons() << endl
		<< "The radius of the planet is: " << planet1.getRadius()
		<< " miles.\n\n";
	cout << "Using cout and the overloaded streaming operator:\n";
	cout << planet1;

	// use prefix operator
	planet2 = ++planet1;
	cout << "Using the prefix operator for planet 1 and planet 2:\n"
		<< planet1 << planet2;

	// use postfix operator
	planet3 = planet1++;
	cout << "Using the postfix operator for planet 1 and planet 3:\n"
		<< planet1 << planet3;

	// use input stream
	cout << "Using the overloaded input streaming operator for planet 4:\n";
	cin >> planet4;
	cout << planet4;

	// use overloaded -
	cout << "Using the overloaded '-' operator for planet 5:\n";
	planet5 = -planet1;
	cout << planet5;

	// use overloaded +
	cout << "Using the overloaded '+' operator for planet 6:\n";
	planet6 = +planet6;
	cout << planet6;

	// ask user for planet object 7 info, with a try catch for high and low 
	// planet numbers, use a sentinel controlled do while loop
	bool tryAgain = true;
	int input;
	do
	{
		try
		{	// ask user for planet number
			cout << "Using the try-catch to input number of planet 7:\n"
				<< "Enter the number of a planet (1 - 8): ";
			cin >> input;
			Planet planet7(input);	// call class constructor
			cout << planet7;		// display planet data
			tryAgain = false;		// end loop
		}
		catch (Planet::PlanetNumberLow)
		{	// if planet number is too low, display error
			cout << "Error - the value entered is too small. Please try again!\n\n";
		}
		catch (Planet::PlanetNumberHigh)
		{	// if planet number is too high, display error
			cout << "Error - the value entered is too large. Please try again!\n\n";
		}
	} while (tryAgain);

	// instantiate planet 8 and display name, number, and moons
	Planet planet8(6);
	cout << "Using cout and the standard streaming operator and the template: \n"
		<< "The planet name is: " << planet8.getName() << endl
		<< "The planet number is: " << planet8.getNumPlanet() << endl
		<< "The planet has " << planet8.getNumMoons() << " moons.\n";
	// display the radius in miles using template call
	// create temporary bool to decide what radius to use
	bool stdRadius = true;
	int planet8Radius;
	double planet8equiv; 
	decideRadius(planet8, stdRadius, planet8Radius);
	cout << "The radius of the planet is: " << planet8Radius << " miles.\n";
	// set up equivalents
	cout << fixed << setprecision(2) << showpoint;
	stdRadius = false;
	decideRadius(planet8, stdRadius, planet8equiv);
	cout << "The size is equal to " << planet8equiv << " times the radius of Earth!\n\n";



	//goodbye message
	cout << "Thank you for using the program!\n\n";

	// end of main
	system("pause");
	return 0;
}

// display program info to user
void header()
{
	cout << "\t\t\t\t\tCMSY 171 CE-Exception and Template\n"
		<< "Copyright 2024 - Howard Community College All rights reserved; "
		<< "Unauthorized duplication prohibited.\n\n"
		<< "\t\t\tWelcome to CMSY-171 Planet Operations Program\n\n";
}