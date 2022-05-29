#pragma once
#include "Room.h"

class Flat
{
private:
	int count_room;
	Room* list_room;
	Wallpaper* list_wallpaper;
	int quantity_wallpaper;
	double surfaceWallpaper(double width, double length);
	double surfaceRoom(double width, double length, double height, bool gluing_the_ceiling);
	void quantityWallpaper(double widthWallpaper, double lengthWallpaper, double widthRoom, double lengthRoom, double heightRoom, bool gluing_the_ceiling);
public:
	Flat();
	Flat(int count_room);
	void fill();	
	void fillWallpapers();
	
	void print();

};

