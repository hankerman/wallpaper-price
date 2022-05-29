#include "Room.h"

Room::Room()
{
	name = "unknown";
	width = 10;
	length = 10;
	height = 2,5;
	gluing_the_ceiling = false;
}

Room::Room(string name, double width, double length, double height, bool gluing_the_ceiling)
{
	this->name = name;
	this->width = width;
	this->length = length;
	this->height = height;
	this->gluing_the_ceiling = gluing_the_ceiling;
}

void Room::setName(string name)
{
	if (name != "") {
		this->name = name;
	}
}

void Room::setWidth(double width)
{
	bool flag = true;
	while (flag) {
		if (width != 0) {
			this->width = width;
			flag = false;
		}
		else {
			cout << "Ширина не может быть равна 0, попробуйте еще раз: ";
			cin >> width;
		}
	}
}

void Room::setLength(double length)
{
	bool flag = true;
	while (flag) {
		if (length != 0) {
			this->length = length;
			flag = false;
		}
		else {
			cout << "Длина не может быть равна 0, попробуйте еще раз: ";
			cin >> length;
		}
	}
}

void Room::setHeight(double height)
{
	bool flag = true;
	while (flag) {
		if (height != 0) {
			this->height = height;
			flag = false;
		}
		else {
			cout << "Высота не может быть равна 0, попробуйте еще раз: ";
			cin >> height;
		}
	}
}

void Room::setGluingTheCeiling(bool flag)
{
	gluing_the_ceiling = flag;
}

string Room::getNaming()
{
	return name;
}

double Room::getWidth()
{
	return width;
}

double Room::getLenght()
{
	return length;
}

double Room::getHeight()
{
	return height;
}

bool Room::getGluingTheCeiling()
{
	return gluing_the_ceiling;
}
