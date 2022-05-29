#pragma once
#include "Wallpaper.h"
#include <iostream>
using namespace std;

class Room
{
private:
	string name;
	double width;
	double length;
	double height;
	bool gluing_the_ceiling;

public:
	Room();
	Room(string name, double width, double length, double height, bool gluing_the_ceiling);
	void setName(string name);
	void setWidth(double width);
	void setLength(double length);
	void setHeight(double height);
	void setGluingTheCeiling(bool flag);
	string getNaming();	
	double getWidth();
	double getLenght();
	double getHeight();
	bool getGluingTheCeiling();


};

