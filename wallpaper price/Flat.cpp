#include "Flat.h"

double Flat::surfaceWallpaper(double width, double length)
{
	double res = width * length;
	
	return res;
}

double Flat::surfaceRoom(double width, double length, double height, bool gluing_the_ceiling)
{
	double res;

	if (gluing_the_ceiling) {
		res = 2 * (width * height) + 2 * (length * height) + (width * length);
	}
	else {
		res = 2 * (width * height) + 2 * (length * height);
	}

	return res;
}

void Flat::quantityWallpaper(double widthWallpaper, double lengthWallpaper, double widthRoom, double lengthRoom, double heightRoom, bool gluing_the_ceiling)
{
	int count_wallpaper = 1;
	double wallpapers, rooms = surfaceRoom(widthRoom, lengthRoom, heightRoom, gluing_the_ceiling);
	bool flag = true;

	do {

		wallpapers = surfaceWallpaper(widthWallpaper, lengthWallpaper) * count_wallpaper;
		if (wallpapers >= rooms) {
			quantity_wallpaper = count_wallpaper;
			flag = false;
		}
		else {
			count_wallpaper++;
		}

	} while (flag);
}

Flat::Flat()
{
	this->count_room = 1;
	list_room = new Room[count_room];
	list_wallpaper = new Wallpaper[count_room];
	this->quantity_wallpaper = 10;
}

Flat::Flat(int count_room)
{
	this->count_room = count_room;
	list_room = new Room[count_room];
	list_wallpaper = new Wallpaper[count_room];
	this->quantity_wallpaper = 10;
}

void Flat::fill()
{
	string temp;
	double tempp;
	
	for (int i = 0; i < count_room; i++) {
		temp = "";
		cout << "Введите название комнаты:" << endl;
		if (temp == "") {
			cin >> temp;
		}
		list_room[i].setName(temp);
		cout << "Введите размеры комнаты" << endl;
		cout << "Ширина: ";
		cin >> tempp;
		list_room[i].setWidth(tempp);
		cout << "Длина: ";
		cin >> tempp;
		list_room[i].setLength(tempp);
		cout << "Высота: ";
		cin >> tempp;
		list_room[i].setHeight(tempp);
		cout << "На потолке обои клеем?" << endl;
		cout << "Если да - yes, если нет - no" << endl;		
		temp = "";
		cin >> temp;
		if (temp == "") {
			cin >> temp;
		}
		if (temp == "yes") {
			list_room[i].setGluingTheCeiling(true);
		}
		else {
			list_room[i].setGluingTheCeiling(false);
		}
		cout << endl << endl;
	}
}

void Flat::fillWallpapers()
{
	string temp;
	double tempp;
	int tem;

	for (int i = 0; i < count_room; i++) {
		cout << "Введите название обоев для комнаты: " << list_room[i].getNaming() << endl;
		cin >> temp;
		list_wallpaper[i].setName(temp);
		cout << "Введите размеры обоев:" << endl;
		cout << "Ширина: ";
		cin >> tempp;
		list_wallpaper[i].setWidth(tempp);
		cout << "Длина: ";
		cin >> tempp;
		list_wallpaper[i].setLength(tempp);
		cout << "Введите цену обоев за рулон: ";
		cin >> tem;
		list_wallpaper[i].setPrice(tem);
		cout << endl << endl;
	}


}

void Flat::print()
{
	int count_price = 0;
	cout << "В квартире есть комнаты:" << endl;
	for (int i = 0; i < count_room; i++) {
		cout << "Комната " << i << " " << list_room[i].getNaming() << endl;
		cout << "Ее параметры: " << endl;
		cout << "Ширина - " << list_room[i].getWidth() << "m" << ", Длина - " << list_room[i].getLenght() << "m" << ", Высота - " << list_room[i].getHeight() << "m" << endl;
		if (list_room[i].getGluingTheCeiling()) {
			cout << "Обои на потолке клеить" << endl;
		}
		else {
			cout << "Обои на потолке не клеить" << endl;
		}
		cout << "Обои в этой комнате: " << list_wallpaper[i].getNaming() << endl;
		cout << "Размерами: Ширина - " << list_wallpaper[i].getWidth() << "m" << ", Длиной - " << list_wallpaper[i].getLenght() << "m" << endl;
		cout << "Ценой за рулон - " << list_wallpaper[i].getPrices() << " рублей" << endl;
		quantityWallpaper(list_wallpaper[i].getWidth(), list_wallpaper[i].getLenght(), list_room[i].getWidth(), list_room[i].getLenght(), list_room[i].getHeight(), list_room[i].getGluingTheCeiling());
		cout << "Для поклейки этой комнаты нужно - " << quantity_wallpaper + 1 << " рулонов обоев" << endl;
		cout << "Цена на все обои на комнату - " << (quantity_wallpaper + 1) * list_wallpaper[i].getPrices() << " рублей" << endl;
		count_price = count_price + ((quantity_wallpaper + 1) * list_wallpaper[i].getPrices());
		cout << endl;
	}

	cout << "Всего: " << count_price;
}
