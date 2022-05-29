#include "Wallpaper.h"

Wallpaper::Wallpaper()
{
	name = "def";
	price = 1000;
	width = 1;
	length = 10;
}

Wallpaper::Wallpaper(string name, int price, double width, double length)
{
	this->name = name;
	this->price = price;
	this->width = width;
	this->length = length;
}

string Wallpaper::getNaming()
{
	return name;
}

int Wallpaper::getPrices()
{
	return price;
}

double Wallpaper::getWidth()
{
	return width;
}

double Wallpaper::getLenght()
{
	return length;
}

void Wallpaper::setName(string name)
{
	if (name != "") {
		this->name = name;
	}
}

void Wallpaper::setPrice(int price)
{
	bool flag = true;
	while (flag) {
		if (price != 0) {
			this->price = price;
			flag = false;
		}
		else {
			cout << "÷ена не может быть равна 0, попробуйте еще раз: ";
			cin >> price;
		}
	}
}

void Wallpaper::setWidth(double width)
{
	bool flag = true;
	while (flag) {
		if (width != 0) {
			this->width = width;
			flag = false;
		}
		else {
			cout << "Ўирина не может быть равна 0, попробуйте еще раз: ";
			cin >> width;
		}
	}
}

void Wallpaper::setLength(double length)
{
	bool flag = true;
	while (flag) {
		if (length != 0) {
			this->length = length;
			flag = false;
		}
		else {
			cout << "Ўирина не может быть равна 0, попробуйте еще раз: ";
			cin >> length;
		}
	}
}
