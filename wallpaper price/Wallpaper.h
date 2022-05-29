#pragma once
#include <string>
#include <iostream>
using namespace std;

class Wallpaper
{
private:
	string name;
	int price;
	double width;
	double length;

public:
	Wallpaper();
	Wallpaper(string name, int price, double width, double length);
	string getNaming();
	int getPrices();
	double getWidth();
	double getLenght();
	void setName(string name);
	void setPrice(int price);
	void setWidth(double width);
	void setLength(double length);
};

